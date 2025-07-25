#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "leddev"
#define CLASS_NAME  "ledclass"
#define GPIO_LED    65  // GPIO correspondiente al LED en la LicheeRV

static int majorNumber;
static struct class*  ledClass  = NULL;
static struct device* ledDevice = NULL;

// Declaraciones de funciones
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);

static struct file_operations fops = {
    .open    = dev_open,
    .release = dev_release,
    .write   = dev_write,
    .read    = dev_read,
};

// Inicialización del módulo
static int __init led_init(void) {
    printk(KERN_INFO "LED Driver: Iniciando módulo...\n");

    majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
    if (majorNumber < 0) {
        printk(KERN_ALERT "LED Driver: Falló el registro del dispositivo\n");
        return majorNumber;
    }

    ledClass = class_create(CLASS_NAME);
    if (IS_ERR(ledClass)) {
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_ALERT "LED Driver: Falló al crear la clase\n");
        return PTR_ERR(ledClass);
    }

    ledDevice = device_create(ledClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
    if (IS_ERR(ledDevice)) {
        class_destroy(ledClass);
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_ALERT "LED Driver: Falló al crear el dispositivo\n");
        return PTR_ERR(ledDevice);
    }

    if (gpio_request(GPIO_LED, "LED") != 0) {
        device_destroy(ledClass, MKDEV(majorNumber, 0));
        class_destroy(ledClass);
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_ALERT "LED Driver: GPIO %d no disponible\n", GPIO_LED);
        return -1;
    }

    gpio_direction_output(GPIO_LED, 0);  // LED apagado al inicio
    printk(KERN_INFO "LED Driver: GPIO %d configurado como salida\n", GPIO_LED);

    printk(KERN_INFO "LED Driver: Módulo cargado con número mayor %d\n", majorNumber);
    return 0;
}

// Salida del módulo
static void __exit led_exit(void) {
    gpio_set_value(GPIO_LED, 0);  // Apagar LED antes de salir
    gpio_free(GPIO_LED);

    device_destroy(ledClass, MKDEV(majorNumber, 0));
    class_unregister(ledClass);
    class_destroy(ledClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);

    printk(KERN_INFO "LED Driver: Módulo descargado\n");
}

// Abrir dispositivo
static int dev_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "LED Driver: Dispositivo abierto\n");
    return 0;
}

// Cerrar dispositivo
static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "LED Driver: Dispositivo cerrado\n");
    return 0;
}

// Escribir en el dispositivo (encender/apagar LED)
static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    char command;

    if (copy_from_user(&command, buffer, 1) != 0)
        return -EFAULT;

    if (command == '1') {
        gpio_set_value(GPIO_LED, 1);
        printk(KERN_INFO "LED Driver: LED ENCENDIDO\n");
    } else if (command == '0') {
        gpio_set_value(GPIO_LED, 0);
        printk(KERN_INFO "LED Driver: LED APAGADO\n");
    } else {
        printk(KERN_WARNING "LED Driver: Comando inválido (%c)\n", command);
    }

    return len;
}

// Leer el estado actual del LED (1 encendido, 0 apagado)
static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    char state = gpio_get_value(GPIO_LED) ? '1' : '0';

    if (copy_to_user(buffer, &state, 1) != 0)
        return -EFAULT;

    printk(KERN_INFO "LED Driver: Estado leído (%c)\n", state);
    return 1;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("IAN & Copilot");
MODULE_DESCRIPTION("Driver de carácter para controlar LED vía GPIO 65");
MODULE_VERSION("1.1");

module_init(led_init);
module_exit(led_exit);
