#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entidad
{
    char nombre[20];
    long sigEnt;
    long atts;
    long datos;
};

FILE* f;

int AbreArchivo(char* ruta)
{
    long cab = 0;

    f = fopen(ruta, "rb+");
    if (f == NULL)
    {
        printf("Archivo no existe\n");
        f = fopen(ruta, "wb");
        if (f != NULL)
        {
            fwrite(&cab, 1, sizeof(long), f);
             printf("Archivo creado\n");
        }
        else
            return 0;
    }
    else
        printf("Archivo abierto\n");

    return 1;
}

void GuardaEntidad(char nombre[20])
{
    long cab, pos, posEntGuardada;
    struct entidad ent, entGuardar, ultEnt;

    strcpy(entGuardar.nombre, nombre);
    entGuardar.atts = 0;
    entGuardar.datos = 0;
    entGuardar.sigEnt = 0;

    fseek(f, 0, SEEK_END);
    posEntGuardada = ftell(f);

    //pos = BuscaUltimaEntidad(&ultEnt);

    int p = fseek(f, 0, SEEK_SET);
    fread(&cab, 1, sizeof(long), f);
    printf("---%d----",cab);
    if (cab == 0)
    {
        fseek(f, 0 , SEEK_SET);
        fwrite(&posEntGuardada, 1, sizeof(long), f);
        printf("Primera entidad");
    }
    else
    {
        fseek(f, cab, SEEK_SET);
        fread(&ent, 1, sizeof(struct entidad), f);

        pos = cab;
        while(ent.sigEnt != 0)
        {
            pos = ent.sigEnt;

            fseek(f, ent.sigEnt, SEEK_SET);
            fread(&ent, 1, sizeof(struct entidad), f);
        }

        ent.sigEnt = posEntGuardada;
        fseek(f, pos, SEEK_SET);
        fwrite(&ent, 1, sizeof(struct entidad), f);
        printf("Insercion al final");
    }

    fseek(f, 0, SEEK_END);
    fwrite(&entGuardar, 1, sizeof(struct entidad), f);
}

int EliminaEntidad(char *nombre)
{
    int entEncontrada = 0;
    long cab, posEntAnt;
    struct entidad ent, entAnt;

    fseek(f, 0, SEEK_SET);
    fread(&cab, 1, sizeof(long), f);

    if (cab == 0) return 0;

    fseek(f, cab, SEEK_SET);
    fread(&ent, 1, sizeof(struct entidad), f);

    //Ver si es la primera entidad
    if (strcmp(ent.nombre, nombre) == 0)
    {
        cab = ent.sigEnt;
        fseek(f, 0, SEEK_SET);
        fwrite(&cab, 1, sizeof(long), f);
        return 1;
    }

    entAnt = ent;
    posEntAnt = cab;
    while(ent.sigEnt != 0)
    {
        fseek(f, ent.sigEnt, SEEK_SET);
        fread(&ent, 1, sizeof(struct entidad), f);

        if (strcmp(ent.nombre, nombre) == 0)
        {
            entEncontrada = 1;
            break;
        }

        entAnt = ent;
        posEntAnt = entAnt.sigEnt;
    }

    if (entEncontrada == 0) return 0;

    entAnt.sigEnt = ent.sigEnt;

    fseek(f, posEntAnt, SEEK_SET);
    fwrite(&entAnt, 1, sizeof(struct entidad), f);

    return 1;
}



void imprimeEntidad(){

    struct entidad ent;
    int cont;
    long cab;

    fseek(f, 0, SEEK_SET);
    fread(&cab, 1, sizeof(long), f);

    if(cab == 0) return 0;

    fseek(f, cab, SEEK_SET);
	fread(&ent, 1, sizeof(struct entidad), f);

	printf("Entidad %d\n", cont);
	printf("Nombre: %s\n", ent.nombre);
	printf("\n");

}


int menu(){
    int menu;

    printf("ELIGE EL NÚMERO\n");

    printf("1.- INSERTA ATRIBUTOS\n");
    printf("2.- ELIMINA ATRIBUTOS\n");
    printf("3.- SALIR\n");
    scanf("%d,", &menu);

    if(menu == 1)
        printf("hola\n");


}



//PONER ATRIBUTOS
// pedir tipo, si tipo es cadena es entero, si no el sizeof
void atributos(char *nombre){

    int entEncontrada = 0;
    long cab, posEntAnt;
    struct entidad ent;

    fseek(f, 0, SEEK_SET);
    fread(&cab, 1, sizeof(long), f);



}


int main()
{
    int res;
    menu();
    res = AbreArchivo("archivo.bin");
    GuardaEntidad("Persona");
    fclose(f);

    res = AbreArchivo("archivo.bin");
    GuardaEntidad("Alumno");

    if (res == 1)
        fclose(f);
}









/*
    - ALTAS Y BAJAS DE ENTIDADES DEBE DE FUNCIONAR ES UN MUST
    - ALTAS Y BAJAS DE ATRIBUTOS ES ESENCIAL Y MÍNIMO QUE DEBE DE REVISAR DE NOSOTROS
    - MENÚ FUNCIONAL
    - IMPRESIONES (si dimos de alta 3 entidades pues que se impriman las entidades y atributos)


    [-] MODIFICACIONES DE ATRIBUTOS COMO UNA BAJA Y ALTA O ESCRIBIENDOLO
    [-] MENSAJES DE ERRORES (Archivo no existe, archivo existe, archivo abierto, creado etc)

    DEPSENK

*/
   /// [L U N E S   5 DE DICIEMBRE, A MÁS TARDAR EL 6 DE DICIEMBRE POR SI HUBIESE UN ERROR]

















