//Desarrollador: Daniel Iglesias Cuesta
//Practica 3
//Desarrollar un programa informático en C que gestione en esta primera práctica únicamente dos plazas de aparcamiento de un establecimiento.

#include <stdio.h>
#include <string.h>
#define NPLAZAS 2

struct plaza {
	int estado; //0 - Libre / 1 - Ocupada
	char tipo;  //M - moto /  C - Coche
	char matricula[8]; //Formato de la matricula NNNNLLL
};


void main() {

	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'M' };
	struct plaza plaza[NPLAZAS];

	char opcion;
	char motocoche[1];
	char matricula[8];
	char matricula1[8];
	char matricula2[8];
	char matriculaAux[8]; //Para Compararlo en el apartado de busqueda
	char usuario[50] = "admin", contrasena[50] = "1234", usuario1[50], contrasena1[50];

	int salir = 1; //Para salir del programa tiene que ser != 1
	int mat1Coche = 0, mat2Moto = 0; //Si son = 0 entonces esta vacia la plaza
	int tipoVehiculo; //Si es 0 es coche si es 1 es moto
	int i = 0;
	int comparacion1 = 0, comparacion2 = 0;


	while (i < 3) {

		printf("intoduzca el nombre de usuario:\n");

		gets(usuario1);

		printf("introduzca la contrasena:\n");

		gets(contrasena1);



		comparacion1 = strcmp(usuario1, usuario);

		comparacion2 = strcmp(contrasena1, contrasena);



		if (comparacion1 == 0 && comparacion2 == 0) {

			opcion = 'R';

			break;

		}

		else {

			printf("usuario o contrasena incorrectas.\n");

			i++;

			opcion = 'S';

			system("pause");

			system("cls");

		}

	}

	for (i = 0; i < NPLAZAS; i++) {

		plaza[i].estado = 0;

	}



	i = 0;

	while (opcion != 'S' && opcion != 's') {

		printf("\nSeleccione alguna de las siguientes opciones correspondientes al aparcamiento:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
		scanf_s("%c", &opcion);



		//Elegir una opcion
		switch (opcion) {

			//RESERVAR
		case 'R':
		case 'r':
			//Indicar si es coche o moto
			printf("Indica que tipo de vehiculo quieres estacionar:\n Coche - C\n Moto - M\n");
			gets(plaza1.tipo);
			if (plaza1.estado == 0 && plaza2.estado == 0) {
				if (plaza1.tipo == 'c' || plaza1.tipo == 'C') {
					plaza1.tipo = "C";
					printf("Has seleccionado coche\n");
					system("PAUSE");
					system("cls");
				}
				else if (plaza1.tipo == 'm' || plaza1.tipo == 'M') {
					plaza1.tipo = "M";
					printf("Has seleccionado moto\n");
					system("PAUSE");
					system("cls");
				}


				//Reservar Matricula plaza 1
				if (plaza1.estado == 0) {
					printf("\nSi quiere reservar la plaza1 debe indicarnos la matricula de su vehiculo:\n");
					scanf_s("%s", plaza1.matricula, 8);
					printf("Has reservado la plaza 1 con la matricula: %s\n", plaza1.matricula);
					plaza1.estado = 1;
				}
				else if (plaza2.estado == 0) {
					printf("\nSi quiere reservar la plaza2 debe indicarnos la matricula de su vehiculo:\n");
					scanf_s("%s", plaza2.matricula, 8);
					printf("Has reservado la plaza 2 con la matricula: %s\n", plaza2.matricula);
					plaza2.estado = 1;
				}

			}
			else {
				printf("Las plazas estan ocupadas, por favor, vuelva mas tarde. Perdone las molestias.\n");
			}
			break;

			//ABANDONAR
		case 'A':
		case 'a':

			printf("\nIndicanos la matricula del coche que aparcaste:\n");
			scanf_s("%s", matricula, 8);

			if (strcmp(plaza1.matricula, matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0

				printf("Acaba de abandonar la plaza 1.\n Gracias por la visita, esperemos verle de nuevo.\n");
				plaza1.estado = 0;
			}

			else if (strcmp(plaza2.matricula, matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0

				printf("Acaba de abandonar la plaza 2.\n Gracias por la visita, esperemos verle de nuevo.\n");
				plaza2.estado = 0;
			}
			else {
				printf("No existe ningun vehiculo con esta matricula.\n");
			}
			break;

			//ESTADO DEL APARCAMIENTO
		case 'E':
		case 'e':
			printf("El estado del aparcamiento es:\n");

			if (plaza1.estado == 1) {
				printf("Plaza 1: Reservada (%c - %s)\n", plaza1.tipo, plaza1.matricula, 8);
			}
			else {
				printf("Plaza 1: Vacia\n");
			}

			if (plaza2.estado == 1) {
				printf("Plaza 2: Reservada (%c - %s)\n", plaza2.tipo, plaza2.matricula, 8);
			}
			else {
				printf("Plaza 2: Vacia\n");
			}

			break;

			//BUSCAR EL VEHICULO POR MATRICULA

		case 'B':
		case 'b':
			printf("Indiquenos la matricula del coche que deseas buscar: ");
			scanf_s("%s", matriculaAux, 8);

			if (strcmp(matriculaAux, plaza1.matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				printf("Su vehiculo esta estacionado en la plaza 1\n");
			}
			else if (strcmp(matriculaAux, plaza2.matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				printf("Su vehiculo esta estacionado en la plaza 2\n");
			}
			else {
				printf("No hay ningun vehiculo con esta matricula en el aparcamiento\n");
			}
			break;

			//SALIR DEL PROGRAMA

		case 'S':
		case 's':
			printf("Has decidido salir del programa. Esperemos verle pronto (^_^)\n");
			opcion = "s";
			salir = 0;
			return;

			break;
		default:
			printf("opcion incorrecta\n");
		}


		system("PAUSE");
		system("cls");

	}
}

