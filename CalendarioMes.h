#pragma once

#include "GestorEdificios.h"
#include "GestorReservas.h"

// Declaración de las funciones de la cabecera

// Esta función se pasa para poder saber el día de salida según el mes y el año por si pasa a uno superior
int DiasMes(int month, int year);

void ReservarApartamentoMes(ReservasEdificios reservas);
