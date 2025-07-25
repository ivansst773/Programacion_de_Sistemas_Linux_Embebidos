# Programacion_de_Sistemas_Linux_Embebidos

💡 LED GPIO Character Driver – LicheeRV / Raspberry Pi (Linux Kernel Module)

Este proyecto implementa un controlador de dispositivo de carácter para sistemas Linux embebidos (como LicheeRV o Raspberry Pi). Permite la interacción entre el espacio de usuario y un LED GPIO a través de llamadas estándar (open, write, read) usando un módulo del kernel.

📁 Estructura del Proyecto

led_driver_project/
├── src/
│   ├── led_driver.c      # Código fuente del módulo del kernel
│   └── led_app.c         # Aplicación en espacio de usuario para pruebas
├── Makefile              # Makefile principal para compilación
├── README.md             # Este documento
├── pruebas/              # Archivos de prueba y logs (opcional)

⚙️ Requisitos del Sistema

    Distribución Linux con soporte para carga de módulos (Ubuntu o derivado)

    Headers del kernel instalados:

sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)

🛠️ Compilación

Desde la raíz del proyecto:

bash
make 
Esto generará led_driver.ko para insertar en el kernel.

🚀 Uso

    Insertar el módulo:

sudo insmod led_driver.ko

verificar con dmesg:

dmesg | tail 
 
ejecutar la app de prueba 
./src/led_app

🧪 Pruebas

Se recomienda incluir en la carpeta pruebas/:

    Logs de dmesg

    Script de comandos usados (comandos.sh)

    Capturas de salida en consola

📌 Notas Adicionales

    Compatible con arquitecturas RISC-V y ARM

    Probado en LicheeRV, Raspberry Pi, y entorno VirtualBox (Ubuntu)

    Puede requerir permisos de root para algunas operaciones
