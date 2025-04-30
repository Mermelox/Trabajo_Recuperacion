#include <stdio.h>
#include <stdlib.h>

int main() {
    // Nombres de los boxeadores
    char nombre1[30], nombre2[30], nombre3[30], nombre4[30], nombre5[30], nombre6[30];
    // Puntos de los boxeadores
    int puntos1, puntos2, puntos3, puntos4, puntos5, puntos6;
    char entrada[10];

    // Ingreso de nombres
    printf("Ingrese los nombres de los boxeadores:\n");

    // Validar nombres uno por uno
    do {
        printf("Boxeador 1: ");
        scanf("%s", nombre1);
        int i = 0;
        while (nombre1[i] != '\0') {
            if (!((nombre1[i] >= 'A' && nombre1[i] <= 'Z') || (nombre1[i] >= 'a' && nombre1[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre1[0] == '\0');  // Asegurarse de que no quede vacío

    do {
        printf("Boxeador 2: ");
        scanf("%s", nombre2);
        int i = 0;
        while (nombre2[i] != '\0') {
            if (!((nombre2[i] >= 'A' && nombre2[i] <= 'Z') || (nombre2[i] >= 'a' && nombre2[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre2[0] == '\0' || strcmp(nombre2, nombre1) == 0); // Evitar repetidos

    do {
        printf("Boxeador 3: ");
        scanf("%s", nombre3);
        int i = 0;
        while (nombre3[i] != '\0') {
            if (!((nombre3[i] >= 'A' && nombre3[i] <= 'Z') || (nombre3[i] >= 'a' && nombre3[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre3[0] == '\0' || strcmp(nombre3, nombre1) == 0 || strcmp(nombre3, nombre2) == 0);

    do {
        printf("Boxeador 4: ");
        scanf("%s", nombre4);
        int i = 0;
        while (nombre4[i] != '\0') {
            if (!((nombre4[i] >= 'A' && nombre4[i] <= 'Z') || (nombre4[i] >= 'a' && nombre4[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre4[0] == '\0' || strcmp(nombre4, nombre1) == 0 || strcmp(nombre4, nombre2) == 0 || strcmp(nombre4, nombre3) == 0);

    do {
        printf("Boxeador 5: ");
        scanf("%s", nombre5);
        int i = 0;
        while (nombre5[i] != '\0') {
            if (!((nombre5[i] >= 'A' && nombre5[i] <= 'Z') || (nombre5[i] >= 'a' && nombre5[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre5[0] == '\0' || strcmp(nombre5, nombre1) == 0 || strcmp(nombre5, nombre2) == 0 || strcmp(nombre5, nombre3) == 0 || strcmp(nombre5, nombre4) == 0);

    do {
        printf("Boxeador 6: ");
        scanf("%s", nombre6);
        int i = 0;
        while (nombre6[i] != '\0') {
            if (!((nombre6[i] >= 'A' && nombre6[i] <= 'Z') || (nombre6[i] >= 'a' && nombre6[i] <= 'z'))) {
                printf("Nombre inválido. Solo se permiten letras.\n");
                break;
            }
            i++;
        }
    } while (nombre6[0] == '\0' || strcmp(nombre6, nombre1) == 0 || strcmp(nombre6, nombre2) == 0 || strcmp(nombre6, nombre3) == 0 || strcmp(nombre6, nombre4) == 0 || strcmp(nombre6, nombre5) == 0);

    // Ingreso de puntos
    printf("\nIngrese los puntos de los boxeadores:\n");

    do {
        printf("%s: ", nombre1);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos1 = atoi(entrada);

    do {
        printf("%s: ", nombre2);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos2 = atoi(entrada);

    do {
        printf("%s: ", nombre3);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos3 = atoi(entrada);

    do {
        printf("%s: ", nombre4);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos4 = atoi(entrada);

    do {
        printf("%s: ", nombre5);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos5 = atoi(entrada);

    do {
        printf("%s: ", nombre6);
        scanf("%s", entrada);
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                printf("Entrada inválida. Ingrese un número entero positivo: ");
                break;
            }
            i++;
        }
    } while (entrada[0] == '\0');
    puntos6 = atoi(entrada);

    // Lógica para determinar los ganadores y el torneo
    int g1 = (puntos1 > puntos2) ? 1 : 2;
    int g2 = (puntos3 > puntos4) ? 3 : 4;
    int g3 = (puntos5 > puntos6) ? 5 : 6;

    // Semifinal
    int semi1 = g1, semi2 = g2;
    int ganador_semi = ( (semi1 == 1 ? puntos1 : puntos2) > (semi2 == 3 ? puntos3 : puntos4) ) ? semi1 : semi2;

    // Final
    int finalista = g3;
    int puntos_finalista = (finalista == 5) ? puntos5 : puntos6;
    int puntos_ganador_semi;
    if (ganador_semi == 1) puntos_ganador_semi = puntos1;
    else if (ganador_semi == 2) puntos_ganador_semi = puntos2;
    else if (ganador_semi == 3) puntos_ganador_semi = puntos3;
    else puntos_ganador_semi = puntos4;

    int campeon, subcampeon, semifinalista;
    if (puntos_ganador_semi > puntos_finalista) {
        campeon = ganador_semi;
        subcampeon = finalista;
        semifinalista = (semi1 == ganador_semi) ? semi2 : semi1;
    } else {
        campeon = finalista;
        subcampeon = ganador_semi;
        semifinalista = (semi1 == ganador_semi) ? semi2 : semi1;
    }

    // Mostrar resultados
    printf("\nResultados del torneo:\n");

    char *nombres[] = { "", nombre1, nombre2, nombre3, nombre4, nombre5, nombre6 };
    int puntos[] = { 0, puntos1, puntos2, puntos3, puntos4, puntos5, puntos6 };

    printf("Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);
    printf("Semifinalista: %s con %d puntos\n", nombres[semifinalista], puntos[semifinalista]);

    return 0;
}



