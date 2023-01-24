#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo
{
    int dato;
    struct Nodo * sig;
} nodo;

typedef struct listaS
{
    nodo* pri;
    int cant;
} lista;

void crear(lista*);
void destruir(lista*);
void altaFrnt(lista*, int);
void altaFin(lista*, int);
void bajaFin(lista*);
void bajaFrnt(lista*);
void buscar(lista* l, int dato);
void recorrer(lista);
void borrar(lista*, int);
int cantidad(lista);

int main()
{
    lista list;
    int opcion = -1, dato;

    do
    {
        printf("\n|-------------------------------------|");
        printf("\n|    *  Lista Simplemente Ligada  *   |");
        printf("\n|------------------|------------------|");
        printf("\n| 1. Crear lista   | 6. Recorrer      |");
        printf("\n| 2. Alta Frente   | 7. Buscar        |");
        printf("\n| 3. Alta Final    | 8. Borrar dato   |");
        printf("\n| 4. Baja Frente   | 9. Destruir      |");
        printf("\n| 5. Baja Final    | 0. Salir         |");
        printf("\n|-------------------------------------|");
        printf("\n|     10. Cantidad de elementos       |");
        printf("\n|-------------------------------------|");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\nCreando Lista Simple...\n");
            crear(&list);
            break;
        case 2:
            printf("\n\nIngrese un valor para dar de alta al frente, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                altaFrnt(&list, dato);

                printf("\n\nIngrese un valor para dar de alta al frente, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 3:
            printf("\n\nIngrese un valor para dar de alta al final, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                altaFin(&list, dato);

                printf("\n\nIngrese un valor para dar de alta al final, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 4:
            printf("\nRealizando baja al frente...\n");
            bajaFrnt(&list);
            break;
        case 5:
            printf("\nRealizando baja al final...\n");
            bajaFin(&list);
            break;
        case 6:
            printf("\nRecorriendo lista: \n");
            recorrer(list);
            break;
        case 7:
            printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

                buscar(&list, dato);

            }


            break;
        case 8:
            printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                borrar(&list, dato);

                printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

            }
            break;
        case 9:
            printf("\n\nDestruyendo Lista...\n");
            destruir(&list);
            break;
        case 10:
            printf("\nContando elementos...\n");
            if(cantidad(list) > 0)
                printf("\nHay %d elementos en la lista.\n", cantidad(list));
            else
                printf("\nLista vacia.\n");
            break;
        case 0:
            printf("\n\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");

        }
    }
    while(opcion != 0);

    return 0;
}

void crear(lista* l)
{
    l->pri = NULL;
    l->cant = 0;
    printf("\nLista Creada exitosamente.\n");
}

void altaFrnt(lista* l, int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = l->pri;
    l->pri = nuevo;
    l->cant += 1;
    printf("\nSe ha realizado un alta al frente correctamente.\n");
}

void altaFin(lista* l, int dato)
{
    if(l->pri == NULL)
    {
        l->pri = (nodo*)malloc(sizeof(nodo));
        l->pri->dato = dato;
        l->pri->sig = NULL;
        l->cant += 1;
    }
    else
    {
        nodo* actual = l->pri;

        while(actual->sig != NULL)
            {
                actual = actual->sig;
            }

        actual->sig = (nodo*)malloc(sizeof(nodo));
        actual = actual->sig;
        actual->dato = dato;
        actual->sig = NULL;
        l->cant += 1;
    }

    printf("\nSe ha realizado un alta al final correctamente.\n");
}

void recorrer(lista l)
{
    nodo* actual = l.pri;

    if(l.pri != NULL)
    {
        while(actual != NULL)
        {
            printf("\n%d\n", actual->dato);
            actual = actual->sig;
        }
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}

void bajaFin(lista* l)
{
    nodo* actual = l->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(l->pri != NULL)
    {
        while(actual->sig != NULL)
            {
                anterior = actual;
                actual = actual->sig;
            }
        if(actual != l->pri)
            {
                anterior->sig = NULL;
                free(actual);
                l->cant -= 1;
            }
        else
            {
                l->pri = actual->sig;
                free(actual);
                l->cant -= 1;
            }

        printf("\nSe ha dado una baja al final correctamente.\n");

    }
    else
    {
        printf("\nLista inexistente.\n");
    }
}

void bajaFrnt(lista* l)
{
    nodo* actual = l->pri;

    if(l->pri != NULL)
    {
        l->pri = l->pri->sig;
        free(actual);
        l->cant -= 1;

        printf("\nSe ha realizado una baja al frente correctamente.\n");

    }
    else
    {
        printf("\nLista inexistente.\n");
    }
}

void destruir(lista* l)
{
    nodo* actual = l->pri;
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux = NULL;

    if(l->pri != NULL)
    {
        while(actual != NULL)
        {
            if(actual == l->pri)
            {
                l->pri = l->pri->sig;
                aux = actual;
                actual = actual->sig;
                free(aux);
                l->cant -= 1;
            }
            else if(actual->sig == NULL)
            {
                aux->sig = NULL;
                aux = actual;
                actual = actual->sig;
                free(aux);
                l->cant -= 1;
            }
            else
            {
                aux->sig = actual->sig;
                aux = actual;
                actual = actual->sig;
                free(aux);
                l->cant -= 1;
            }
        }





    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}

void borrar(lista* l, int dato)
{
    nodo* actual = l->pri;
    nodo* anterior = (nodo*) malloc(sizeof(nodo));
    anterior = NULL;

    bool encontrado = false;

    if(l->pri!=NULL)
    {
        while(actual != NULL && encontrado != true)
        {

            if(actual->dato == dato)
            {

                if(actual == l->pri)
                {
                    l->pri = l->pri->sig;
                }
                else if(actual->sig == NULL)
                {
                    anterior->sig = NULL;
                }
                else
                {
                    anterior->sig = actual->sig;
                }


                encontrado = true;
            }
            anterior = actual;
            actual = actual->sig;
        }
        if(encontrado == false)
        {
            printf("\nNodo no encontrado\n\n");
        }
        else
        {
            l->cant -= 1;
            free(anterior);
            printf("\nDato Eliminado satisfactoriamente.\n");
        }
    }
    else
    {
        printf("\nLa lista se encuentra vacia\n\n");
    }
}

void buscar(lista* l, int dato)
{
    nodo* actual = l->pri;
    bool encontrado = false;

    if(l->pri!=NULL)
    {
        while(actual != NULL && encontrado != true)
        {

            if(actual->dato == dato)
            {
                printf("\nEl nodo con el dato ( %d ) Encontrado\n\n", dato);
                encontrado = true;
            }

            actual = actual->sig;
        }
        if(encontrado == false)
        {
            printf("\nNodo no encontrado\n\n");
        }
    }
    else
    {
        printf("\nLa lista se encuentra vacia\n\n");
    }
}

int cantidad(lista l)
{
    return l.cant;
}
