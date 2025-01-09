#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "CalendarioMes.h"

// Función para determinar si un año es bisiesto
bool LeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    return false;
}

// Función que devuelve el número de días de un mes en un año específico
int DiasMes(int month, int year) {
    // Los meses con 31 días
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    // Febrero, teniendo en cuenta si el año es bisiesto o no
    } else if (month == 2) {
        if (LeapYear(year)) {
            return 29; // Año bisiesto
        }
        return 28; // Año no bisiesto
    }
    return 30; // El resto de meses con 30 días
}

// Función de Zeller para calcular el día de la semana para una fecha dada
int zeller(int year, int month) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    // Fórmula de Zeller para determinar el día de la semana
    int d = ((1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) - 1) % 7;
    return d;
}

// Función para mostrar el calendario de un mes específico en un formato legible
void SeleccionarMes(int month, int year) {
    printf("\t     ");
    // Dependiendo del mes, imprime su nombre con un formato ajustado, además alineo el mes y año con el formato de la practica
    switch (month) {
        case 1:
            printf("ENERO");
            for (int x = 1; x < 19; x++) {
                printf(" ");
            }
            break;
        case 2:
            printf("FEBRERO");
            for (int x = 1; x < 17; x++) {
                printf(" ");
            }
            break;
        case 3:
            printf("MARZO");
            for (int x = 1; x < 19; x++) {
                printf(" ");
            }
            break;
        case 4:
            printf("ABRIL");
            for (int x = 1; x < 19; x++) {
                printf(" ");
            }
            break;
        case 5:
            printf("MAYO");
            for (int x = 1; x < 20; x++) {
                printf(" ");
            }
            break;
        case 6:
            printf("JUNIO");
            for (int x = 1; x < 19; x++) {
                printf(" ");
            }
            break;
        case 7:
            printf("JULIO");
            for (int x = 1; x < 19; x++) {
                printf(" ");
            }
            break;
        case 8:
            printf("AGOSTO");
            for (int x = 1; x < 18; x++) {
                printf(" ");
            }
            break;
        case 9:
            printf("SEPTIEMBRE");
            for (int x = 1; x < 14; x++) {
                printf(" ");
            }
            break;
        case 10:
            printf("OCTUBRE");
            for (int x = 1; x < 17; x++) {
                printf(" ");
            }
            break;
        case 11:
            printf("NOVIEMBRE");
            for (int x = 1; x < 15; x++) {
                printf(" ");
            }
            break;
        case 12:
            printf("DICIEMBRE");
            for (int x = 1; x < 15; x++) {
                printf(" ");
            }
            break;
    }
    printf("%i\n", year);
    printf("\n\t      L   M   X   J   V   S   D\n");
    printf("\t     ");
    for (int x = 1; x < 28; x++) {
        printf("-");
    }
    printf("\n\n");
}

