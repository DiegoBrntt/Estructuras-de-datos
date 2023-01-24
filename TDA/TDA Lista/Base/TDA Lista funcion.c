#include<stdio.h>
#include<stdlib.h>



typedef struct Nodo
{
    int info;
    struct Nodo * sig;
} nodo;

typedef struct Lista
{
    nodo *p;
    nodo *u;
} lista;

void inicializar(lista*);
void Altafr(lista*, int);
void Altafn(lista*, int);
void Emitir(lista *);
void Borrar(lista *, int);
void bajaFrente(lista *);
void bajaFin(lista *);


int main()
{

    lista list;
    int opcion = 0, dato, pos;

    inicializar(&list);

    do
    {
        printf("\n|-------------------------------------|\n");
        printf("\n|      *  LISTA LIGADA SIMPLE  *      |\n");
        printf("\n|------------------|------------------|\n");
        printf("\n| 1. Alta Frente   | 5. Baja Frente   |\n");
        printf("\n| 2. Alta Final    | 6. Baja Final    |\n");
        printf("\n| 3. Buscar        | 7. Recorrer      |\n");
        printf("\n| 4. Modificar     | 8. Salir         |\n");
        printf("\n|------------------|------------------|\n");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\nIngrese un valor para dar de alta al frente, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                Altafr(&list, dato);

                printf("\n\nIngrese un valor para dar de alta al frente, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 2:
            printf("\n\nIngrese un valor para dar de alta al final, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                Altafn(&list, dato);

                printf("\n\nIngrese un valor para dar de alta al final, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 3:
            printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

                //buscar(&list, dato);

            };

            break;
        case 4:
            printf("\n\nIngrese dato a buscar para modificar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                //modificar(&list, dato);

                printf("\n\nIngrese dato a buscar para modificar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

            };

            break;
        case 5:
            bajaFrente(&list);
            break;
        case 6:
            bajaFin(&list);
            break;
        case 7:
            printf("\n\nRecorremos la lista:\n");
            Emitir(&list);
            break;
        case 8:
            printf("\n\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");

        }
    }
    while(opcion != 8);


    return 0;
}

void inicializar(lista * Lista)
{
    Lista->p = NULL;
    Lista->u = NULL;
}

void Altafr(lista * Lista, int dato)
{
    nodo * aux;
    aux = (nodo*)malloc(sizeof(nodo));

    if(Lista->p == NULL)
        {
            aux->info = dato;
            aux->sig = Lista->p;
            Lista->u = aux;
            Lista->p = aux;
        }
    else
        {
            aux->info = dato;
            aux->sig = Lista->p;
            Lista->p = aux;
        }

}

void Emitir(lista * l)
{
    nodo* actual = l->p;

    if(l->p != NULL)
    {
          do
          {
              printf("\n%d\n", actual->info);
              actual = actual->sig;
          }while(actual != NULL);
    }
    else
    {
         printf("\nEsta lista se encuentra vacia.\n");
    }
}

void Altafn(lista* Lista, int dato)
{
    nodo * aux;

    if(Lista->u == NULL)
    {
        Lista->p = (nodo*)malloc(sizeof(nodo));
        Lista->p->info = dato;
        Lista->p->sig = NULL;
        Lista->u = Lista->p;
    }
    else
    {
        aux = Lista->u;

        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = (nodo*)malloc(sizeof(nodo));
        aux = aux->sig;
        aux->info = dato;
        aux->sig = NULL;
    }
}
void bajaFrente(lista* l)
{
    nodo* actual = l->p;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->p != NULL)
    {
        l->p = l->p->sig;

        anterior = actual;
        actual = actual->sig;

        free(anterior);

        printf("\nSe ha dado una baja  correctamente.\n");

    }
    else
    {
        printf("\nPila inexistente.\n");
    }
}



void bajaFin(lista* l)
{
    nodo* actual = l->p;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->p != NULL)
    {
        while(actual != NULL)
            {
                anterior->sig = NULL;

                l->u = anterior;

                anterior = actual;

			    actual = actual->sig;
            }

            free(anterior);

    }
    else
    {
        printf("\n La cola no existe\n\n");
    }
}

