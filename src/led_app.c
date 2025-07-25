#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1')) {
        printf("Uso: %s [1|0]\n", argv[0]);
        return 1;
    }

    int fd = open("/dev/leddev", O_WRONLY);
    if (fd < 0) {
        perror("No se pudo abrir /dev/leddev");
        return 1;
    }

    write(fd, argv[1], 1);
    close(fd);
    return 0;
}

