#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "GestorEdificios.h"
#include "GestorReservas.h"
#include "CalendarioMes.h"


int main(){

    char opcion = ' ';
    Edificios edificios;
    ReservasEdificios reservas;

    InicializarEdificios(edificios);
    InicializarReservas(edificios, reservas);


    while (opcion != 'S'){
        printf("GesRAE: Gestion de Reservas Apartamentos-Edificios\n");
        printf("\n");
        printf("\t Editar Edificio\t\t (Pulsar E)\n");
        printf("\t Listar Edificios\t\t (Pulsar L)\n");
        printf("\t Apartamentos Disponibles\t (Pulsar A)\n");
        printf("\t Reservar Apartamento\t\t (Pulsar R)\n");
        printf("\t Reservar Mensuales Apartamento\t (Pulsar M)\n");
        printf("\t Salir\t\t\t\t (Pulsar S)\n\n");

        printf("Teclear una opcion valida (E|L|A|R|M|S)?");
        scanf(" %c", &opcion);
        opcion = toupper(opcion);

        // Función para editar el edificio.
        if (opcion == 'E') {
            EditarEdificio(edificios, reservas);
        }

        // Función para listar todos los edificios.
        else if (opcion == 'L') {
            ListarEdificios(edificios);
        }

        // Función para ver lo apartamentos libres el edificio.
        else if (opcion == 'A') {
            ApartamentosDisponibles(reservas);
        }

        // Función para reservar un apartamento de un edificio según la fecha y la hora introducidos.
        else if (opcion == 'R') {
            ReservarApartamento(reservas);
        }

        // Función para ver las reservas mensuales de otro apartamento.
        else if (opcion == 'M') {
            ReservarApartamentoMes(reservas);
        }

        else {
            printf("\n\nInserte una letra válida.\n\n");
        }
    }

    // Función para salir del programa.
    if (opcion == 'S') {
        system("cls");
        printf("\n¡Muchas gracias y le esperamos en su siguiente visita!\n");
        return 0;
    }
    return 0;
}

