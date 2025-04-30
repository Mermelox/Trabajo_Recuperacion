#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define MAX_NOMBRE 30

int validarEntrada(char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] < '0' || entrada[i] > '9') return 0;
    }
    return 1;
}

int validarNombre(char *nombre) {
    if (strlen(nombre) == 0) return 0;
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z'))) {
            return 0;
        }
    }
    return 1;
}

int nombreRepetido(char nombres[][MAX_NOMBRE], int cantidad, char *nuevo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nuevo) == 0) return 1;
    }
    return 0;
}

int main() {
    int puntos[NUM_BOXEADORES];
    char entrada[10];
    char nombres[NUM_BOXEADORES][MAX_NOMBRE];

    printf("Ingrese los nombres de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        printf("Boxeador %d: ", i + 1);
        scanf("%s", nombres[i]);
        while (!validarNombre(nombres[i]) || nombreRepetido(nombres, i, nombres[i])) {
            if (!validarNombre(nombres[i])) {
                printf("Nombre inválido. Ingrese un nombre válido: ");
            } else {
                printf("Nombre repetido. Ingrese un nombre único: ");
            }
            scanf("%s", nombres[i]);
        }
    }

    printf("\nIngrese los puntos de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        printf("%s: ", nombres[i]);
        scanf("%s", entrada);
        while (!validarEntrada(entrada)) {
            printf("Entrada inválida. Ingrese un número entero positivo: ");
            scanf("%s", entrada);
        }
        puntos[i] = atoi(entrada);
    }

    printf("\n--- Primera ronda ---\n");
    int ganadores[3];
    for (int i = 0; i < 3; i++) {
        int a = i * 2;
        int b = a + 1;
        int ganador = (puntos[a] > puntos[b]) ? a : b;
        ganadores[i] = ganador;
        printf("%s (%d) vs %s (%d) → Gana %s\n", nombres[a], puntos[a], nombres[b], puntos[b], nombres[ganador]);
    }

    printf("\n--- Segunda ronda ---\n");
    int semi1 = ganadores[0];
    int semi2 = ganadores[1];
    int finalista1 = (puntos[semi1] > puntos[semi2]) ? semi1 : semi2;
    int semifinalista = (semi1 == finalista1) ? semi2 : semi1;
    printf("%s (%d) vs %s (%d) → Gana %s\n", nombres[semi1], puntos[semi1], nombres[semi2], puntos[semi2], nombres[finalista1]);

    int finalista2 = ganadores[2];
    printf("%s (%d) espera para la final\n", nombres[finalista2], puntos[finalista2]);

    printf("\n--- Final ---\n");
    int campeon = (puntos[finalista1] > puntos[finalista2]) ? finalista1 : finalista2;
    int subcampeon = (campeon == finalista1) ? finalista2 : finalista1;
    printf("%s (%d) vs %s (%d) → Campeón: %s\n", nombres[finalista1], puntos[finalista1], nombres[finalista2], puntos[finalista2], nombres[campeon]);

    printf("\n=== Resultados del torneo ===\n");
    printf("🏆 Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("🥈 Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);
    printf("🥉 Semifinalista: %s con %d puntos\n", nombres[semifinalista], puntos[semifinalista]);

    return 0;
}


