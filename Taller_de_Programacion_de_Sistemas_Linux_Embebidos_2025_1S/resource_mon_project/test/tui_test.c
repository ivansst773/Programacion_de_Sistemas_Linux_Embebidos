#include "../src/tui.h"
#include <stdio.h>

int main() {
    printf("Prueba de funciones TUI:\n");

    tui_clear();
    printf("Pantalla limpia.\n");

    printf("Presiona una tecla para continuar...\n");
    while (!tui_kbhit());

    printf("¡Tecla presionada!\n");

    return 0;
}
