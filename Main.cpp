# Arboles
ABB
#include <stdio.h>
#include <stdlib.h>
#include "primitivas.h"

void main()
{
	int op = -1, n = 0;
	nodo *p = NULL;

	while (op != 0) {
		system("cls");
		printf("\n\n                              Menu principal Arboles! \n\n\n");
		printf("\n 1. Insertar (x) en el arbol.");
		printf("\n 2. Buscar (x) en el arbol."); 
		printf("\n 3. Eliminar (x) del arbol.");
		printf("\n 4. Impresion preorden.");
		printf("\n 5. Impresion inorden."); 
		printf("\n 6. Imprimir por niveles.");
		printf("\n\n 0. Salir. \n\n");
		printf(" Indique opcion : ");
		op = 0;
		scanf("%i", &op);
		system("cls");
		printf("\n\n");
		switch (op)
		{
		case 1: printf("\n\n Indique el valor a ingresar : ");
			scanf("%i", &n);
			insertar(&p, n);
			break;

		 case 2: printf("\n\n Numero a buscar en el arbol:");
			scanf("%i", &n);
			buscar(p, n);
			break;

		 case 3: printf("\n\n Numero a eliminar del arbol :");
			 scanf("%i", &n);
			 eliminar(&p, n);
			 break;

		case 4: printf("\n\n Impresion Preorden \n\n ");
			preorden(p);
			break;

		case 5: printf("\n\n Impresion Inorden \n\n ");
			inorden(p);
			break;

		case 6: printf("\n\n Impresion por niveles \n\n ");
			break;
		}
		if (op)
		{
			printf("\n\n");
			system("pause");
			system("cls");
		}
	}
}
