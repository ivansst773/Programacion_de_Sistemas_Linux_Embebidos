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
