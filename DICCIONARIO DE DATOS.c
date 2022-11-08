//
// Created by carca on 07/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entidad{
    char nombre[20];
    long atts;
    long datos;
    long sigEnt;
};

FILE *file;

int AbreArchivo(char* ruta){
    long cab = 0;
    file = fopen(ruta, "rb+");

    if(file == NULL){
        printf("FILE DOESNT EXIST\n");
        file = fopen(ruta, "wb");
        if(file != NULL){

            fwrite(&cab, 1, sizeof(long), file);
            printf("%d", sizeof(long), file);
            printf("CREATED FILE\n");
        }
        else
            return 0;
    }
    else
        printf("OPENED FILE\n");
    return 1;
}

void Guarda_entidad(char nombre[20]){
    long cab, posEnt_Guardada;
    struct entidad ent;

    strcpy(ent.nombre, nombre);
    ent.atts = 0;
    ent.datos = 0;
    ent.sigEnt = 0;

    fseek(file, 0, SEEK_END);
    posEnt_Guardada = ftell(file);
    fwrite(&ent, 1, sizeof(struct entidad), file);

    //VERIFICAR INSERCIÓN AL INICIO
    fseek(file, 0, SEEK_SET);
    fread(&cab, 1, sizeof (long), file);
    if(cab == 0){
        fseek(file, 0, SEEK_SET);
        fwrite(&posEnt_Guardada, 1, sizeof (long), file);
        printf("Primera entidad");
    }
}

int busca_entidad(char nombre[20], char entidad[])
{
    struct entidad ent;
    long cab;
    int aux = 0;

    file = fopen(nombre, "rb");
    if(file != NULL)
    {
        fread(&cab, sizeof(long), 1, file);
        while(cab != -1 && !aux)
        {
            fseek(file, cab, SEEK_SET);
            fread(ent, sizeof(struct entidad), 1, file);
            if(strcmp(ent.nombre, entidad) == 0)
            {
                aux = 1;
            }
            cab = ent.sigEnt;
        }
        fclose(file);
    }
    return(aux);
}


int main(){
    int res;
    res = AbreArchivo("archivo.bin");
    Guarda_entidad("persona");

    if(res == 1)
        fclose(file);

}


















