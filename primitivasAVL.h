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
				if((*p)->fe != 0)
					(*p)->fe ++;
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
				if((*p)->fe != 0)
					(*p)->fe --;
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
		if(((*p)->valor) < x && ((*p)->der->valor)%2 == 0 && ((*p)->der->fe) == 1)
		{
			eliminar(&(*p)->der, x, &(*inserta));
			if (*inserta == 1)
				(*p)->fe--;
		}
		else if ((*p)->valor > x && ((*p)->izq->valor)%2 == 0 && ((*p)->izq->fe) == 1)
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
			else if(!(t->izq) && ((*p)->valor)%2 == 0 && ((*p)->fe) == 1)
				(*p) = t->der;
			else if (!(t->der) && ((*p)->valor)%2 == 0 && ((*p)->fe) == 1)
				(*p) = t->izq;
			else if(((*p)->valor)%2 == 0 && ((*p)->fe) == 1)
				(*p)->valor = MDM(&((*p)->der),&t);

			if ((t->valor)%2 == 0 && (t->fe) == 1)
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
