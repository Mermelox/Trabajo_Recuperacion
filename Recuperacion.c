#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define MAX_NOMBRE 30

// Función para validar la entrada de puntos
int validarEntrada(char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] < '0' || entrada[i] > '9') {
            return 0; // Retorna 0 si hay un carácter no válido
        }
    }
    return 1; // Retorna 1 si la entrada es válida
}

// Función para validar nombres
int validarNombre(char *nombre) {
    if (strlen(nombre) == 0) {
        return 0; // Retorna 0 si el nombre está vacío
    }
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z'))) {
            return 0; // Retorna 0 si hay un carácter no válido
        }
    }
    return 1; // Retorna 1 si el nombre es válido
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
        
        // Validar el nombre
        while (!validarNombre(nombres[i])) {
            printf("Nombre inválido. Ingrese un nombre válido: ");
            scanf("%s", nombres[i]);
        }
    }

    // Ingreso de puntos de los boxeadores
    printf("\nIngrese los puntos de los boxeadores:\n");
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        printf("%s: ", nombres[i]);
        scanf("%s", entrada);
        
        // Validar la entrada
        while (!validarEntrada(entrada)) {
            printf("Entrada inválida. Ingrese un número entero positivo: ");
            scanf("%s", entrada);
        }
        
        // Convertir la entrada a entero usando strtol
        puntos[i] = (int)strtol(entrada, NULL, 10); // Convertir la entrada a entero
    }

    // Determinar los ganadores de cada combate
    int ganadores[NUM_BOXEADORES / 2];
    for (int i = 0; i < NUM_BOXEADORES / 2; i++) {
        if (puntos[i * 2] > puntos[i * 2 + 1]) {
            ganadores[i] = i * 2; // Ganador es el boxeador 1
        } else {
            ganadores[i] = i * 2 + 1; // Ganador es el boxeador 2
        }
    }

    // Determinar los finalistas
    int finalistas[2];
    if (puntos[ganadores[0]] > puntos[ganadores[1]]) {
        finalistas[0] = ganadores[0];
    } else {
        finalistas[0] = ganadores[1];
    }

    // Mostrar los resultados
    printf("\nFinalistas:\n");
    printf("%s con %d puntos\n", nombres[finalistas[0]], puntos[finalistas[0]]);
    
    return 0;
}