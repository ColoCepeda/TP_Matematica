//Aca voy a empezar a crear el codigo, lo subo solo para que lo vayan teniendo. Saludos!!
#include <stdio.h>
#include <string.h>

#define NUM_EQUIPOS 20

struct Equipo {
    char nombre[50];
    int distanciaRecorrida;
    char rival[50];
};

void generarFixture(struct Equipo equipos[], int distancias[][NUM_EQUIPOS]) {
    int numPartidos = NUM_EQUIPOS * (NUM_EQUIPOS - 1) / 2;
    int distanciaTotal = 0;
    int distanciaMaxima = 0;
    int equipoLocal = 0;
    int equipoVisitante = 0;

    printf("Generando fixture...\n");

    for (int i = 0; i < numPartidos; i++) {
        printf("Partido %d: %s vs %s\n", i+1, equipos[equipoLocal].nombre, equipos[equipoVisitante].nombre);

        // Obtener la distancia entre los equipos y sumarla al registro correspondiente
        int distancia = distancias[equipoLocal][equipoVisitante];
        equipos[equipoLocal].distanciaRecorrida += distancia;
        equipos[equipoVisitante].distanciaRecorrida += distancia;

        // Actualizar la distancia máxima y determinar el equipo local en los clásicos rivales
        if (distancia > distanciaMaxima) {
            distanciaMaxima = distancia;
            if (strcmp(equipos[equipoLocal].rival, equipos[equipoVisitante].nombre) == 0) {
                equipoLocal = equipoVisitante;
            } else {
                equipoLocal = equipoLocal;
            }
        }

        // Actualizar los índices de los equipos para el siguiente partido
        equipoVisitante++;
        if (equipoVisitante == NUM_EQUIPOS) {
            equipoLocal++;
            equipoVisitante = equipoLocal + 1;
        }
    }

    printf("Fixture generado con éxito.\n\n");

    // Mostrar los datos de los equipos después del fixture
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        printf("Equipo %d:\n", i+1);
        printf("Nombre: %s\n", equipos[i].nombre);
        printf("Distancia recorrida: %d\n", equipos[i].distanciaRecorrida);
        printf("Rival: %s\n", equipos[i].rival);
        printf("------------------------\n");
    }
}

int main() {
    struct Equipo equipos[NUM_EQUIPOS];
    int distancias[NUM_EQUIPOS][NUM_EQUIPOS] = {
        // ... Ingresar las distancias entre los equipos aquí ...
    };

    // Datos de ejemplo para los equipos
    const char* nombres[] = {"Equipo1", "Equipo2", "Equipo3", /* ... Agrega los nombres de los equipos aquí ... */};
    const char* rivales[] = {"Rival1", "Rival2", "Rival3", /* ... Agrega los nombres de los rivales aquí ... */};

    // Inicializar los datos de los equipos
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        strcpy(equipos[i].nombre, nombres[i]);
        equipos[i].distanciaRecorrida = 0;
        strcpy(equipos[i].rival, rivales[i]);
    }

    // Generar el fixture
    generarFixture(equipos, distancias);

    return 0;
}
