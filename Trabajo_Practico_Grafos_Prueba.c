#include <stdio.h>

#define NUM_EQUIPOS 20

// Estructura para representar un partido
typedef struct {
    int equipoLocal;
    int equipoVisitante;
    int distanciaRecorrida;
} Partido;

// Función para calcular la distancia recorrida en un partido
int calcularDistancia(int matrizAdyacencia[NUM_EQUIPOS][NUM_EQUIPOS], Partido partido) {
    return matrizAdyacencia[partido.equipoLocal][partido.equipoVisitante];
}

int main() {
    int matrizAdyacencia[NUM_EQUIPOS][NUM_EQUIPOS] = {
        // Aquí debes ingresar las distancias entre los equipos
        // La matriz representa un grafo completo ponderado
    };

    Partido rondas[NUM_EQUIPOS - 1][NUM_EQUIPOS / 2];
    int equipoLocal = 0;
    int equipoVisitante = NUM_EQUIPOS / 2;

    // Asignar partidos para la primera ronda
    for (int i = 0; i < NUM_EQUIPOS - 1; i++) {
        for (int j = 0; j < NUM_EQUIPOS / 2; j++) {
            rondas[i][j].equipoLocal = equipoLocal;
            rondas[i][j].equipoVisitante = equipoVisitante;

            equipoLocal = (equipoLocal + 1) % (NUM_EQUIPOS - 1);
            equipoVisitante = (equipoVisitante + 1) % (NUM_EQUIPOS - 1);

            if (j == 0 && i % 2 == 1) {
                // Intercambiar los equipos para equilibrar las distancias en rondas impares
                int temp = equipoLocal;
                equipoLocal = equipoVisitante;
                equipoVisitante = temp;
            }
        }
    }

    // Calcular las distancias recorridas en la primera ronda y mostrar los partidos
    int distanciaTotal = 0;
    for (int i = 0; i < NUM_EQUIPOS - 1; i++) {
        printf("Ronda %d:\n", i + 1);
        for (int j = 0; j < NUM_EQUIPOS / 2; j++) {
            Partido partido = rondas[i][j];
            int distancia = calcularDistancia(matrizAdyacencia, partido);
            distanciaTotal += distancia;

            printf("Partido %d: Equipo %d (Local) vs Equipo %d (Visitante) - Distancia: %d km\n",
                   j + 1, partido.equipoLocal + 1, partido.equipoVisitante + 1, distancia);
        }
        printf("\n");
    }

    printf("Distancia total recorrida por cada equipo al finalizar el torneo: %d km\n", distanciaTotal);

    return 0;
}