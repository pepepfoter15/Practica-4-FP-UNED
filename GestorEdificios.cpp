#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "GestorEdificios.h"

// Función para inicializar las variables con información predefinida de los edificios.
void InicializarEdificios(Edificios edificios) {

    // Edificio 1
    edificios[0].id = 1;
    strcpy(edificios[0].nombre, "Neptuno");
    edificios[0].ApartamentosBasicos = 3;
    edificios[0].ApartamentosNormales = 12;
    edificios[0].ApartamentosLujosos = 2;
    edificios[0].ExisteEdificio = true;

    // Inicializar apartamentos en el edificio 1
    for (int i = 0; i < edificios[0].ApartamentosBasicos; i++) {
        strcpy(edificios[0].Apartamentos[i].tipo, "Basico");
        edificios[0].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[0].ApartamentosBasicos; i < edificios[0].ApartamentosBasicos + edificios[0].ApartamentosNormales; i++) {
        strcpy(edificios[0].Apartamentos[i].tipo, "Normal");
        edificios[0].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[0].ApartamentosBasicos + edificios[0].ApartamentosNormales; i < edificios[0].ApartamentosBasicos + edificios[0].ApartamentosNormales + edificios[0].ApartamentosLujosos; i++) {
        strcpy(edificios[0].Apartamentos[i].tipo, "Lujo");
        edificios[0].Apartamentos[i].disponible = true;
    }

    // Edificio 2
    edificios[1].id = 2;
    strcpy(edificios[1].nombre, "Pruebas Pepe");
    edificios[1].ApartamentosBasicos = 0;
    edificios[1].ApartamentosNormales = 0;
    edificios[1].ApartamentosLujosos = 0;
    edificios[1].ExisteEdificio = true;

    // Edificio 3
    edificios[2].id = 3;
    strcpy(edificios[2].nombre, "Apolo");
    edificios[2].ApartamentosBasicos = 8;
    edificios[2].ApartamentosNormales = 5;
    edificios[2].ApartamentosLujosos = 3;
    edificios[2].ExisteEdificio = true;

    // Inicializar apartamentos en el edificio 3
    for (int i = 0; i < edificios[2].ApartamentosBasicos; i++) {
        strcpy(edificios[2].Apartamentos[i].tipo, "Basico");
        edificios[2].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[2].ApartamentosBasicos; i < edificios[2].ApartamentosBasicos + edificios[2].ApartamentosNormales; i++) {
        strcpy(edificios[2].Apartamentos[i].tipo, "Normal");
        edificios[2].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[2].ApartamentosBasicos + edificios[2].ApartamentosNormales; i < edificios[2].ApartamentosBasicos + edificios[2].ApartamentosNormales + edificios[2].ApartamentosLujosos; i++) {
        strcpy(edificios[2].Apartamentos[i].tipo, "Lujo");
        edificios[2].Apartamentos[i].disponible = true;
    }

    // Edificio 4
    edificios[3].id = 4;
    strcpy(edificios[3].nombre, "Zeus");
    edificios[3].ApartamentosBasicos = 9;
    edificios[3].ApartamentosNormales = 6;
    edificios[3].ApartamentosLujosos = 5;
    edificios[3].ExisteEdificio = true;

    // Inicializar apartamentos en el edificio 4
    for (int i = 0; i < edificios[3].ApartamentosBasicos; i++) {
        strcpy(edificios[3].Apartamentos[i].tipo, "Basico");
        edificios[3].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[3].ApartamentosBasicos; i < edificios[3].ApartamentosBasicos + edificios[3].ApartamentosNormales; i++) {
        strcpy(edificios[3].Apartamentos[i].tipo, "Normal");
        edificios[3].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[3].ApartamentosBasicos + edificios[3].ApartamentosNormales; i < edificios[3].ApartamentosBasicos + edificios[3].ApartamentosNormales + edificios[3].ApartamentosLujosos; i++) {
        strcpy(edificios[3].Apartamentos[i].tipo, "Lujo");
        edificios[3].Apartamentos[i].disponible = true;
    }

    // Edificio 5
    edificios[4].id = 5;
    strcpy(edificios[4].nombre, "Atenea");
    edificios[4].ApartamentosBasicos = 4;
    edificios[4].ApartamentosNormales = 9;
    edificios[4].ApartamentosLujosos = 2;
    edificios[4].ExisteEdificio = true;

    // Inicializar apartamentos en el edificio 5
    for (int i = 0; i < edificios[4].ApartamentosBasicos; i++) {
        strcpy(edificios[4].Apartamentos[i].tipo, "Basico");
        edificios[4].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[4].ApartamentosBasicos; i < edificios[4].ApartamentosBasicos + edificios[4].ApartamentosNormales; i++) {
        strcpy(edificios[4].Apartamentos[i].tipo, "Normal");
        edificios[4].Apartamentos[i].disponible = true;
    }
    for (int i = edificios[4].ApartamentosBasicos + edificios[4].ApartamentosNormales; i < edificios[4].ApartamentosBasicos + edificios[4].ApartamentosNormales + edificios[4].ApartamentosLujosos; i++) {
        strcpy(edificios[4].Apartamentos[i].tipo, "Lujo");
        edificios[4].Apartamentos[i].disponible = true;
    }
}

