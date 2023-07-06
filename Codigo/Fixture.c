//Aca voy a empezar a crear el codigo, lo subo solo para que lo vayan teniendo. Saludos!!
#include <stdio.h>
#include <string.h>

#define NUM_EQUIPOS 20

struct Equipo {
    char nombre[50];
    int distanciaRecorrida;
    char clasico[50];
    int posicion;
};
struct Fixture
{
    int x;
    int y;
};


void generarFixture(struct Equipo equipos[], struct Fixture fixtureOficial[19][10]);

int main() {
    struct Equipo equipos[NUM_EQUIPOS];
    struct Fixture fixtureOficial[19][10];

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
    const char* nombres[] = {"River Plate", "Boca Jrs", "Independiente", "Racing", "San Lorenzo", "Huracán",
                             "Rosario Central", "Newell's", "Estudiantes de La Plata", "Gimnasia Esgrima de La Plata",
                             "Talleres de Córdoba", "Belgrano de Córdoba", "Colon de Santa Fe", "Unión de Santa Fe",
                              "Bandfield", "Lanús", "Vélez Sarsfield", "Argentinos Jrs", "Tigre", "Platense"};

    const char* clasicos[] = {"Boca Jrs", "River Plate", "Racing", "Independiente", "Huracán", "San Lorenzo",
                             "Newell's", "Rosario Central", "Gimnasia Esgrima de La Plata", "Estudiantes de La Plata",
                             "Belgrano de Córdoba", "Talleres de Córdoba", "Unión de Santa Fe", "Colon de Santa Fe",
                              "Lanús", "Bandfield", "Argentinos Jrs", "Vélez Sarsfield", "Platense", "Tigre"};

    // Inicializar los datos de los equipos
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        strcpy(equipos[i].nombre, nombres[i]);
        equipos[i].distanciaRecorrida = 0;
        strcpy(equipos[i].clasico, clasicos[i]);
        equipos[i].posicion = i;
    }

    // Generar el fixture
    generarFixture(equipos, fixtureOficial);

    return 0;
}
void generarFixture(struct Equipo equipos[], struct Fixture fixtureOficial[19][10]) {
    
    //Fecha 1//
    fixtureOficial[0][0].x = 17, fixtureOficial[0][0].y = 14;
    fixtureOficial[0][1].x = 11, fixtureOficial[0][1].y = 1;
    fixtureOficial[0][2].x = 12, fixtureOficial[0][2].y = 8;
    fixtureOficial[0][3].x = 9, fixtureOficial[0][3].y = 5;
    fixtureOficial[0][4].x = 2, fixtureOficial[0][4].y = 15;
    fixtureOficial[0][5].x = 7, fixtureOficial[0][5].y = 19;
    fixtureOficial[0][6].x = 3, fixtureOficial[0][6].y = 0;
    fixtureOficial[0][7].x = 6, fixtureOficial[0][7].y = 4;
    fixtureOficial[0][8].x = 10, fixtureOficial[0][8].y = 18;
    fixtureOficial[0][9].x = 13, fixtureOficial[0][9].y = 16;
    //Fecha 2//
    fixtureOficial[1][0].x = 0, fixtureOficial[1][0].y = 0;
    fixtureOficial[1][1].x = 0, fixtureOficial[1][1].y = 0;
    fixtureOficial[1][2].x = 0, fixtureOficial[1][2].y = 0;
    fixtureOficial[1][3].x = 0, fixtureOficial[1][3].y = 0;
    fixtureOficial[1][4].x = 0, fixtureOficial[1][4].y = 0;
    fixtureOficial[1][5].x = 0, fixtureOficial[1][5].y = 0;
    fixtureOficial[1][6].x = 0, fixtureOficial[1][6].y = 0;
    fixtureOficial[1][7].x = 0, fixtureOficial[1][7].y = 0;
    fixtureOficial[1][8].x = 0, fixtureOficial[1][8].y = 0;
    fixtureOficial[1][9].x = 0, fixtureOficial[1][9].y = 0;
    //Fecha 3//
    fixtureOficial[2][0].x = 0, fixtureOficial[2][0].y = 0;
    fixtureOficial[2][1].x = 0, fixtureOficial[2][1].y = 0;
    fixtureOficial[2][2].x = 0, fixtureOficial[2][2].y = 0;
    fixtureOficial[2][3].x = 0, fixtureOficial[2][3].y = 0;
    fixtureOficial[2][4].x = 0, fixtureOficial[2][4].y = 0;
    fixtureOficial[2][5].x = 0, fixtureOficial[2][5].y = 0;
    fixtureOficial[2][6].x = 0, fixtureOficial[2][6].y = 0;
    fixtureOficial[2][7].x = 0, fixtureOficial[2][7].y = 0;
    fixtureOficial[2][8].x = 0, fixtureOficial[2][8].y = 0;
    fixtureOficial[2][9].x = 0, fixtureOficial[2][9].y = 0;
    //Fecha 4//
    fixtureOficial[3][0].x = 0, fixtureOficial[3][0].y = 0;
    fixtureOficial[3][1].x = 0, fixtureOficial[3][1].y = 0;
    fixtureOficial[3][2].x = 0, fixtureOficial[3][2].y = 0;
    fixtureOficial[3][3].x = 0, fixtureOficial[3][3].y = 0;
    fixtureOficial[3][4].x = 0, fixtureOficial[3][4].y = 0;
    fixtureOficial[3][5].x = 0, fixtureOficial[3][5].y = 0;
    fixtureOficial[3][6].x = 0, fixtureOficial[3][6].y = 0;
    fixtureOficial[3][7].x = 0, fixtureOficial[3][7].y = 0;
    fixtureOficial[3][8].x = 0, fixtureOficial[3][8].y = 0;
    fixtureOficial[3][9].x = 0, fixtureOficial[3][9].y = 0;
    //Fecha 5//
    fixtureOficial[4][0].x = 0, fixtureOficial[4][0].y = 0;
    fixtureOficial[4][1].x = 0, fixtureOficial[4][1].y = 0;
    fixtureOficial[4][2].x = 0, fixtureOficial[4][2].y = 0;
    fixtureOficial[4][3].x = 0, fixtureOficial[4][3].y = 0;
    fixtureOficial[4][4].x = 0, fixtureOficial[4][4].y = 0;
    fixtureOficial[4][5].x = 0, fixtureOficial[4][5].y = 0;
    fixtureOficial[4][6].x = 0, fixtureOficial[4][6].y = 0;
    fixtureOficial[4][7].x = 0, fixtureOficial[4][7].y = 0;
    fixtureOficial[4][8].x = 0, fixtureOficial[4][8].y = 0;
    fixtureOficial[4][9].x = 0, fixtureOficial[4][9].y = 0;
    //Fecha 6//
    fixtureOficial[5][0].x = 0, fixtureOficial[5][0].y = 0;
    fixtureOficial[5][1].x = 0, fixtureOficial[5][1].y = 0;
    fixtureOficial[5][2].x = 0, fixtureOficial[5][2].y = 0;
    fixtureOficial[5][3].x = 0, fixtureOficial[5][3].y = 0;
    fixtureOficial[5][4].x = 0, fixtureOficial[5][4].y = 0;
    fixtureOficial[5][5].x = 0, fixtureOficial[5][5].y = 0;
    fixtureOficial[5][6].x = 0, fixtureOficial[5][6].y = 0;
    fixtureOficial[5][7].x = 0, fixtureOficial[5][7].y = 0;
    fixtureOficial[5][8].x = 0, fixtureOficial[5][8].y = 0;
    fixtureOficial[5][9].x = 0, fixtureOficial[5][9].y = 0;
    //Fecha 7//
    fixtureOficial[6][0].x = 0, fixtureOficial[6][0].y = 0;
    fixtureOficial[6][1].x = 0, fixtureOficial[6][1].y = 0;
    fixtureOficial[6][2].x = 0, fixtureOficial[6][2].y = 0;
    fixtureOficial[6][3].x = 0, fixtureOficial[6][3].y = 0;
    fixtureOficial[6][4].x = 0, fixtureOficial[6][4].y = 0;
    fixtureOficial[6][5].x = 0, fixtureOficial[6][5].y = 0;
    fixtureOficial[6][6].x = 0, fixtureOficial[6][6].y = 0;
    fixtureOficial[6][7].x = 0, fixtureOficial[6][7].y = 0;
    fixtureOficial[6][8].x = 0, fixtureOficial[6][8].y = 0;
    fixtureOficial[6][9].x = 0, fixtureOficial[6][9].y = 0;
    //Fecha 8//
    fixtureOficial[7][0].x = 0, fixtureOficial[7][0].y = 0;
    fixtureOficial[7][1].x = 0, fixtureOficial[7][1].y = 0;
    fixtureOficial[7][2].x = 0, fixtureOficial[7][2].y = 0;
    fixtureOficial[7][3].x = 0, fixtureOficial[7][3].y = 0;
    fixtureOficial[7][4].x = 0, fixtureOficial[7][4].y = 0;
    fixtureOficial[7][5].x = 0, fixtureOficial[7][5].y = 0;
    fixtureOficial[7][6].x = 0, fixtureOficial[7][6].y = 0;
    fixtureOficial[7][7].x = 0, fixtureOficial[7][7].y = 0;
    fixtureOficial[7][8].x = 0, fixtureOficial[7][8].y = 0;
    fixtureOficial[7][9].x = 0, fixtureOficial[7][9].y = 0;
    //Fecha 9//
    fixtureOficial[8][0].x = 0, fixtureOficial[8][0].y = 0;
    fixtureOficial[8][1].x = 0, fixtureOficial[8][1].y = 0;
    fixtureOficial[8][2].x = 0, fixtureOficial[8][2].y = 0;
    fixtureOficial[8][3].x = 0, fixtureOficial[8][3].y = 0;
    fixtureOficial[8][4].x = 0, fixtureOficial[8][4].y = 0;
    fixtureOficial[8][5].x = 0, fixtureOficial[8][5].y = 0;
    fixtureOficial[8][6].x = 0, fixtureOficial[8][6].y = 0;
    fixtureOficial[8][7].x = 0, fixtureOficial[8][7].y = 0;
    fixtureOficial[8][8].x = 0, fixtureOficial[8][8].y = 0;
    fixtureOficial[8][9].x = 0, fixtureOficial[8][9].y = 0;
    //Fecha 10//
    fixtureOficial[9][0].x = 0, fixtureOficial[9][0].y = 0;
    fixtureOficial[9][1].x = 0, fixtureOficial[9][1].y = 0;
    fixtureOficial[9][2].x = 0, fixtureOficial[9][2].y = 0;
    fixtureOficial[9][3].x = 0, fixtureOficial[9][3].y = 0;
    fixtureOficial[9][4].x = 0, fixtureOficial[9][4].y = 0;
    fixtureOficial[9][5].x = 0, fixtureOficial[9][5].y = 0;
    fixtureOficial[9][6].x = 0, fixtureOficial[9][6].y = 0;
    fixtureOficial[9][7].x = 0, fixtureOficial[9][7].y = 0;
    fixtureOficial[9][8].x = 0, fixtureOficial[9][8].y = 0;
    fixtureOficial[9][9].x = 0, fixtureOficial[9][9].y = 0;
    //Fecha 11//
    fixtureOficial[10][0].x = 0, fixtureOficial[10][0].y = 0;
    fixtureOficial[10][1].x = 0, fixtureOficial[10][1].y = 0;
    fixtureOficial[10][2].x = 0, fixtureOficial[10][2].y = 0;
    fixtureOficial[10][3].x = 0, fixtureOficial[10][3].y = 0;
    fixtureOficial[10][4].x = 0, fixtureOficial[10][4].y = 0;
    fixtureOficial[10][5].x = 0, fixtureOficial[10][5].y = 0;
    fixtureOficial[10][6].x = 0, fixtureOficial[10][6].y = 0;
    fixtureOficial[10][7].x = 0, fixtureOficial[10][7].y = 0;
    fixtureOficial[10][8].x = 0, fixtureOficial[10][8].y = 0;
    fixtureOficial[10][9].x = 0, fixtureOficial[10][9].y = 0;
    //Fecha 12//
    fixtureOficial[11][0].x = 0, fixtureOficial[11][0].y = 0;
    fixtureOficial[11][1].x = 0, fixtureOficial[11][1].y = 0;
    fixtureOficial[11][2].x = 0, fixtureOficial[11][2].y = 0;
    fixtureOficial[11][3].x = 0, fixtureOficial[11][3].y = 0;
    fixtureOficial[11][4].x = 0, fixtureOficial[11][4].y = 0;
    fixtureOficial[11][5].x = 0, fixtureOficial[11][5].y = 0;
    fixtureOficial[11][6].x = 0, fixtureOficial[11][6].y = 0;
    fixtureOficial[11][7].x = 0, fixtureOficial[11][7].y = 0;
    fixtureOficial[11][8].x = 0, fixtureOficial[11][8].y = 0;
    fixtureOficial[11][9].x = 0, fixtureOficial[11][9].y = 0;
    //Fecha 13//
    fixtureOficial[12][0].x = 0, fixtureOficial[12][0].y = 0;
    fixtureOficial[12][1].x = 0, fixtureOficial[12][1].y = 0;
    fixtureOficial[12][2].x = 0, fixtureOficial[12][2].y = 0;
    fixtureOficial[12][3].x = 0, fixtureOficial[12][3].y = 0;
    fixtureOficial[12][4].x = 0, fixtureOficial[12][4].y = 0;
    fixtureOficial[12][5].x = 0, fixtureOficial[12][5].y = 0;
    fixtureOficial[12][6].x = 0, fixtureOficial[12][6].y = 0;
    fixtureOficial[12][7].x = 0, fixtureOficial[12][7].y = 0;
    fixtureOficial[12][8].x = 0, fixtureOficial[12][8].y = 0;
    fixtureOficial[12][9].x = 0, fixtureOficial[12][9].y = 0;
    //Fecha 14//
    fixtureOficial[13][0].x = 0, fixtureOficial[13][0].y = 0;
    fixtureOficial[13][1].x = 0, fixtureOficial[13][1].y = 0;
    fixtureOficial[13][2].x = 0, fixtureOficial[13][2].y = 0;
    fixtureOficial[13][3].x = 0, fixtureOficial[13][3].y = 0;
    fixtureOficial[13][4].x = 0, fixtureOficial[13][4].y = 0;
    fixtureOficial[13][5].x = 0, fixtureOficial[13][5].y = 0;
    fixtureOficial[13][6].x = 0, fixtureOficial[13][6].y = 0;
    fixtureOficial[13][7].x = 0, fixtureOficial[13][7].y = 0;
    fixtureOficial[13][8].x = 0, fixtureOficial[13][8].y = 0;
    fixtureOficial[13][9].x = 0, fixtureOficial[13][9].y = 0;
    //Fecha 15//
    fixtureOficial[14][0].x = 0, fixtureOficial[14][0].y = 0;
    fixtureOficial[14][1].x = 0, fixtureOficial[14][1].y = 0;
    fixtureOficial[14][2].x = 0, fixtureOficial[14][2].y = 0;
    fixtureOficial[14][3].x = 0, fixtureOficial[14][3].y = 0;
    fixtureOficial[14][4].x = 0, fixtureOficial[14][4].y = 0;
    fixtureOficial[14][5].x = 0, fixtureOficial[14][5].y = 0;
    fixtureOficial[14][6].x = 0, fixtureOficial[14][6].y = 0;
    fixtureOficial[14][7].x = 0, fixtureOficial[14][7].y = 0;
    fixtureOficial[14][8].x = 0, fixtureOficial[14][8].y = 0;
    fixtureOficial[14][9].x = 0, fixtureOficial[14][9].y = 0;
    //Fecha 16//
    fixtureOficial[15][0].x = 0, fixtureOficial[15][0].y = 0;
    fixtureOficial[15][1].x = 0, fixtureOficial[15][1].y = 0;
    fixtureOficial[15][2].x = 0, fixtureOficial[15][2].y = 0;
    fixtureOficial[15][3].x = 0, fixtureOficial[15][3].y = 0;
    fixtureOficial[15][4].x = 0, fixtureOficial[15][4].y = 0;
    fixtureOficial[15][5].x = 0, fixtureOficial[15][5].y = 0;
    fixtureOficial[15][6].x = 0, fixtureOficial[15][6].y = 0;
    fixtureOficial[15][7].x = 0, fixtureOficial[15][7].y = 0;
    fixtureOficial[15][8].x = 0, fixtureOficial[15][8].y = 0;
    fixtureOficial[15][9].x = 0, fixtureOficial[15][9].y = 0;
    //Fecha 17//
    fixtureOficial[16][0].x = 0, fixtureOficial[16][0].y = 0;
    fixtureOficial[16][1].x = 0, fixtureOficial[16][1].y = 0;
    fixtureOficial[16][2].x = 0, fixtureOficial[16][2].y = 0;
    fixtureOficial[16][3].x = 0, fixtureOficial[16][3].y = 0;
    fixtureOficial[16][4].x = 0, fixtureOficial[16][4].y = 0;
    fixtureOficial[16][5].x = 0, fixtureOficial[16][5].y = 0;
    fixtureOficial[16][6].x = 0, fixtureOficial[16][6].y = 0;
    fixtureOficial[16][7].x = 0, fixtureOficial[16][7].y = 0;
    fixtureOficial[16][8].x = 0, fixtureOficial[16][8].y = 0;
    fixtureOficial[16][9].x = 0, fixtureOficial[16][9].y = 0;
    //Fecha 18//
    fixtureOficial[17][0].x = 0, fixtureOficial[17][0].y = 0;
    fixtureOficial[17][1].x = 0, fixtureOficial[17][1].y = 0;
    fixtureOficial[17][2].x = 0, fixtureOficial[17][2].y = 0;
    fixtureOficial[17][3].x = 0, fixtureOficial[17][3].y = 0;
    fixtureOficial[17][4].x = 0, fixtureOficial[17][4].y = 0;
    fixtureOficial[17][5].x = 0, fixtureOficial[17][5].y = 0;
    fixtureOficial[17][6].x = 0, fixtureOficial[17][6].y = 0;
    fixtureOficial[17][7].x = 0, fixtureOficial[17][7].y = 0;
    fixtureOficial[17][8].x = 0, fixtureOficial[17][8].y = 0;
    fixtureOficial[17][9].x = 0, fixtureOficial[17][9].y = 0;
    //Fecha 19//
    fixtureOficial[18][0].x = 0, fixtureOficial[18][0].y = 0;
    fixtureOficial[18][1].x = 0, fixtureOficial[18][1].y = 0;
    fixtureOficial[18][2].x = 0, fixtureOficial[18][2].y = 0;
    fixtureOficial[18][3].x = 0, fixtureOficial[18][3].y = 0;
    fixtureOficial[18][4].x = 0, fixtureOficial[18][4].y = 0;
    fixtureOficial[18][5].x = 0, fixtureOficial[18][5].y = 0;
    fixtureOficial[18][6].x = 0, fixtureOficial[18][6].y = 0;
    fixtureOficial[18][7].x = 0, fixtureOficial[18][7].y = 0;
    fixtureOficial[18][8].x = 0, fixtureOficial[18][8].y = 0;
    fixtureOficial[18][9].x = 0, fixtureOficial[18][9].y = 0;

    
}
