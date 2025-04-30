#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define MAX_NOMBRE 30

// Función para obtener el índice del ganador entre dos boxeadores
int obtenerGanador(int idx1, int idx2, int *puntos) {
    if (puntos[idx1] > puntos[idx2]) {
        return idx1;
    } else {
        return idx2;
    }
}

int main() {
    int puntos[NUM_BOXEADORES];
    char entrada[10];
    char nombres[NUM_BOXEADORES][MAX_NOMBRE];

    // Ingreso de nombres de los boxeadores
    printf("Ingrese los nombres de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        int valido = 0;

        while (!valido) {
            printf("Boxeador %d: ", i + 1);
            scanf("%s", nombres[i]);

            valido = 1;
            int j;
            for (j = 0; nombres[i][j] != '\0'; j++) {
                if (!((nombres[i][j] >= 'A' && nombres[i][j] <= 'Z') || (nombres[i][j] >= 'a' && nombres[i][j] <= 'z'))) {
                    valido = 0;
                    break;
                }
            }

            if (j == 0) {
                valido = 0;
            }

            if (!valido) {
                printf("Nombre inválido. Ingrese solo letras.\n");
            }
        }
    }

    // Ingreso de puntos de los boxeadores
    printf("\nIngrese los puntos de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        int valido = 0;

        while (!valido) {
            printf("%s: ", nombres[i]);
            scanf("%s", entrada);

            valido = 1;
            int j;
            for (j = 0; entrada[j] != '\0'; j++) {
                if (entrada[j] < '0' || entrada[j] > '9') {
                    valido = 0;
                    break;
                }
            }

            if (j == 0) {
                valido = 0;
            }

            if (!valido) {
                printf("Entrada inválida. Ingrese un número entero positivo.\n");
            }
        }

        puntos[i] = atoi(entrada);
    }

    // Primera ronda: 3 combates entre pares
    int ganadores[3];
    for (int i = 0; i < 3; i++) {
        int idx1 = i * 2;
        int idx2 = idx1 + 1;
        ganadores[i] = obtenerGanador(idx1, idx2, puntos);
    }

    // Segunda ronda: semifinal y final
    int semifinal = obtenerGanador(ganadores[0], ganadores[1], puntos);
    int finalista = ganadores[2];
    int campeon = obtenerGanador(semifinal, finalista, puntos);

    int subcampeon = (campeon == semifinal) ? finalista : semifinal;
    int semifinalista = (semifinal == ganadores[0]) ? ganadores[1] : ganadores[0];

    // Resultados
    printf("\nResultados del torneo:\n");
    printf("Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);
    printf("Semifinalista: %s con %d puntos\n", nombres[semifinalista], puntos[semifinalista]);

    return 0;
}




