#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valor;
	nodo *izq, *der;
};

int contar(nodo *p)
{
	if (p)
		return 1 + contar(p->izq) + contar(p->der);
	return 0;
}

int hojas(nodo *p)
{
	if (p)
		if (!(p->izq) && !(p->der))
			return 1;
		else 
			return hojas(p->izq) + hojas(p->der);
	return 0;
}

int internos(nodo *p)
{
	if (p)
		if ((p->izq) && (p->der))
			return 1 + internos(p->izq) + internos(p->der);
		else
			return 0;
}

nodo *crear(int x) {
	nodo *t = new nodo;
	t->valor = x;
	t->izq = NULL,
		t->der = t->izq;
	return t;
};

void insertar(nodo **p, int x) {
	/* Inserta x en un arbol binario de busqueda  */
	if (!(*p))
		(*p) = crear(x);
	else
		if ((*p)->valor < x)
			insertar(&((*p)->der), x);
		else if ((*p)->valor > x)
			insertar(&((*p)->izq), x);
		else
			printf("\n\nNo se aceptan claves repetidas ... \n\n");
};

void preorden(nodo *p) {

	if (p) {
		printf("[%i]->", p->valor);
		preorden(p->izq);
		preorden(p->der);
	}
};
int menordemayores(nodo **p, nodo **t) {
	if ((*p)->izq)
		return menordemayores(&((*p)->izq), t);
	else {
		*t = *p;
		(*p) = (*p)->der;
		return (*t)->valor;
	}
}

void eliminar(nodo **p, int x) {
	if (*p)
		if ((*p)->valor < x)
			eliminar(&((*p)->der), x);
		else if ((*p)->valor > x)
			eliminar(&((*p)->izq), x);
		else { /* estamos en el nodo a eliminar */
			nodo *t = *p;
			if ((!(t->izq)) && (!(t->der)))
				*p = NULL;
			else if (!(t->izq))
				*p = (*p)->der;
			else if (!(t->der))
				*p = (*p)->izq;
			else
				(*p)->valor = menordemayores(&((*p)->der), &t);
			delete t;
		}
}

