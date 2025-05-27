# Proyecto `resource_mon`

**Integrantes:**
- Edgar Ivan Calpa Cuacialpud CC 1004577329
## Descripción

`resource_mon` es un programa en C que muestra información del sistema en tiempo real:

✅ CPU:  
- Modelo y fabricante.  
- Número de núcleos y hilos.  
- Porcentaje de uso de cada hilo.

✅ Memoria:  
- Memoria física total y libre.  
- Memoria swap total y libre.  
- Porcentaje de uso de ambas.

✅ Se actualiza cada segundo y finaliza con `q`, `Ctrl + C` o cerrando la terminal.

## Estructura del proyecto
bin/#Ejecutables
obj/#Archivos objeto
src/#Código fuente principal 
test/#Código de pruebas (tests)
Makefile# Construcción automatizada 
README.md#Documentación principal 

python 

## Uso 

Desde la raíz del proyecto:

Compilar tDesde la raíz del proyecto:

Compilar todo:
```bash
make all

Ejecutar el programa principal: 
bash 
./bin/resource_mon
Ejecutar tests

bash
make tests
./bin/cpuinfo_test
./bin/meminfo_test
./bin/tui_test

Limpiar archivos generados:
bash 
make clean

Repositorio 
El enlace al repositorio se entregará en classroom
