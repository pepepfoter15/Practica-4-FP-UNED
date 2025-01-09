# Práctica 4 FP UNED 2024/2025

Practica 4 Fundamentos de Programación UNED 2024/2025. Desarollado en C+-. 

Realizar un programa en C+/- para Gestionar las Reservas de los Apartamentos de un Edificio (GesRAE). En cada edificio, los apartamentos pueden ser catalogados según sus prestaciones como Básico, Normal o de Lujo. Todos los apartamentos con las mismas prestaciones son equivalentes y será el programa el encargado de realizar la asignación concreta al realizar la reserva.  
El sistema GesRAE deberá tener las siguientes capacidades mínimas:
- Hasta 5 Edificios
- Hasta 20 Apartamentos por edificio

Las operaciones del programa serán las siguientes:
- Editar Edificio
- Listar Edificios
- Apartamentos Disponibles
- Reservar Apartamento
- Reservas Mensuales de Apartamento

Se trata de realizar el programa principal para la gestión de todos los edificios de apartamentos y las correspondientes funciones, procedimientos y los tipos abstractos de datos (TADs) que el alumno crea conveniente. En la realización de esta práctica se debe reutilizar, en la medida de lo posible, el código fuente ya realizado en la tercera, que se redefinirá como un TAD “CalendarioMes”, incorporando las operaciones nuevas para cumplir las necesidades de esta cuarta práctica.

## El programa principal deberá presentar las siguientes opciones:

### 1.- La opción “Editar Edificio” permite introducir los datos de uno de los 5 edificios. Esta opción debe avisar del previo borrado de todos los datos del edificio con ese mismo identificador.  
En el ejemplo, el nuevo edificio de nombre Apolo tendrá 8 apartamentos básicos, 5 apartamentos normales y 3 de lujo. El programa deberá comprobar que el número total de apartamentos no supera los 20 establecidos como tope para el programa.  
Cuando todos los tipos de apartamentos sean 0 o negativos, se dará de baja el edificio con el identificador introducido.  
GesRAE: Gestión de Reservas Apartamentos-Edificios  
- Editar Edificio (Pulsar E)  
- Listar Edificios (Pulsar L)  
- Apartamentos Disponibles (Pulsar A)  
- Reservar Apartamento (Pulsar R)  
- Reservas Mensuales Apartamento (Pulsar M)  
- Salir (Pulsar S)  

Teclear una opción válida (E|L|A|R|M|S)?  
**Editar Edificio:**  
- Identificador (número entre 1 y 5)? 3  
- Nombre (entre 1 y 20 caracteres)? Apolo  
- Número de Apartamentos Básicos? 8  
- Número de Apartamentos Normales? 5  
- Número de Apartamentos de Lujo? 3  
**IMPORTANTE:** Esta opción borra los datos anteriores.  
**Son correctos los nuevos datos (S/N)?** S  

### 2.- La opción “Listar Edificios” permite conocer todos los edificios gestionados con sus apartamentos. Esta opción tendrá el siguiente formato:  

Id  |  Nombre   | Aptos Básicos | Aptos Normales | Aptos de Lujo  
--- | --------- | ------------- | -------------- | -------------  
1   | Neptuno  | 3             | 12             | 2  
3   | Apolo    | 8             | 5              | 3  
4   | Zeus     | 9             | 6              | 5  
5   | Atenea   | 4             | 9              | 2  

En el ejemplo, se muestran los cuatro edificios gestionados y sus respectivos apartamentos según sus prestaciones.

### 3.- La opción “Apartamentos Disponibles” permite conocer los apartamentos de un edificio que estarían disponibles desde una fecha inicial con una duración de la estancia de los días solicitados. Esta opción tendrá el siguiente formato:  
En el ejemplo, la búsqueda de disponibilidad entre los 8 apartamentos posibles de tipo Básico es de 4, entre los 5 apartamentos posibles de tipo Normal es de 2 y no hay disponibilidad de ninguno de los 3 apartamentos de tipo Lujo para las fechas solicitadas.

