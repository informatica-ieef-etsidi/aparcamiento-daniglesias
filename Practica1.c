//Desarrollador: Daniel Iglesias Cuesta
//Practica 1
//Desarrollar un programa informático en C que gestione en esta primera práctica únicamente dos plazas de aparcamiento de un establecimiento.

#include <stdio.h>
#include<string.h>
void main() {
	char opcion;

	char matricula[8];
	char matricula1[8];
	char matricula2[8];

	char mat1 = 2, mat2 = 2;

	int i = 0;
	//int plaza1 = 0, plaza2 = 0;

	for (i = 0; i >= 0; i++) {
		system("cls");
	printf("\nSeleccione alguna de las siguientes opciones correspondientes al aparcamiento:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\n");
	scanf_s("%c", &opcion);



	system("cls");


		switch (opcion) {

			//RESERVADO
		case 'R':
		case 'r':

			if (mat1 == 2) {
				printf("\nSi quiere reservar una plaza debe indicarnos la matricula de su automovil:\n");
				scanf_s("%s", matricula1, 8);
				mat1 = 1;
				printf("Has reservado la plaza 1 con la matricula: %s\n", matricula1);

			}
			else if (mat2 == 2) {
				printf("\nSi quiere reservar una plaza debe indicarnos la matricula de su automovil:\n");
				scanf_s("%s", matricula2, 8);
				mat2 = 1;
				printf("Has reservado la plaza 2 con la matricula: %s\n", matricula2);

			}
			else {
				printf("Ambas plazas estan ocupadas, por favor, vuelva mas tarde y perdone las molestias.\n");
			}
			break;




			//ABANDONAR
		case 'A':
		case 'a':
						

			printf("\nIndicanos la matricula del coche que aparcaste:\n");
			scanf_s("%s", matricula, 8);

			

			if (strcmp(matricula1, matricula) == 0) {			//esto hace y compara las dos variables y si son iguales pone 0
				
				matricula1 == 2;
				printf("Acaba de abandonar la plaza 1.\n Gracias por la visita, esperemos verle de nuevo.\n");
			}

			if (strcmp(matricula2, matricula) == 0) {			

				matricula2 == 2;
				printf("Acaba de abandonar la plaza 2.\n Gracias por la visita, esperemos verle de nuevo.\n");
			}

		break;

			//ESTADO DEL APARCAMIENTO
		case 'E':
		case 'e':
			printf("El estado del aparcamiento es:\n");

			if (mat1 == 1) {
				printf("Plaza 1: Reservada (Matricula: %s)\n", matricula1, 8);
			}
			else {
				printf("Plaza 1: Vacia\n");
			}


			if (mat2 == 1) {
				printf("Plaza 2: Reservada (Matricula: %s)\n", matricula2, 8);
			}
			else {
				printf("Plaza 2: Vacia\n");
			}


		break;
		}


		system("PAUSE");

	}
}
