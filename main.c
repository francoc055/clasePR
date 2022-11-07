#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float altura;
}ePersona;

ePersona* newPersona();
ePersona* newPersonaParam(int id, char nombre[], char apellido[], char sexo, float altura);
int mostrarPersona(ePersona* p);

// getters y setters
int personaSetId(ePersona* p, int id);
int personaSetNombre(ePersona* p, char nombre[]);
int personaSetApellido(ePersona* p, char apellido[]);
int personaSetSexo(ePersona* p, char sexo);
int personaSetAltura(ePersona* p, float altura);
//-----------------------------------------------
int personaGetId(ePersona* p, int* pId);
int personaGetSexo(ePersona* p, char* pSexo);
int personaGetSexoString(ePersona* p, char sexo[]);


int main()
{

char auxCad[20];
    ePersona* p = newPersonaParam(20000, "juan", "perez", 'm', 1.80);

    if(p == NULL){
        printf("no hay memoria");
        exit(1);
    }

    mostrarPersona(p);

    printf("\n");
    personaSetNombre(p, "pEdro");
    mostrarPersona(p);

    printf("\n");
    personaGetSexoString(p, auxCad);
    puts(auxCad);

    return 0;
}
//getter

int personaGetSexoString(ePersona* p, char sexo[])
{
    int ret = 0;
        if(p != NULL && sexo != NULL)
        {
            if(p->sexo == 'f')
            {
                strcpy(sexo, "femenino");
            }
            else if(p->sexo == 'm')
            {
                strcpy(sexo, "masculino");
            }
            ret = 1;
        }
    return ret;
}

int personaGetSexo(ePersona* p, char* pSexo)
{
    int ret = 0;
    if(p != NULL && pSexo != NULL)
    {
        *pSexo = p->sexo;
        ret = 1;
    }
return ret;
}


int personaGetId(ePersona* p, int* pId)
{
    int ret = 0;
    if(p != NULL && pId != NULL)
    {
        *pId = p->id;
        ret = 1;
    }
return ret;
}


// setter
int personaSetAltura(ePersona* p, float altura)
{
    int ret = 0;
    if(p != NULL && altura >= 1.50 && altura<= 2.05)
    {
        p->altura = altura;
        ret = 1;
    }
    return ret;
}

int personaSetSexo(ePersona* p, char sexo)
{
    int ret = 0;
    if(p != NULL && (sexo == 'm' || sexo == 'f'))
    {
        sexo = tolower(sexo);
        p->sexo = sexo;
        ret = 1;
    }
    return ret;
}

int personaSetApellido(ePersona* p, char apellido[])
{
    int ret = 0;
    if(p != NULL && apellido != NULL && strlen(apellido) < 20)
    {
        strcpy(p->apellido, apellido);
        strlwr(p->apellido);
        p->apellido[0] = toupper(p->apellido[0]);
        ret = 1;
    }
    return ret;
}

int personaSetNombre(ePersona* p, char nombre[])
{
    int ret = 0;
    if(p != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(p->nombre, nombre);
        strlwr(p->nombre);
        p->nombre[0] = toupper(p->nombre[0]);
        ret = 1;
    }
    return ret;
}

int personaSetId(ePersona* p, int id)
{
    int ret = 0;
    if(p != NULL && id>= 20000 && id<= 30000)
    {
        p->id = id;
        ret = 1;
    }
    return ret;
}

ePersona* newPersonaParam(int id, char nombre[], char apellido[], char sexo, float altura)
{
    ePersona* p = newPersona();
    if(!(personaSetId(p, id)
       && personaSetNombre(p, nombre)
       && personaSetApellido(p, apellido)
       && personaSetSexo(p, sexo)
       && personaSetAltura(p, altura)))
    {
        free(p);
        p = NULL;
    }
    return p;
}

ePersona* newPersona(){
    ePersona* p = (ePersona*) malloc(sizeof(ePersona));
    if(p != NULL){
        p->id = 0;
        strcpy(p->nombre, " ");
        p->sexo = ' ';
        p->altura = 0.00;
    }
return p;
}

int mostrarPersona(ePersona* p)
{
    int ret = 0;
    if(p!= NULL){
        printf("id: %d nombre: %s apellido: %s sexo: %c altura: %f", p->id, p->nombre, p->apellido, p->sexo, p->altura);
        ret = 1;
    }
return ret;
}