// Función para copiar la información de los edificios a un array de reservas.
void InicializarReservas(Edificios edificios, ReservasEdificios reservas) {
    for (int i = 0; i < MaximosEdificios; i++) {
        reservas[i] = edificios[i]; // Copia el edificio completo

        // Copiar apartamentos uno por uno
        for (int j = 0; j < MaximosApartamentos; j++) {
            reservas[i].Apartamentos[j] = edificios[i].Apartamentos[j];
        }
    }
}

// Función para listar todos los edificios existentes con sus detalles.
void ListarEdificios(Edificios edificios) {
    printf("Listar Edificios:\n");
    printf("\n");
    printf("ID\tNombre\t\t\tApartamentos Básicos\tApartamentos Normales\tApartamentos Lujosos\n");
    for (int i = 0; i < MaximosEdificios; i++) {
        if (edificios[i].ExisteEdificio) {
            printf("%d\t%-18s\t%d\t\t\t%d\t\t\t%d\n",
                   edificios[i].id,
                   edificios[i].nombre,
                   edificios[i].ApartamentosBasicos,
                   edificios[i].ApartamentosNormales,
                   edificios[i].ApartamentosLujosos);
        }
    }
    printf("\n");
}

// Función para editar la información de un edificio específico.
void EditarEdificio(Edificios edificios, ReservasEdificios reservas) {
    int id, apartamentosBasicos, apartamentosNormales, apartamentosLujosos;
    TipoNombreEdificio nombre;
    char confirmacion;
    int totalApartamentos = 0;
    int EliminarID = 0;
    int indice = 0;

    // Solicita al usuario la información para editar un edificio.
    printf("Editar Edificio:\n");
    printf("\n");
    printf("\tIdentificador (número entre 1 y 5)? ");
    scanf("%d", &id);

    // Verifica que el ID esté dentro de un rango válido.
    if (id < 1 || id > MaximosEdificios) {
        printf("\nError: El identificador debe estar entre 1 y 5.\n\n");
        return;
    }

    // Recoge datos del nuevo edificio.
    printf("\tNombre (entre 1 y 20 caracteres)? ");
    scanf(" %30[^\n]", nombre);
    printf("\tNumero de Apartamentos Basicos? ");
    scanf("%d", &apartamentosBasicos);
    printf("\tNumero de Apartamentos Normales? ");
    scanf("%d", &apartamentosNormales);
    printf("\tNumero de Apartamentos de Lujo? ");
    scanf("%d", &apartamentosLujosos);

    totalApartamentos = apartamentosBasicos + apartamentosNormales + apartamentosLujosos;

    // Valida que el número total de apartamentos no exceda el máximo permitido.
    if (totalApartamentos > MaximosApartamentos) {
        printf("\nError: El numero total de apartamentos no puede exceder los %d.\n\n", MaximosApartamentos);
        return;
    }

    // Confirma si los datos nuevos son correctos.
    printf("\nIMPORTANTE: Esta opcion borra los datos anteriores.\n");
    printf("Son correctos los nuevos datos (S/N)? ");
    scanf(" %c", &confirmacion);

    confirmacion = toupper(confirmacion);
    if (confirmacion != 'S') {
        printf("\nOperacion cancelada.\n\n");
        return;
    }

    // Si no hay apartamentos, el edificio se desactiva.
    if (apartamentosBasicos <= 0 && apartamentosNormales <= 0 && apartamentosLujosos <= 0) {
        EliminarID = id - 1;
        edificios[EliminarID].ExisteEdificio = false;
        printf("\nEl edificio con ID %d ha sido dado de baja.\n\n", id);
        return;
    }

    indice = id - 1;
    edificios[indice].id = id;
    strcpy(edificios[indice].nombre, nombre);
    edificios[indice].ApartamentosBasicos = apartamentosBasicos;
    edificios[indice].ApartamentosNormales = apartamentosNormales;
    edificios[indice].ApartamentosLujosos = apartamentosLujosos;
    edificios[indice].ExisteEdificio = true;

    // Limpiar y actualizar apartamentos en el array original

    for (int i = 0; i < MaximosApartamentos; i++) {
        edificios[indice].Apartamentos[i].disponible = false;
    }

    for (int i = 0; i < apartamentosBasicos; i++) {
        strcpy(edificios[indice].Apartamentos[i].tipo, "Basico");
        edificios[indice].Apartamentos[i].disponible = true;
    }
    for (int i = apartamentosBasicos; i < apartamentosBasicos + apartamentosNormales; i++) {
        strcpy(edificios[indice].Apartamentos[i].tipo, "Normal");
        edificios[indice].Apartamentos[i].disponible = true;
    }
    for (int i = apartamentosBasicos + apartamentosNormales; i < apartamentosBasicos + apartamentosNormales + apartamentosLujosos; i++) {
        strcpy(edificios[indice].Apartamentos[i].tipo, "Lujo");
        edificios[indice].Apartamentos[i].disponible = true;
    }

    // Actualiza las reservas con los nuevos datos.
    InicializarReservas(edificios, reservas);

    printf("\nEdificio actualizado correctamente.\n\n");
}

