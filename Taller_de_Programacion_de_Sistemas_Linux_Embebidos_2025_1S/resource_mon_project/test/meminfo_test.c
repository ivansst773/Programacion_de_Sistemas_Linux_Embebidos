#include "../src/meminfo_manip.h"
#include <stdio.h>

int main() {
    unsigned long mem_total, mem_free, swap_total, swap_free;

    get_mem_info(&mem_total, &mem_free, &swap_total, &swap_free);

    printf("Memoria total: %lu MB\n", mem_total / 1024);
    printf("Memoria libre: %lu MB\n", mem_free / 1024);
    printf("Uso de Memoria: %.2f%%\n", 100.0 * (mem_total - mem_free) / mem_total);

    printf("Swap total: %lu MB\n", swap_total / 1024);
    printf("Swap libre: %lu MB\n", swap_free / 1024);
    printf("Uso de Swap: %.2f%%\n", swap_total ? (100.0 * (swap_total - swap_free) / swap_total) : 0.0);

    return 0;
}
