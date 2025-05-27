#ifndef CPUINFO_MANIP_H
#define CPUINFO_MANIP_H

void get_cpu_info(char *model, char *vendor, int *cores, int *threads);
double get_cpu_usage(int cpu_id);

#endif