**Apartamentos Disponibles:**  
- Identificador de Edificio? 3  
- Fecha Entrada: Día? 8  
- Fecha Entrada: Mes? 9  
- Fecha Entrada: Año? 2025  
- Días de duración de la estancia? 15  

El edificio Apolo desde el 8/9/2025 y 15 días de estancia, tendría disponibles:  
- 4 apartamentos tipo Básico  
- 2 apartamentos tipo Normal  
- 0 apartamentos tipo Lujo  

### 4.- La opción “Reservar Apartamento” permite hacer la reserva de un apartamento en un edificio para la fecha y duración introducidos. Esta opción tendrá el siguiente formato:  
En esta opción se tiene que comprobar que existe algún apartamento disponible con las condiciones solicitadas de tipo, fecha de entrada y duración de la estancia.  
Cuando no exista la disponibilidad, se deberá dar un mensaje indicándolo. Cuando exista más de un apartamento que cumpla las condiciones, el programa asignará uno de los apartamentos disponibles.  
La referencia del apartamento se forma por las letras APT seguidas de dos dígitos para designar el edificio, la letra B, N o L según el tipo Básico, Normal o Lujo y dos dígitos para designar el apartamento.  
En el ejemplo APT03N04 sería el apartamento del edificio Apolo (03), N de tipo Normal y el apartamento 4 de los 5 de tipo Normal que hay en el edificio.  
El programa asignará número de reserva de manera secuencial según se solicitan en el año de la fecha de inicio de la reserva. En el ejemplo 34/2025 se corresponde con la reserva 34 del año 2025.

**Reservar Apartamento:**  
- Identificador de Edificio? 3  
- Tipo de Apartamento (B-Básico/N-Normal/L-Lujo)? N  
- Fecha Entrada: Día? 8  
- Fecha Entrada: Mes? 9  
- Fecha Entrada: Año? 2025  
- Días de duración de la estancia? 15  

**Datos de la Reserva:**  
- Número de Reserva: 34/2025  
- Edificio: Apolo (Id = 3)  
- Referencia Apartamento: APT03N04  
- Fecha Entrada: 8/9/2025  
- Duración estancia: 15 días  
- Fecha Salida: 23/9/2025  
**Es correcta la operación (S/N)?** S  

### 5.- La opción de “Reservas Mensuales Apartamento” solicita la referencia del apartamento, el mes y el año del que se quiere las reservas y tendrá el siguiente formato:  

**Reservas Mensuales Apartamento:**  
- Referencia Apartamento? APT03N04  
- Selección Mes? 9  
- Selección Año? 2025  

**Estado Mensual Apartamento:** APT03N04  
- Edificio: Apolo  
- Septiembre 2025  

| L | M | X | J | V | S | D |  
|---|---|---|---|---|---|---|  
| Re | Re | Re | Re | Re | 06 | 07 |  
| Re | Re | Re | Re | Re | Re | Re |  
| Re | Re | Re | Re | Re | Re | Re |  
| Re | 23 | 24 | 25 | Re | Re | Re |  
| Re | Re |  

**Reserva 21/2025:** Fecha entrada 27/8/2025 y de 10 días  
**Reserva 34/2025:** Fecha entrada 8/9/2025 y de 15 días  
**Reserva 45/2025:** Fecha entrada 26/9/2025 y de 10 días  

**Total días reservados del mes:** 25 días  
**Total días libres del mes:** 5 días  

**Mostrar otro mes (S/N)?** N  

En el ejemplo, se muestra las reservas del mes de septiembre de 2025 para el apartamento APT03N04 del edificio Apolo. Los días reservados se muestran mediante un símbolo Re en el calendario. Después del calendario se detallan las reservas que afectan a algún día dentro del mes.
