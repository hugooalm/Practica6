#include "agenda.h"

int menu() {
    printf("----- Practica -----\n");
    printf("Bienvenido a la Agenda: \n");
    printf("1 - Listado de personas."
           "\n2 - Nueva persona."
           "\n3 - Borrar persona."
           "\n4 - Guardar agenda en fichero de texto."
           "\n5 - Leer agenda de fichero de texto."
           "\n0 - Salir.\n");

    int opcion;
    tAgenda agenda;
    printf("\nElige una opcion: \n");
    scanf("%i",&opcion);

    inicializar_agenda(&agenda);

    while (opcion != 0) {
        switch (opcion) {
            case 1:
                printf("Listado de personas.\n");
                listar_personas(&agenda);
                printf("\nElige una opcion: ");
                scanf("%i",&opcion);
                break;

            case 2:
                printf("Nueva persona.\n");
                nueva_persona(&agenda);
                printf("\nElige una opcion: ");
                scanf("%i",&opcion);
                break;

            case 3:
                printf("Borrar persona.\n");
                borrar_persona(&agenda);
                printf("\nElige una opcion: ");
                scanf("%i",&opcion);
                break;
            case 4:
                guardarEnFichero(&agenda);
                break;
            case 5:
                leerFichero(&agenda);

            default:
                printf("No introduciste ningun valor correcto.\n");
                printf("\nElige una opcion: ");
                scanf("%i",&opcion);
        }
    }
    printf("\nHas terminado la practica.");
}

void inicializar_agenda(tAgenda *agenda) {
    agenda->personas = (tPersona*)malloc(MAX_PERSONAS * sizeof(tPersona));
    agenda->num_personas = 0;
}

void listar_personas(tAgenda *agenda) {
    printf("\nListado de personas:\n\n");

    for (int i = 0; i < agenda->num_personas; i++) {
        printf("%d;%s;%s;%s;%d;", i+1, agenda->personas[i].nombre, agenda->personas[i].apellidos, agenda->personas[i].numero, agenda->personas[i].edad);

        switch (agenda->personas[i].c) {
            case Favorito:
                printf("FAVORITO\n");
                break;
            case Conocido:
                printf("CONOCIDO\n");
                break;
            case Trabajo:
                printf("TRABAJO\n");
                break;
            default:
                printf("\n");
                break;
        }
    }
}

void nueva_persona(tAgenda *agenda) {
    if (agenda->num_personas < MAX_PERSONAS) {
        tPersona nueva;

        printf("\nIntroduzca los datos de la nueva persona:\n");
        printf("\nNombre: \n");
        scanf("%s", nueva.nombre);
        printf("\nApellidos: \n");
        scanf("%s", nueva.apellidos);
        printf("\nNumero de telefono: \n");
        scanf("%s", nueva.numero);
        printf("\nEdad: \n");
        scanf("%hd", &nueva.edad);
        printf("\nTipo de contacto (0-FAVORITO, 1-CONOCIDO, 2-TRABAJO): \n");
        scanf("%d", &nueva.c);

        agenda->personas[agenda->num_personas] = nueva;
        agenda->num_personas++;
        printf("\nContacto introducido correctamente.\n");
    } else {
        printf("\nNo se pueden introducir mas contactos a la agenda.\n");
    }
}

void borrar_persona(tAgenda *agenda) {
    int num_persona;

    printf("\nIndique el numero de la persona a borrar: \n");
    scanf("%d", &num_persona);

    if (num_persona >= 1 && num_persona <= agenda->num_personas) {
        tPersona *persona_a_borrar = &agenda->personas[num_persona - 1];

        printf("\nUsted desea borrar %d;%s;%s;%s;%d;", num_persona, persona_a_borrar->nombre,
               persona_a_borrar->apellidos, persona_a_borrar->numero, persona_a_borrar->edad);
        switch (persona_a_borrar->c) {
            case Favorito:
                printf("FAVORITO\n");
                break;
            case Conocido:
                printf("CONOCIDO\n");
                break;
            case Trabajo:
                printf("TRABAJO\n");
                break;
            default:
                break;
        }

        printf("\n¿Seguro? S/N: ");
        char respuesta[2];
        scanf("%s", respuesta);

        if (respuesta[0] == 'S' || respuesta[0] == 's') {

            for (int i = num_persona - 1; i < agenda->num_personas - 1; i++) {
                agenda->personas[i] = agenda->personas[i + 1];
            }


            agenda->num_personas--;

            printf("\nPersona borrada\n");
        }
    } else {
        printf("\nNumero de persona incorrecto\n");
    }
}

void guardarEnFichero(tAgenda *agenda){
    FILE *fichero = fopen("texto.txt","w");
    if (fichero == NULL){
        perror("No se ha podido crear el archio.%n");
    }else {
        for (int i = 0; i < agenda->num_personas; i++) {
            fprintf(fichero, "%d;%s;%s;%s;%d;", i+1, agenda->personas[i].nombre, agenda->personas[i].apellidos, agenda->personas[i].numero, agenda->personas[i].edad);

            switch (agenda->personas[i].c) {
                case Favorito:
                    fprintf(fichero, "FAVORITO%n");
                    break;
                case Conocido:
                    fprintf(fichero, "CONOCIDO%n");
                    break;
                case Trabajo:
                    fprintf(fichero, "TRABAJO%n");
                    break;
                default:
                    fprintf(fichero, "%n");
                    break;
            }
        }
    }

    fclose(fichero);

}


int leerFichero(tAgenda *agenda){
    char linea[MAX];
    FILE *fichero = fopen("texto.txt","r");

    while(!feof(fichero)){
        fscanf(fichero,"%s",linea);
    }
    fclose(fichero);
    if (fclose(fichero) != 0){
        printf("Error en clausura del fichero\n");
    }
    return 0;
}

