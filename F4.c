#include<stdio.h>
#include<stdlib.h>

//FUNCIÓN PARA LA PRESENTACIÓN DE DATOS
int presentacion(){
    printf(" ______________________________________ \n");
    printf("|                                      |\n");
    printf("|     A B A R C A       C A R C A M O  |\n");
    printf("|          A L A N   Y A H I R         |\n");
    printf("|    ///LENGUAJES DE PROGRAMACION///   |\n");
    printf("|______________________________________|\n\n\n\n");
}


//FUNCIÓN PARA EL MENÚ
int menu(){

    int op;
	do{
        fflush(stdin);
    	printf("\n *************************************************************" );
		printf("\n | 1. CREAR ARCHIVO              6. MODIFICA ENTIDAD         |" );
		printf("\n | 2. ABRIR ARCHIVO              7. ALTA ATRIBUTO            |" );
		printf("\n | 3. SALIR                      8. BAJA ATRIBUTO            |" );
		printf("\n | 4. ALTA ENTIDAD               9. MODIFICA ATRIBUTO        |" );
		printf("\n | 5. BAJA ENTIDAD               10. IMPRIME DICCIONARIO     |" );
		printf("\n *************************************************************\n\n" );
		printf("\n\n Elige una opcion: ");
		scanf("%d",&op);

    	switch(op)
    	{
    		case 1:
    			printf("\n CREAR ARCHIVO \n");
    			//CREA EL ARCHIVO
				//abrirArchivo();
    			break;

    		case 2:
    			printf("\n ABRIR ARCHIVO \n");                        //Observemos que en cada case pusimos una función dependiendo de la opción que
    			//ABRE EL ARCHIVO                                     le correspondía seguido de un break para volver al menú de opciones.
				//agregaEntidades();
    			break;

    		case 3:
    			printf("\n SALIR \n");
    			//SALE DEL PROGRAMA
				//imprimeEntidad();
    			break;

    		case 4:
    			printf("\n ALTA ENTIDAD \n");
    			//DA DE ALTA ENTIDAD
				//eliminaEntidad();
    			break;

    		case 5:
    			printf("\n BAJA ENTIDAD \n");
    			//DA DE BAJA ENTIDAD
				//cerrarArchivo();
    			break;

    		case 6:
    			printf("\n MODIFICA ENTIDAD \n");
    			//MODIFICA ENTIDAD
				//g_estadistica();
    			break;

    		case 7:
    			printf("\n ALTA ATRIBUTO \n");
				//ALTA ATRIBUTO
				//factorial();
    			break;

    		case 8:
    			printf("\n BAJA ATRIBUTO \n");
    			// DA DE BAJA ATRIBUTO
    			break;

            case 9:
    			printf("\n MODIFICA ATRIBUTO \n");
    			// MODIFICA ATRIBUTO
    			break;

            case 10:
    			printf("\n IMPRIME DICCIONARIO \n");
    			// IMPRIME EL DICCIONARIO
    			break;

    		default:
    			printf("\n\n    ------ OPCION INVALIDA");
    			printf(", POR FAVOR INGRESA OTRO NUMERO ------\n");
		}
        printf("\n");
	} while(op != 8);

    return 0;


}


//FUNCIÓN PRINCIPAL
int main()
{


    presentacion();
    menu();
}




