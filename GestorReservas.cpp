#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "GestorReservas.h"
#include "CalendarioMes.h"

// Función para mostrar los apartamentos disponibles del array de reservas
void ApartamentosDisponibles(ReservasEdificios reservas) {
    // Variables para capturar datos de entrada y resultados intermedios
    int EdificioID, duracionDias;
    TipoFecha fechaEntrada;
    TipoEdificio edificio;
    Apartamento apartamento;
    int disponiblesBasicos = 0;
    int disponiblesNormales = 0;
    int disponiblesLujosos = 0;

    // Solicita el identificador del edificio y verifica que sea válido
    printf("Apartamentos Disponibles:\n\n");
    printf("\tIdentificador de Edificio? ");
    scanf("%d", &EdificioID);

    if (EdificioID < 1 || EdificioID > MaximosEdificios || !reservas[EdificioID - 1].ExisteEdificio) {
        printf("\nError: Edificio no válido o no existe.\n\n");
        return;
    }

    // Obtiene el edificio correspondiente
    edificio = reservas[EdificioID - 1];

    // Solicita la fecha de entrada y duración de la estancia
    printf("\tFecha Entrada: Día? ");
    scanf("%d", &fechaEntrada.dia);
    printf("\tFecha Entrada: Mes? ");
    scanf("%d", &fechaEntrada.mes);
    printf("\tFecha Entrada: Año? ");
    scanf("%d", &fechaEntrada.anio);
    printf("\tDías de duración de la estancia? ");
    scanf("%d", &duracionDias);
    printf("\n");

    // Recorre los apartamentos del edificio para contar los disponibles según tipo
    for (int i = 0; i < MaximosApartamentos; i++) {
        apartamento = edificio.Apartamentos[i];
        if (apartamento.disponible && !apartamento.ocupado) {
            if (strcmp(apartamento.tipo, "Basico") == 0) {
                disponiblesBasicos++;
            } else if (strcmp(apartamento.tipo, "Normal") == 0) {
                disponiblesNormales++;
            } else if (strcmp(apartamento.tipo, "Lujo") == 0) {
                disponiblesLujosos++;
            }
        }
    }

    // Imprime el resultado de los apartamentos disponibles
    printf("El edificio '%s' desde el %d/%d/%d con una estancia de %d días tiene disponibles:\n",edificio.nombre, fechaEntrada.dia, fechaEntrada.mes, fechaEntrada.anio, duracionDias);
    printf("\n");
    printf("\t%d apartamentos tipo Basico\n", disponiblesBasicos);
    printf("\t%d apartamentos tipo Normal\n", disponiblesNormales);
    printf("\t%d apartamentos tipo Lujo\n\n", disponiblesLujosos);
}

