#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define MAX_NOMBRE 30

int main() {
    int puntos[NUM_BOXEADORES];
    char nombres[NUM_BOXEADORES][MAX_NOMBRE];
    char entrada[10];

    // Ingreso de nombres de los boxeadores
    printf("Ingrese los nombres de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        int valido = 0;

        while (!valido) {
            printf("Boxeador %d: ", i + 1);
            scanf("%s", nombres[i]);

            valido = 1;
            for (int j = 0; nombres[i][j] != '\0'; j++) {
                if (!((nombres[i][j] >= 'A' && nombres[i][j] <= 'Z') || 
                      (nombres[i][j] >= 'a' && nombres[i][j] <= 'z'))) {
                    valido = 0;
                    break;
                }
            }

            if (strlen(nombres[i]) == 0) {
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
            for (int j = 0; entrada[j] != '\0'; j++) {
                if (entrada[j] < '0' || entrada[j] > '9') {
                    valido = 0;
                    break;
                }
            }

            if (strlen(entrada) == 0) {
                valido = 0;
            }

            if (!valido) {
                printf("Entrada inválida. Ingrese un número entero positivo.\n");
            }
        }

        puntos[i] = atoi(entrada);
    }

    // Primera ronda: 3 combates entre pares
    int ganador1 = (puntos[0] > puntos[1]) ? 0 : 1;
    int ganador2 = (puntos[2] > puntos[3]) ? 2 : 3;
    int ganador3 = (puntos[4] > puntos[5]) ? 4 : 5;

    // Segunda ronda: semifinal y final
    int semifinal = (puntos[ganador1] > puntos[ganador2]) ? ganador1 : ganador2;
    int finalista = ganador3;
    int campeon = (puntos[semifinal] > puntos[finalista]) ? semifinal : finalista;

    int subcampeon = (campeon == semifinal) ? finalista : semifinal;
    int semifinalista = (semifinal == ganador1) ? ganador2 : ganador1;

    // Resultados
    printf("\nResultados del torneo:\n");
    printf("Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);
    printf("Semifinalista: %s con %d puntos\n", nombres[semifinalista], puntos[semifinalista]);

    return 0;
}




