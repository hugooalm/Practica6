
#ifndef PRACTICA_6_AGENDA_H
#define PRACTICA_6_AGENDA_H


#include <stdio.h>
#include <string.h>
#define MAX 50

#include <stdio.h>
#include "malloc.h"
#define MAX 10000
#define MAX_PERSONAS 100

enum contacto{
    Favorito,
    Conocido,
    Trabajo
};

typedef struct Persona {
    char nombre[MAX_PERSONAS];
    char apellidos[MAX_PERSONAS];
    char numero[MAX_PERSONAS];
    short int edad;
    enum contacto c;
} tPersona;

typedef struct Agenda {
    tPersona *personas;
    int num_personas;
} tAgenda;

int menu();
void inicializar_agenda(tAgenda *agenda);
void listar_personas(tAgenda *agenda);
void nueva_persona(tAgenda *agenda);
void borrar_persona(tAgenda *agenda);
void guardarEnFichero(tAgenda *agenda);
int leerFichero(tAgenda *agenda);


#endif //PRACTICA_6_AGENDA_H
