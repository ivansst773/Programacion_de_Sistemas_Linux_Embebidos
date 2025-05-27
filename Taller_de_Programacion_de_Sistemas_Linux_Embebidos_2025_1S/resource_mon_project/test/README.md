# test/

Contiene los tests de validación de los módulos:

- `cpuinfo_test.c`: prueba las funciones de CPU.
- `meminfo_test.c`: prueba las funciones de memoria.
- `tui_test.c`: prueba las funciones de la interfaz TUI.

## Ejecución de los tests
Compilar:
```bash
make tests

Ejecutar:

bash 
./bin/cpuinfo_test
./bin/meminfo_test
./bin/tui_test

Valores esperados
Los tests imprimen la información que extraen de los módulos.

El test de tui espera que se presione una tecla.



# Pruebas del proyecto - `test`

## Descripción
Esta carpeta contiene las pruebas unitarias para verificar el correcto funcionamiento de los módulos del proyecto.

### **1. `cpuinfo_test.c`**
- **Propósito:** Verificar la correcta lectura de información de la CPU.
- **Test implementado:** 
  - Se ejecuta `get_cpu_info()`, y se compara el nombre y fabricante de la CPU con el valor esperado.
  - Se ejecuta `get_cpu_usage()`, verificando que el porcentaje de uso de la CPU sea un valor válido.

### **2. `meminfo_test.c`**
- **Propósito:** Validar el correcto manejo de la memoria.
- **Test implementado:**
  - Se ejecuta `get_memory_info()`, verificando que los valores de memoria sean mayores a cero.
  - Se ejecuta `get_memory_usage()`, verificando que el porcentaje de uso sea válido.

### **3. `tui_test.c`**
- **Propósito:** Probar la interfaz de usuario.
- **Test implementado:**
  - Se ejecuta `render_ui()` para comprobar que los datos se muestren en pantalla correctamente.
  - Se prueba `get_user_input()` para asegurarse de que el programa detecte la tecla `q` correctamente.

## **Uso del `Makefile` en `test`**
El `Makefile` permite compilar y ejecutar las pruebas unitarias:
- `make` → Compila los archivos de prueba.
- `make clean` → Borra los archivos `.o` y ejecutables generados.
- `make tests` → Ejecuta todas las pruebas unitarias.
