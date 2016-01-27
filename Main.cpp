#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void main() {
	int  op = -1, n = 0;
	nodo *p = NULL;
	while (op != 0) {
		system("cls");
		printf("\n\n                                 Menu Principal \n");
		printf("\n 1. Insertar. \n");
		printf("\n 2. Mostrar en Preorden. \n");
		printf("\n 3. Borrar. \n");
		printf( "\n 4. Muestra la cuenta de : todos sus nodos, sus  internos y sus hojas. \n\n");
		printf(" Salir : 0 \n\n");
		printf("Indique opcion (1-4)");
		op = 0;
		scanf("%i", &op);
		system("cls");
		printf("\n\n");
		switch (op) {
		case 1: printf("\n\n1. Insertar un elemento \n\n");
			printf("numero a insertar =");
			scanf("%i", &n);
			insertar(&p, n);
			break;
		case 2: printf("\n\n2. Mostrar en PREorden\n\n ");
			preorden(p);
			break;
		case 3: printf("\n\n3. Eliminar un dato \n\n ");
			printf("numero a eliminar =");
			scanf("%i", &n);
			eliminar(&p, n);
			break;
		case 4: printf("%i [Todos], %i [Internos], %i [Hijos]", contar(p), internos(p), hojas(p));
			break;
		}
		if (op) {
			printf("\n\n");
			system("pause");
			system("cls");
		}
	}
}
