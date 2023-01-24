#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo
{
    int dat;
    struct Nodo * sig;
} nodo;

typedef struct Lista
{
    nodo *pri;
    nodo *ult;
} listaC;


void crear(listaC*);
void destruir(listaC*);
void altaFrnt(listaC*, int);
void altaFin(listaC*, int);
void borrar(listaC*, int);
void recorrer(listaC);
void buscar(listaC*, int);
void bajaFin(listaC*);
void bajaFrnt(listaC*);

int main()
{
    listaC circ;
    int opcion = -1, dato, pos;



    do
    {
        printf("\n|-------------------------------------|");
        printf("\n|      *  Lista Circular Simple  *    |");
        printf("\n|------------------|------------------|");
        printf("\n| 1. Crear lista   | 6. Recorrer      |");
        printf("\n| 2. Alta Frente   | 7. Buscar        |");
        printf("\n| 3. Alta Final    | 8. Borrar dato   |");
        printf("\n| 4. Baja Frente   | 9. Destruir      |");
        printf("\n| 5. Baja Final    | 0. Salir         |");
        printf("\n|------------------|------------------|");
        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\nIngrese un valor para dar de alta, o -1 para finalizar:\n");
            crear(&circ);
            break;
        case 2:
            printf("\n\nIngrese dato para dar de alta al frente, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                altaFrnt(&circ, dato);

                printf("\n\nIngrese dato para dar de alta al frente, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);
            }

            break;
        case 3:
            printf("\n\nIngrese dato para dar de alta al final, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                altaFin(&circ, dato);

                printf("\n\nIngrese dato para dar de alta al final, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);
            }

            break;
        case 4:
            printf("\nRealizando una baja al frente...\n");
            bajaFrnt(&circ);
            break;
        case 5:
            printf("\nRealizando una baja al frente...\n");
            bajaFin(&circ);
            break;
        case 6:
            printf("\n\nRecorremos la lista:\n");
            recorrer(circ);
            break;
        case 7:
            printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                buscar(&circ, dato);

                printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);
            }

            break;
        case 8:
            printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                borrar(&circ, dato);

                printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

            }
            break;
        case 9:
            printf("\nDestruyendo Lista...\n");
            destruir(&circ);
            break;
        case 0:
            printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");

        }
    }
    while(opcion != 0);

    return 0;
}


void crear(listaC *l)
{
    l->pri = NULL;
    l->ult = NULL;
    printf("\nLista Circular creada con exito.\n");
}

void altaFrnt(listaC *l, int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dat = dato;

    if(l->pri == NULL)
    {
        l->pri = nuevo;
        l->pri->sig = l->pri;
        l->ult = l->pri;
    }
    else
    {
        nuevo->sig = l->pri;
        l->pri = nuevo;
        l->ult->sig = l->pri;
    }
}

void altaFin(listaC *l, int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dat = dato;

    if(l->pri == NULL)
    {
        l->pri = nuevo;
        l->pri->sig = l->pri;
        l->ult = l->pri;
    }
    else
    {
        l->ult->sig = nuevo;
        nuevo->sig = l->pri;
        l->ult = nuevo;
    }
}

void recorrer(listaC l)
{
    nodo* actual = l.pri;

    if(l.pri != NULL)
    {
        do
        {
            printf("\n%d\n", actual->dat);
            actual = actual->sig;
        }
        while(actual != l.pri);
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}

void destruir(listaC* l)
{
    nodo* actual = l->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->pri != NULL)
    {
        do
        {
            if(l->pri != l->ult)
            {
                anterior = actual;
                actual = actual->sig;
                free(anterior);
            }
            else
            {
                l->pri = actual;
                l->ult = actual;
                free(anterior);
                free(actual);
            }

        }
        while(actual != l->pri);
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}
void buscar(listaC* l, int nodoBusc)
{
    bool encontrado = false;
    nodo* actual = l->pri;

    if(l->pri != NULL)
    {
        do
        {
            if(actual->dat == nodoBusc)
            {
                printf("\nNodo con el dato (%d) encontrado.\n", nodoBusc);
                encontrado = true;
            }

            actual = actual->sig;

        }
        while(actual != l->pri && encontrado != true);

        if(encontrado == false)
        {
            printf("\nDato no encontrado.\n");
        }
    }
    else
    {
        printf("'nEsta lista se encuentra vacia.\n");
    }
}

void bajaFin(listaC* l)
{
    nodo* actual = l->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->pri != NULL)
    {
        while(actual != l->ult)
        {
            anterior = actual;
            actual = actual->sig;
        }
        if(l->pri != l->ult)
        {
            anterior->sig = l->pri;
            l->ult = anterior;
            anterior = actual;
            actual = actual->sig;
            free(anterior);
        }
        else
        {
            l->pri = anterior;
            l->ult = anterior;
            free(anterior);
            free(actual);
        }

        printf("\nBaja al final realizada satisfactoriamente.\n");

    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}

void borrar(listaC* l, int nodoBusc)
{
    bool encontrado = false;
    nodo* actual = l->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->pri != NULL)
    {
        do
        {
            if(actual->dat == nodoBusc)
            {
                printf("\nNodo con el dato (%d) encontrado.\n", nodoBusc);

                if(actual == l->pri)
                {
                    l->pri = l->pri->sig;
                    l->ult->sig = l->pri;
                }
                else if (actual == l->ult)
                {
                    anterior->sig = l->pri;
                    l->ult = anterior;
                }
                else
                {
                    anterior->sig = actual->sig;
                }


                encontrado = true;
            }

            actual = actual->sig;

        }
        while(actual != l->pri && encontrado != true);

        if(encontrado == false)
        {
            printf("\nDato no encontrado.\n");
        }
        else
        {
            free(anterior);
            printf("\nNodo eliminado satisfactoriamente.\n");
        }
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}

void bajaFrnt(listaC* l)
{
    nodo* actual = l->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->pri != NULL)
    {
        if(l->pri != l->ult)
        {
            l->pri = l->pri->sig;
            l->ult->sig = l->pri;
            anterior = actual;
            actual = actual->sig;
            free(anterior);
        }
        else
        {
            l->pri = anterior;
            l->ult = anterior;
            anterior = actual;
            free(anterior);
            free(actual);
        }


        printf("\nBaja al Frente realizada satisfactoriamente.\n");
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}
