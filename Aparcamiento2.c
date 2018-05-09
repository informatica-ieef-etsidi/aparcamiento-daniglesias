//Desarrollador: Daniel Iglesias Cuesta
//Practica 1
//Desarrollar un programa informático en C que gestione en esta primera práctica únicamente dos plazas de aparcamiento de un establecimiento.

#include <stdio.h>
#include <string.h>

void main() {
	char opcion;
	char motocoche[1];

	char matricula[8];
	char matricula1[8];
	char matricula2[8];
	char matriculaAux[8]; //Para Compararlo en el apartado de busqueda
	
	int salir = 1; //Para salir del programa tiene que ser != 1
	int mat1Coche = 0, mat2Moto = 0; //Si son = 0 entonces esta vacia la plaza
	
	int tipoVehiculo; //Si es 0 es coche si es 1 es moto
	int i = 0;

	while (salir == 1) {
		
		printf("\nSeleccione alguna de las siguientes opciones correspondientes al aparcamiento:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
		scanf_s("%c", &opcion);
		


		//Elegir una opcion
		switch (opcion) {

			//RESERVAR
		case 'R':
		case 'r':
			//Indicar si es coche o moto
			i = 1;
		do {
			printf("Indica que tipo de vehiculo quieres estacionar:\n Coche - C\n Moto - M\n");
			scanf_s("%s", motocoche, 8);
			if (motocoche[0] == 'c' || motocoche[0] == 'C') {
				printf("Has seleccionado coche\n");
				system("PAUSE");
				system("cls");

						//Reservar Matricula y sitio C
						if (mat1Coche == 0) {
							printf("\nSi quiere reservar una plaza debe indicarnos la matricula de su vehiculo:\n");
							scanf_s("%s", matricula1, 8);
							mat1Coche = 1;
							printf("Has reservado la plaza 1 con la matricula: %s\n", matricula1);
						}
				
						else {
							printf("La plaza esta ocupada, por favor, vuelva mas tarde. Perdone las molestias.\n");
						}
				tipoVehiculo = 0;
				i = 0;
			}
			else if (motocoche[0] == 'm' || motocoche[0] == 'M') {
				printf("Has seleccionado moto\n");
				system("PAUSE");
				system("cls");

						//Reservar Matricula y sitio M

						if (mat2Moto == 0) {
							printf("\nSi quiere reservar una plaza debe indicarnos la matricula de su vehiculo:\n");
							scanf_s("%s", matricula2, 8);
							mat2Moto = 1;
							printf("Has reservado la plaza 2 con la matricula: %s\n", matricula2);
						}
						else {
							printf("La plaza esta ocupada, por favor, vuelva mas tarde. Perdone las molestias.\n");
						}
				tipoVehiculo = 1;
				i = 0;
			}
			else {
				printf("Indique de nuevo el tipo de vehiculo que posee\n");
				i = 0;
			}
		} while (i = 0);
			
		break;

			//ABANDONAR
		case 'A':
		case 'a':

			printf("\nIndicanos la matricula del coche que aparcaste:\n");
			scanf_s("%s", matricula, 8);

			if (strcmp(matricula1, matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				mat1Coche = 0;
				printf("Acaba de abandonar la plaza 1.\n Gracias por la visita, esperemos verle de nuevo.\n");
			}

			else if (strcmp(matricula2, matricula) == 0) {
				mat2Moto = 0;
				printf("Acaba de abandonar la plaza 2.\n Gracias por la visita, esperemos verle de nuevo.\n");
			}
			else {
				printf("No existe ningun vehiculo con esta matricula.\n");
			}
		break;

			//ESTADO DEL APARCAMIENTO
		case 'E':
		case 'e':
			printf("El estado del aparcamiento es:\n");

			if (mat1Coche == 1) {
				printf("Plaza 1 de coche: Reservada (Matricula: %s)\n", matricula1, 8);
			}
			else {
				printf("Plaza 1 de coche: Vacia\n");
			}

			if (mat2Moto == 1) {
				printf("Plaza 2 de moto: Reservada (Matricula: %s)\n", matricula2, 8);
			}
			else {
				printf("Plaza 2 de moto: Vacia\n");
			}

		break;

			//BUSCAR EL VEHICULO POR MATRICULA

		case 'B':
		case 'b':
			printf("Indiquenos la matricula del coche que deseas buscar: ");
			scanf_s("%s", matriculaAux, 8);

			if (strcmp(matriculaAux, matricula1) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				printf("Su coche esta estacionado en la plaza 1\n");
			}
			else if (strcmp(matriculaAux, matricula2) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				printf("Su moto esta estacionada en la plaza 2\n");
			}
			else {
				printf("No hay ningun vehiculo con esta matricula en el aparcamiento\n");
			}
		break;

			//SALIR DEL PROGRAMA

		case 'S':
		case 's':
			printf("Has decidido salir del programa. Esperemos verle pronto (^_^)\n");
			
			salir = 0;
		
		break;
		default:
			printf("opcion incorrecta\n");
		}

		
		system("PAUSE");
		system("cls");
		getchar();
		
	}
}
