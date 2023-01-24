#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* ant;
    struct Nodo* sig;
} nodo;

typedef struct listaD
{
    nodo* pri;
    int cant;
} lista;

//Operaciones basicas
void crear(lista*);
void destruir(lista*);
void altaFrnt(lista*, int);
void altaFin(lista*, int);
void recorrer(lista);
void recorrerInv(lista);
void buscar(lista*, int);
void borrar(lista*, int);
void bajaFrnt(lista* );

int main()
{
    lista list;
    int opcion = -1, dato;

    do
    {
        printf("\n|--------------------------------------|");
        printf("\n|    *  Lista Doblemente Ligada  *     |");
        printf("\n|------------------|-------------------|");
        printf("\n| 1. Crear lista   | 7. Recorrer Inv.  |");
        printf("\n| 2. Alta Frente   | 8. Cant. datos    |");
        printf("\n| 3. Alta Final    | 9. Buscar         |");
        printf("\n| 4. Baja Frente   | 10. Borrar dato   |");
        printf("\n| 5. Baja Final    | 11. Destruir      |");
        printf("\n| 6. Recorrer      |                   |");
        printf("\n|--------------------------------------|");
        printf("\n|       0. Salir del Programa          |");
        printf("\n|--------------------------------------|");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\nCreando Lista Doble...\n");
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
            //bajaFin(&list);
            break;
        case 6:
            printf("\nRecorriendo lista: \n");
            recorrer(list);
            break;
        case 7:
            printf("\nRecorriendo lista de manera inversa: \n");
            recorrerInv(list);
            break;
        case 8:

        case 9:
            printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                buscar(&list, dato);

                printf("\n\nIngrese dato a buscar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);
            }

            break;
        case 10:
            printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                borrar(&list, dato);

                printf("\n\nIngrese dato para borrar, o -1 para volver al menu principal:\n");
                scanf("%d", &dato);

            }
            break;

        case 11:
            printf("\nRecorriendo lista: \n");
            //destruir(list);
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
    printf("\n�Lista Doblemente Ligada creada con exito!\n");
}
void altaFrnt(lista* l, int dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;

    if(l->pri == NULL)
        {
            l->pri = nuevo;
            l->pri->sig = NULL;
            l->pri->ant = NULL;
        }
    else
        {
            l->pri->ant = nuevo;
            nuevo->sig = l->pri;
            nuevo->ant = NULL;
            l->pri = nuevo;
        }

    l->cant += 1;
    printf("\nSe ha realizado un alta al frente de manera correcta.\n");
}
void altaFin(lista* l, int dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;

    if(l->pri == NULL)
        {
            l->pri = nuevo;
            l->pri->sig = NULL;
            l->pri->ant = NULL;
        }
    else
        {
            nodo* actual = l->pri;

            while(actual->sig != NULL)
                {
                    actual = actual->sig;
                }
            actual->sig = nuevo;
            nuevo->sig = NULL;
            nuevo->ant = actual;
        }

    l->cant += 1;
    printf("\nSe ha realizado un alta al final de manera correcta.\n");
}
void recorrer(lista l)
{
    nodo* actual = l.pri;

    while(actual != NULL)
        {
            printf("\n%d\n", actual->dato);
            actual = actual->sig;
        }
}
void recorrerInv(lista l)
{
    nodo* actual = l.pri;

    while(actual->sig != NULL)
        {
            actual = actual->sig;
        }
    while(actual != NULL)
        {
            printf("\n%d\n", actual->dato);
            actual = actual->ant;
        }
}
void bajaFrnt(lista* l)
{
    nodo* actual = l->pri;

    if(l->pri != NULL)
        {
            if(actual->sig != NULL)
                {
                    l->pri = l->pri->sig;
                    l->pri->ant = NULL;
                    free(actual);
                }
            else
                {
                    l->pri = NULL;
                    free(actual);
                }
            printf("\nSe ha realizado una baja al frente con exito.\n");

        }
    else
        {
            printf("\nLista inexistente.\n");
        }
}
void buscar(lista* l, int dato)
{
    bool encontrado = false;
    nodo* actual = l->pri;
    int nod = 0;

    if(l->pri != NULL)
        {
            while(actual != NULL && encontrado != true)
                {
                    if(actual->dato == dato)
                        {
                            printf("\nDato %d encontrado en el nodo %d.\n", actual->dato, nod+1);
                            encontrado = true;
                        }
                    nod++;
                    actual = actual->sig;
                }
            if(encontrado == false)
                printf("\nDato no encontrado.\n");
        }
    else
        {
            printf("\nLista inexistente.\n");
        }

}
void borrar(lista* l, int dato)
{
    bool encontrado = false;
    nodo* actual = l->pri;
    nodo* ant = (nodo*)malloc(sizeof(nodo));
    ant = NULL;
    int nod = 0;

    if(l->pri != NULL)
        {
            while(actual != NULL && encontrado != true)
                {
                    if(actual->dato == dato)
                        {
                            if(actual == l->pri)
                                {
                                    l->pri = l->pri->sig;
                                    l->pri->ant = NULL;
                                }
                            else if(actual->sig == NULL)
                                {
                                    ant->sig = NULL;
                                    actual = ant;
                                }
                            else
                                {
                                    ant->sig = actual->sig;
                                    actual->sig->ant = ant;
                                }
                            encontrado = true;
                        }

                    ant = actual;
                    actual = actual->sig;
                }
            if(encontrado == false)
                {
                    printf("\nDato no encontrado.\n");
                }
            else
                {
                    l->cant -= 1;
                    free(ant);
                    printf("\nDato eliminado de manera correspondiente.\n");
                }

        }
    else
        {
            printf("\nLista inexistente.\n");
        }

}
