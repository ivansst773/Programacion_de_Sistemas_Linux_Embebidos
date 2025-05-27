#include "../src/cpuinfo_manip.h"
#include <stdio.h>

int main() {
    char model[128] = {0};
    char vendor[128] = {0};
    int cores, threads;

    get_cpu_info(model, vendor, &cores, &threads);

    printf("Modelo: %s\n", model);
    printf("Fabricante: %s\n", vendor);
    printf("Núcleos: %d\n", cores);
    printf("Hilos: %d\n", threads);

    for (int i = 0; i < threads; i++) {
        printf("Uso hilo %d: %.2f%%\n", i, get_cpu_usage(i));
    }

    return 0;
}
