#include "cpuinfo_manip.h"
#include "meminfo_manip.h"
#include "tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char model[128] = {0};
    char vendor[128] = {0};
    int cores, threads;

    while (1) {
        tui_clear();

        get_cpu_info(model, vendor, &cores, &threads);
        printf("CPU: %s\nFabricante: %s\nNúcleos: %d\nHilos: %d\n\n", model, vendor, cores, threads);

        for (int i = 0; i < threads; i++) {
            printf("Hilo %d: %.2f%%\n", i, get_cpu_usage(i));
        }

        unsigned long mem_total, mem_free, swap_total, swap_free;
        get_mem_info(&mem_total, &mem_free, &swap_total, &swap_free);

        printf("\nMemoria Total: %lu MB\n", mem_total / 1024);
        printf("Memoria Libre: %lu MB\n", mem_free / 1024);
        printf("Uso de Memoria: %.2f%%\n", 100.0 * (mem_total - mem_free) / mem_total);

        printf("\nSwap Total: %lu MB\n", swap_total / 1024);
        printf("Swap Libre: %lu MB\n", swap_free / 1024);
        printf("Uso de Swap: %.2f%%\n", swap_total ? (100.0 * (swap_total - swap_free) / swap_total) : 0.0);

        tui_pause();

        usleep(1000000); // 1 segundo

        if (tui_kbhit()) {
            if (tui_getch() == 'q')
                break;
        }
    }

    printf("\nSaliendo...\n");
    return 0;
}
