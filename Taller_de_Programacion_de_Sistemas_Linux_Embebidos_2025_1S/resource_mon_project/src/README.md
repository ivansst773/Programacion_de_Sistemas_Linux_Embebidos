# Módulos del proyecto - `src`

## Descripción
Esta carpeta contiene la implementación de los módulos principales del programa `resource_mon`. Cada módulo se encarga de manejar una parte específica del sistema:

### **1. `cpuinfo_manip.h` y `cpuinfo_manip.c`**
- **Propósito:** Obtener información sobre el procesador.
- **Funciones principales:**
  - `get_cpu_info()`: Recupera el nombre y fabricante de la CPU desde `/proc/cpuinfo`.
  - `get_cpu_usage()`: Calcula el porcentaje de uso de cada hilo desde `/proc/stat`.

### **2. `meminfo_manip.h` y `meminfo_manip.c`**
- **Propósito:** Obtener datos de la memoria RAM y swap.
- **Funciones principales:**
  - `get_memory_info()`: Recupera la cantidad total de memoria física y swap desde `/proc/meminfo`.
  - `get_memory_usage()`: Calcula el porcentaje de uso de la memoria RAM y swap.

### **3. `tui.h` y `tui.c`**
- **Propósito:** Manejar la interfaz de usuario en la terminal.
- **Funciones principales:**
  - `render_ui()`: Muestra la información en pantalla sin generar nuevas líneas.
  - `get_user_input()`: Detecta cuando el usuario presiona `q` para salir.

### **4. `resource_mon.c`**
- **Propósito:** Contiene el ciclo principal de ejecución del programa.
- **Flujo de ejecución:**
  - Recupera información de CPU y memoria.
  - Muestra los datos en pantalla utilizando `tui.c`.
  - Se actualiza cada segundo hasta que el usuario salga.

## **Uso del `Makefile` en `src`**
El `Makefile` permite compilar los módulos individualmente y generar archivos `.o`:
- `make` → Compila `cpuinfo_manip.c`, `meminfo_manip.c` y `resource_mon.c`.
- `make clean` → Borra los archivos `.o` generados.
