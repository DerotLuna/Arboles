# Arboles
ABB
struct nodo
{
	int valor;
	nodo *izq, *der;
};

nodo *crear (int x)
{
	nodo *t = new nodo;
	t->valor = x;
	t->izq = NULL;
	t->der = t->izq;
	return t;
}

void insertar (nodo **p, int x)
{
	if (!(*p))
		*p = crear(x);
	else if ((*p)->valor < x)
		insertar(&((*p)->der), x);
	else if ((*p)->valor > x)
		insertar(&((*p)->izq), x);
	else 
		printf("\n\n Los numeros no se deben repetir!");
}

int buscar(nodo *p, int x)
{
	if(p)
		if (p->valor < x)
			return buscar(p->der, x);
		else if (p->valor > x)
			return buscar(p->izq, x);
		else
			return 1;
		return 0;
}

int MDM(nodo **p, nodo **t)
{	
	if((*p)->izq)
		return MDM(&((*p)->izq), t);
	else
	{
		(*t) = (*p);
		(*p) = (*p)->der;
		return ((*t)->valor);
	}
}

void eliminar(nodo **p, int x)
{
	if (*p)
	{
		if(((*p)->valor) < x)
			eliminar(&(*p)->der, x);
		else if ((*p)->valor > x)
			eliminar(&((*p)->izq), x);
		else	// se esta en el nodo a eliminar
		{	
			nodo *t = (*p);
			if((!(t->izq) && !(t)->der))
				(*p) = NULL;
			else if(!(t->izq))
				(*p) = t->der;
			else if (!(t->der))
				(*p) = t->izq;
			else 
				(*p)->valor = MDM(&((*p)->der),&t);
 			delete t;
		}
	}	
}

void preorden(nodo *p)
{	
	if(p)
	{
		printf("%i ", p->valor);
		preorden(p->izq);
		preorden(p->der);
	}
}	

void inorden(nodo *p)
{	
	if(p)
	{
		inorden(p->izq);
		printf("%i ", p->valor);
		inorden(p->der);
	}
}

void niveles(nodo*p)
{

}
