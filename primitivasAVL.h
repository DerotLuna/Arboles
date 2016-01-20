# Arboles
AVL
struct nodo
{
	int valor, fe;
	nodo *izq, *der;
};

nodo *crear (int x)
{
	nodo *t = new nodo;
	t->valor = x;
	t->izq = NULL;
	t->der = t->izq;
	t->fe = 0;
	return t;
}

void insertar (nodo **p, int x, int *inserta)
{
	if (!(*p))
	{
		*p = crear(x);
		*inserta = 1;
	}
	else 
		if ((*p)->valor < x)
		{
			insertar(&((*p)->der), x, &(*inserta));
			if ((*p)->der && (*p)->izq)
			{
				(*p)->fe = 0;
				*inserta = 0;
			}
			if (*inserta == 1)
				(*p)->fe++;

		}
		else if ((*p)->valor > x)
		{
			insertar(&((*p)->izq), x, &(*inserta));
			if ((*p)->der && (*p)->izq)
			{
				(*p)->fe = 0;
				*inserta = 0;
			}
			if (*inserta == 1)
				(*p)->fe--;
	
		}
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

void eliminar(nodo **p, int x, int *inserta)
{
	if (*p)
	{
		if(((*p)->valor) < x)
		{
			eliminar(&(*p)->der, x, &(*inserta));
			if (*inserta == 1)
				(*p)->fe--;
		}
		else if ((*p)->valor > x)
		{
			eliminar(&((*p)->izq), x, &(*inserta));
			if (*inserta == 1)
				(*p)->fe++;
		}
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
		printf("[%i, %i] ", p->valor, p->fe);
		preorden(p->izq);
		preorden(p->der);
	}
}