// Función para realizar una reserva mensual de un apartamento
void ReservarApartamentoMes(ReservasEdificios reservas) {
    TipoFecha fechaInicio;
    TipoReferencias referencia;

    int year, month, diames;
    int Barra = 4;
    int SaltoLinea = 1;
    int TotalDigitos = 1;
    bool encontrado = false;
    char continuar = 'S';
    int diasReservados = 0;
    int diasLibres = 0;
    bool diaOcupado;
    int diasReserva = 0;
    int numeroReserva = 1;

    printf("Reservas Mensuales Apartamento:\n");
    printf("Referencia Apartamento ? ");
    scanf("%s", referencia);

    // Solicita mes y año para mostrar el calendario
    printf("Seleccion Mes? ");
    scanf("%d", &month);

    printf("Seleccion Anio? ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1601 || year > 3000) {
        printf("Mes o anio invalidos. Intente nuevamente.\n");
        return;
    }

    // Busca el apartamento con la referencia proporcionada
    for (int i = 0; i < MaximosEdificios && !encontrado; i++) {
        for (int j = 0; j < MaximosApartamentos; j++) {
            if (strcmp(reservas[i].Apartamentos[j].referencia, referencia) == 0) {
                encontrado = true;
                printf("\n\tEstado Mensual Apartamento: %s\n", referencia);
                printf("\t\t    Edificio: %s\n\n", reservas[i].nombre);

                // Muestra el calendario del mes seleccionado
                SeleccionarMes(month, year);
                diames = DiasMes(month, year);

                // Imprime los días del mes comenzando desde el primer día de la semana
                printf("\t     ");
                for (int PrimerDia = zeller(year, month); PrimerDia >= 1; PrimerDia--) {
                    printf("   ");
                    SaltoLinea++;
                    TotalDigitos++;
                    printf(" ");
                }

                    // Imprime los días del mes
                    for (int day = 1; day <= diames; day++) {
                        diaOcupado = false;
                        // Verificar si el día está ocupado por alguna reserva
                        for (int k = 0; k < MaximosEdificios; k++) {
                            for (int l = 0; l < MaximosApartamentos; l++) {
                                for (int m = 0; m < MaximasReservas; m++) {
                                    if (reservas[k].Apartamentos[l].reservas[m].activo) {
                                        fechaInicio.dia = reservas[k].Apartamentos[l].reservas[m].diaInicio;
                                        fechaInicio.mes = reservas[k].Apartamentos[l].reservas[m].mesInicio;
                                        fechaInicio.anio = reservas[k].Apartamentos[l].reservas[m].anioInicio;
                                        diasReserva = reservas[k].Apartamentos[l].reservas[m].duracionDias;
                                        // Si el día está dentro de la reserva, marcar como ocupado
                                        if ((fechaInicio.mes == month && fechaInicio.anio == year && day >= fechaInicio.dia && day < fechaInicio.dia + diasReserva)) {
                                            diaOcupado = true;
                                            diasReservados++;
                                            printf("Re ");
                                            // Mostrar la información de la reserva aquí
                                            numeroReserva++;
                                        }
                                    }
                                }
                            }
                        }
                        if (day < 10 && !diaOcupado) {
                            printf(" ");
                        }

                        if (!diaOcupado) {
                            printf("%i ", day);
                            diasLibres++;
                        }

                        printf(" ");
                        if (SaltoLinea % 7 == 0) {
                            printf("\n\t     ");
                        }
                        SaltoLinea++;
                        TotalDigitos++;
                    }

                // Rellenar los espacios restantes de la semana para que el calendario sea consistente
                for (int DigitosRestantes = 7 - ((TotalDigitos - 1) % 7); DigitosRestantes >= 1; DigitosRestantes--) {
                    if ((TotalDigitos - 1) % 7 == 0) {
                        printf("\n");
                        return;
                    }
                    printf("   ");
                    printf(" ");
                    if (SaltoLinea % 7 == 0) {
                        printf("\n");
                    }
                    SaltoLinea++;
                }

                printf("\n");
                numeroReserva = 1;
                // Mostrar resumen de las reservas en el mes
                for (int k = 0; k < MaximosEdificios; k++) {
                    for (int l = 0; l < MaximosApartamentos; l++) {
                        for (int m = 0; m < MaximasReservas; m++) {
                            if (reservas[k].Apartamentos[l].reservas[m].activo) {
                                fechaInicio.dia = reservas[k].Apartamentos[l].reservas[m].diaInicio;
                                fechaInicio.mes = reservas[k].Apartamentos[l].reservas[m].mesInicio;
                                fechaInicio.anio = reservas[k].Apartamentos[l].reservas[m].anioInicio;
                                diasReserva = reservas[k].Apartamentos[l].reservas[m].duracionDias;
                                if (fechaInicio.mes == month && fechaInicio.anio == year) {
                                    printf("Reserva %02d/%d: Fecha entrada %d/%d/%d y de %d días\n", numeroReserva, year, fechaInicio.dia, fechaInicio.mes, fechaInicio.anio, diasReserva);
                                    numeroReserva ++;
                                }
                            }
                        }
                    }
                }
                printf("Total días reservados del mes: %d días\n", diasReservados);
                printf("Total días libres del mes: %d días\n\n", diasLibres);
            }
        }
    }
    // Si no se encuentra la referencia del apartamento, solicita de nuevo la entrada
    if (!encontrado) {
        printf("\n");
        printf("Referencia no encontrada. Intente nuevamente.\n");
        printf("\n");
    }

    printf("Mostrar otro mes (S/N)? ");
    scanf(" %c", &continuar);
    continuar = toupper(continuar);

    if (continuar == 'S'){
      ReservarApartamentoMes(reservas);
    } else if (continuar != 'S'){
        printf("Consulta finalizada.");
    }
}
