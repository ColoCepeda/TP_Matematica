//Aca voy a empezar a crear el codigo, lo subo solo para que lo vayan teniendo. Saludos!!
#include <stdio.h>
#include <string.h>

#define NUM_EQUIPOS 20

struct Equipo {
    char nombre[50];
    int distanciaRecorrida;
    char clasico[50];
};

void generarFixture(struct Equipo equipos[], int distancias[][NUM_EQUIPOS]) {
   
}

int main() {
    struct Equipo equipos[NUM_EQUIPOS];

    //Distancias entre los equipos
    int distancias[NUM_EQUIPOS][NUM_EQUIPOS] = {
    {0, 17, 20, 28, 29, 313, 287, 69, 70, 687, 688, 458, 455, 36, 26, 17, 9, 20, 6},
    {17, 0, 6, 5, 8, 3, 314, 304, 54, 53, 702, 704, 473, 471, 15, 12, 18, 14, 35, 19},
    {20, 6, 0, 1, 10, 6, 317, 305, 52, 51, 714, 706, 476, 474, 11, 7, 21, 17, 38, 21},
    {20, 5, 1, 0, 10, 6, 317, 305, 52, 51, 714, 706, 476, 474, 11, 7, 21, 17, 37, 20},
    {28, 8, 10, 10, 0, 5, 316, 305, 63, 62, 704, 705, 476, 474, 19, 11, 11, 8, 38, 23},
    {29, 3, 6, 6, 5, 0, 320, 309, 59, 58, 708, 709, 480, 477, 19, 11, 15, 10, 41, 19},
    {313, 314, 317, 317, 316, 320, 0, 7, 366, 365, 405, 406, 168, 165, 323, 322, 304, 303, 288, 294},
    {287, 304, 305, 305, 305, 309, 7, 0, 355, 355, 404, 405, 175, 173, 312, 313, 294, 292, 278, 284},
    {69, 54, 52, 52, 63, 59, 366, 355, 0, 1, 763, 764, 525, 523, 54, 53, 70, 65, 86, 70},
    {70, 53, 51, 51, 62, 58, 365, 355, 1, 0, 764, 765, 526, 524, 55, 54, 71, 66, 87, 71},
    {687, 702, 714, 714, 704, 708, 405, 404, 763, 764, 0, 8, 376, 373, 712, 712, 693, 692, 677, 683},
    {688, 704, 706, 706, 705, 709, 406, 405, 764, 765, 8, 0, 371, 369, 714, 714, 695, 694, 679, 685},
    {458, 473, 476, 476, 476, 480, 168, 175, 525, 526, 376, 371, 0, 4, 484, 484, 465, 464, 449, 455},
    {455, 471, 474, 474, 474, 477, 165, 173, 523, 524, 373, 369, 4, 0, 480, 480, 461, 460, 455, 451},
    {36, 15, 11, 11, 19, 19, 323, 312, 54, 55, 712, 714, 484, 480, 0, 4, 21, 23, 46, 32},
    {26, 12, 7, 7, 11, 11, 322, 313, 53, 54, 712, 714, 484, 480, 4, 0, 19, 18, 45, 33},
    {17, 18, 21, 21, 11, 15, 304, 294, 70, 71, 693, 695, 465, 461, 21, 19, 0, 6, 27, 13},
    {9, 14, 17, 17, 8, 10, 303, 292, 65, 66, 692, 694, 464, 460, 23, 18, 6, 0, 26, 12},
    {20, 35, 38, 38, 38, 41, 288, 278, 86, 87, 677, 679, 449, 455, 46, 45, 27, 26, 0, 16},
    {6, 19, 21, 21, 23, 19, 294, 284, 70, 71, 683, 685, 455, 451, 32, 33, 13, 12, 16, 0}};

    // Datos equipos
    const char* nombres[] = {"River Plate", "Boca Jrs", "Independiente", "Racing", "San Lorenzo", "Huracán", "Rosario Central", "Newell's", "Estudiantes de La Plata", "Gimnasia Esgrima de La Plata", "Talleres de Córdoba", "Belgrano de Córdoba", "Colon de Santa Fe", "Unión de Santa Fe", "Bandfield", "Lanús", "Vélez Sarsfield", "Argentinos Jrs", "Tigre", "Platense"};
    const char* clasicos[] = {"Boca Jrs", "River Plate", "Racing", "Independiente", "Huracán", "San Lorenzo", "Newell's", "Rosario Central", "Gimnasia Esgrima de La Plata", "Estudiantes de La Plata", "Belgrano de Córdoba", "Talleres de Córdoba", "Unión de Santa Fe", "Colon de Santa Fe", "Lanús", "Bandfield", "Argentinos Jrs", "Vélez Sarsfield", "Platense", "Tigre"};

    // Inicializar los datos de los equipos
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        strcpy(equipos[i].nombre, nombres[i]);
        equipos[i].distanciaRecorrida = 0;
        strcpy(equipos[i].clasico, clasicos[i]);
    }

    // Generar el fixture
    generarFixture(equipos, distancias);

    return 0;
}
