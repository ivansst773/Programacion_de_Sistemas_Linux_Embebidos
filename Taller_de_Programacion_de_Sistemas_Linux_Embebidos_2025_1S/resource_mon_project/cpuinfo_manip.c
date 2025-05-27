#include "cpuinfo_manip.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_cpu_info(char *model, char *vendor, int *cores, int *threads) {
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        perror("Error al abrir /proc/cpuinfo");
        return;
    }

    char line[256];
    *cores = 0;
    *threads = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "model name", 10) == 0 && model[0] == '\0') {
            sscanf(line, "model name\t: %[^\n]", model);
        }
        if (strncmp(line, "vendor_id", 9) == 0 && vendor[0] == '\0') {
            sscanf(line, "vendor_id\t: %[^\n]", vendor);
        }
        if (strncmp(line, "cpu cores", 9) == 0) {
            int c;
            sscanf(line, "cpu cores\t: %d", &c);
            if (c > *cores) *cores = c;
        }
        if (strncmp(line, "processor", 9) == 0) {
            (*threads)++;
        }
    }
    fclose(fp);
}

float get_cpu_usage(int cpu_id) {
    char buffer[256];
    char cpu_label[10];
    sprintf(cpu_label, "cpu%d", cpu_id);

    static unsigned long long last_total[64] = {0};
    static unsigned long long last_idle[64] = {0};

    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Error al abrir /proc/stat");
        return 0.0;
    }

    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, cpu_label, strlen(cpu_label)) == 0) {
            sscanf(buffer, "%*s %llu %llu %llu %llu %llu %llu %llu %llu",
                   &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            break;
        }
    }
    fclose(fp);

    unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    unsigned long long total_diff = total - last_total[cpu_id];
    unsigned long long idle_diff = idle - last_idle[cpu_id];

    last_total[cpu_id] = total;
    last_idle[cpu_id] = idle;

    if (total_diff == 0) return 0.0;
    return (float)(total_diff - idle_diff) * 100.0 / total_diff;
}