// Función para reservar un apartamento en un edificio específico
void ReservarApartamento(ReservasEdificios reservas) {
    int EdificioID, duracionDias;
    TipoFecha fechaEntrada, fechaSalida;
    char tipoApartamento;
    char confirmacion;
    TipoApartamento tipoStr;
    bool encontrado = false;

    // Solicita detalles de la reserva
    printf("Reservar Apartamento:\n\n");
    printf("\tIdentificador de Edificio? ");
    scanf("%d", &EdificioID);
    if (EdificioID < 1 || EdificioID > MaximosEdificios || !reservas[EdificioID - 1].ExisteEdificio) {
        printf("Error: Edificio no válido o no existe.\n");
        return;
    }

    // Valida el tipo de apartamento
    printf("\tTipo de Apartamento (B-Básico/N-Normal/L-Lujo) ? ");
    scanf(" %c", &tipoApartamento);
    tipoApartamento = toupper(tipoApartamento);

    if (tipoApartamento == 'B') {
        strcpy(tipoStr, "Basico");
    } else if (tipoApartamento == 'N') {
        strcpy(tipoStr, "Normal");
    } else if (tipoApartamento == 'L') {
        strcpy(tipoStr, "Lujo");
    } else {
        printf("Tipo de apartamento inválido.\n");
        return;
    }

    // Solicita fecha de entrada y duración
    printf("\tFecha Entrada: Día? ");
    scanf("%d", &fechaEntrada.dia);
    printf("\tFecha Entrada: Mes? ");
    scanf("%d", &fechaEntrada.mes);
    printf("\tFecha Entrada: Año? ");
    scanf("%d", &fechaEntrada.anio);
    printf("\tDías de duración de la estancia? ");
    scanf("%d", &duracionDias);

    // Valida la fecha de entrada
    if (fechaEntrada.dia < 1 || fechaEntrada.dia > 31 || fechaEntrada.mes < 1 || fechaEntrada.mes > 12 || fechaEntrada.anio < 1601 || fechaEntrada.anio > 3000) {
        printf("Mes o anio invalidos. Intente nuevamente.\n");
        return;
    }

    if (duracionDias < 1){
        printf("Debe poner números positivos y > que 0");
    }

    // Calcula la fecha de salida considerando los días de estancia
    fechaSalida.dia = fechaEntrada.dia;
    fechaSalida.mes = fechaEntrada.mes;
    fechaSalida.anio = fechaEntrada.anio;

    for (int i = 0; i < duracionDias; i++) {
        fechaSalida.dia++;
        if (fechaSalida.dia > DiasMes(fechaSalida.mes, fechaSalida.anio)) {
            fechaSalida.dia = 1;
            fechaSalida.mes++;
            if (fechaSalida.mes > 12) {
                fechaSalida.mes = 1;
                fechaSalida.anio++;
            }
        }
    }

    for (int i = 0; i < MaximosApartamentos; i++) {
        if (!reservas[EdificioID - 1].Apartamentos[i].ocupado &&
            reservas[EdificioID - 1].Apartamentos[i].disponible &&
            strcmp(tipoStr, reservas[EdificioID - 1].Apartamentos[i].tipo) == 0) {

            // Genera una referencia única para la reserva
            sprintf(reservas[EdificioID - 1].Apartamentos[i].referencia, "APT%02d%c%02d", EdificioID, tipoApartamento, i + 1);

            // Presenta los detalles al usuario y solicita confirmación
            printf("\n");
            printf("\t\tDatos de la Reserva:\n");
            printf("\n");
            printf("\tEdificio: %s (Id = %d)\n", reservas[EdificioID - 1].nombre, EdificioID);
            printf("\tReferencia Apartamento: %s\n", reservas[EdificioID - 1].Apartamentos[i].referencia);
            printf("\tFecha Entrada: %d/%d/%d\n", fechaEntrada.dia, fechaEntrada.mes, fechaEntrada.anio);
            printf("\tDuración estancia: %d días\n", duracionDias);
            printf("\tFecha Salida: %d/%d/%d\n\n", fechaSalida.dia, fechaSalida.mes, fechaSalida.anio);
            printf("Es correcta la operación (S/N)? ");
            scanf(" %c", &confirmacion);
            confirmacion = toupper(confirmacion);
            if (confirmacion == 'S') {
                printf("\nReserva confirmada.\n\n");
                for (int j = 0; j < MaximasReservas; j++) {
                      if (!reservas[EdificioID - 1].Apartamentos[i].reservas[j].activo) {
                          reservas[EdificioID - 1].Apartamentos[i].reservas[j].diaInicio = fechaEntrada.dia;
                          reservas[EdificioID - 1].Apartamentos[i].reservas[j].mesInicio = fechaEntrada.mes;
                          reservas[EdificioID - 1].Apartamentos[i].reservas[j].anioInicio = fechaEntrada.anio;
                          reservas[EdificioID - 1].Apartamentos[i].reservas[j].duracionDias = duracionDias;
                          reservas[EdificioID - 1].Apartamentos[i].reservas[j].activo = true;
                          return;
                      }
                }
                reservas[EdificioID - 1].Apartamentos[i].ocupado = true;
                reservas[EdificioID - 1].Apartamentos[i].disponible = false;
                encontrado = true;
                return;
            } else {
                printf("\nReserva cancelada.\n\n");
                return;
            }
        }
    }

    // Si no se encuentra un apartamento adecuado
    if (!encontrado) {
        printf("\nNo hay apartamentos disponibles con las condiciones solicitadas.\n");
    }
}
