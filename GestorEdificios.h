#pragma once

// Declaración de las constantes que voy a emplear para los distintos tipos.
const int MaximasReservas = 100;
const int MaximosApartamentos = 20;
const int MaximosEdificios = 5;

// Declaración de los tipos
typedef char TipoNombreEdificio[31];

typedef char TipoReferencias[20];

typedef char TipoApartamento[20];

typedef struct TipoReserva {
    int diaInicio;
    int mesInicio;
    int anioInicio;
    int duracionDias;
    int diaFin;
    int mes;
    int anio;
    bool activo;
};


typedef struct Apartamento {
    int id;
    TipoApartamento tipo; // Básico, Normal, Lujo
    bool disponible;
    TipoReferencias referencia;
    TipoReserva reservas[MaximasReservas];
    bool ocupado;
};

typedef struct TipoEdificio {
    int id;
    TipoNombreEdificio nombre;
    int ApartamentosBasicos;
    int ApartamentosNormales;
    int ApartamentosLujosos;
    Apartamento Apartamentos[MaximosApartamentos];
    bool ExisteEdificio;
};

typedef struct TipoFecha {
    int dia;
    int mes;
    int anio;
};

typedef TipoEdificio Edificios[MaximosEdificios];

typedef TipoEdificio ReservasEdificios[MaximosEdificios];

// Declaración de las funciones de la cabecera
void InicializarEdificios(Edificios edificios);
void InicializarReservas(Edificios edificios, ReservasEdificios reservas);
void ListarEdificios(Edificios edificios);
void EditarEdificio(Edificios edificios, ReservasEdificios reservas);

