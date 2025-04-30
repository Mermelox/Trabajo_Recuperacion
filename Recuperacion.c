#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define MAX_NOMBRE 30

// Función para validar la entrada de puntos
int validarEntrada(char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] < '0' || entrada[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Función para validar nombres
int validarNombre(char *nombre) {
    if (strlen(nombre) == 0) {
        return 0;
    }
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z'))) {
            return 0;
        }
    }
    return 1;
}

// Función para verificar si un nombre ya fue ingresado
int nombreRepetido(char nombres[][MAX_NOMBRE], int cantidad, char *nuevo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nuevo) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int puntos[NUM_BOXEADORES];
    char entrada[10];
    char nombres[NUM_BOXEADORES][MAX_NOMBRE];

    // Ingreso de nombres de los boxeadores
    printf("Ingrese los nombres de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        printf("Boxeador %d: ", i + 1);
        scanf("%s", nombres[i]);

        // Validar nombre y que no esté repetido
        while (!validarNombre(nombres[i]) || nombreRepetido(nombres, i, nombres[i])) {
            if (!validarNombre(nombres[i])) {
                printf("Nombre inválido. Ingrese un nombre válido: ");
            } else {
                printf("Nombre repetido. Ingrese un nombre único: ");
            }
            scanf("%s", nombres[i]);
        }
    }

    // Ingreso de puntos de los boxeadores
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

    // Primera ronda: 3 combates
    int ganadores_primera[3];
    for (int i = 0; i < 3; i++) {
        int a = i * 2;
        int b = a + 1;
        ganadores_primera[i] = (puntos[a] > puntos[b]) ? a : b;
    }

    // Semifinal y final
    int semifinalista1 = ganadores_primera[0];
    int semifinalista2 = ganadores_primera[1];
    int ganador_semifinal = (puntos[semifinalista1] > puntos[semifinalista2]) ? semifinalista1 : semifinalista2;
    int finalista = ganadores_primera[2];

    int campeon = (puntos[ganador_semifinal] > puntos[finalista]) ? ganador_semifinal : finalista;
    int subcampeon = (campeon == ganador_semifinal) ? finalista : ganador_semifinal;
    int semifinalista = (semifinalista1 == ganador_semifinal) ? semifinalista2 : semifinalista1;

    // Mostrar resultados
    printf("\nResultados del torneo:\n");
    printf("Campeón: %s con %d puntos\n", nombres[campeon], puntos[campeon]);
    printf("Finalista: %s con %d puntos\n", nombres[subcampeon], puntos[subcampeon]);
    printf("Semifinalista: %s con %d puntos\n", nombres[semifinalista], puntos[semifinalista]);

    return 0;
}
