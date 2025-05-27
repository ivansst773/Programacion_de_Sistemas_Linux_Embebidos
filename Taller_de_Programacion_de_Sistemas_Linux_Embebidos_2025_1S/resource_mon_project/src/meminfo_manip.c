#include "meminfo_manip.h"
#include <string.h>
#include <stdio.h>

void get_mem_info(unsigned long *mem_total, unsigned long *mem_free,
                   unsigned long *swap_total, unsigned long *swap_free) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Error al abrir /proc/meminfo");
        return;
    }

    char label[64];
    unsigned long value;
    char unit[16];

    while (fscanf(fp, "%63s %lu %15s\n", label, &value, unit) == 3) {
        if (strcmp(label, "MemTotal:") == 0)
            *mem_total = value;
        else if (strcmp(label, "MemAvailable:") == 0)
            *mem_free = value;
        else if (strcmp(label, "SwapTotal:") == 0)
            *swap_total = value;
        else if (strcmp(label, "SwapFree:") == 0)
            *swap_free = value;
    }

    fclose(fp);
}
