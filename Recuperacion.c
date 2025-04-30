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
        printf("Pelea %d: %s (%d) vs %s (%d) → Ganador: %s\n",
               i + 1, nombres[a], puntos[a], nombres[b], puntos[b], nombres[ganador]);
    }

    // Elegir los 2 ganadores con más puntos para la final
    int f1 = ganadores[0], f2 = ganadores[1], f3 = ganadores[2];

    // Ordenar los ganadores para encontrar los dos con más puntos
    int first, second;
    if (puntos[f1] >= puntos[f2] && puntos[f1] >= puntos[f3]) {
        first = f1;
        second = (puntos[f2] > puntos[f3]) ? f2 : f3;
    } else if (puntos[f2] >= puntos[f1] && puntos[f2] >= puntos[f3]) {
        first = f2;
        second = (puntos[f1] > puntos[f3]) ? f1 : f3;
    } else {
        first = f3;
        second = (puntos[f1] > puntos[f2]) ? f1 : f2;
    }

    printf("\n--- Final ---\n");
    printf("%s (%d) vs %s (%d)\n", nombres[first], puntos[first], nombres[second], puntos[second]);

    int campeon = (puntos[first] > puntos[second]) ? first : second;
    int subcampeon = (campeon == first) ? second : first;

    printf("\n=== Resultados del torneo ===\n");
    printf("🏆 Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("🥈 Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);

    return 0;
}


