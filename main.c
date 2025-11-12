//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para trabajar con fechas y horas, y generar números aleatorios con srand y rand.
#include <ctype.h> //para usar isdigit
#include <string.h>  // Para trabajar con cadenas de texto, como strlen 

//Macros para colores de letras
#define PURPURA "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define AMARILLO "\033[33m"
#define CELESTE "\033[1;36m"
#define BLANCO_NEGRITA "\033[1;37m"


//Prototipos de funciones
void portada();
void menu();
void nivel_facil();
void nivel_dificil();

//Funcion main del programa
int main() {
	portada();
	return 0;
}

//Funcion de mostrar portada
void portada(){
	printf(CELESTE"|================================================|\n");
	printf("\tPractica de Sumas\n", 162);
	printf("\tPara ninos\n", 164);
	printf("|================================================|\n");
	printf("\t  Aprendamos a Sumar Juntos\n");
	printf("|================================================|\n");
	printf("\t\t Hecho Por:\n");
	printf("\tJorge Manuel Dubon Fuentes\n");
	printf("|================================================|\n");
	printf(BLANCO_NEGRITA"|................Versi%cn 1.3.....................|\n", 162);
	printf(CELESTE"\n---Presione Enter para inicializar el programa---\n");
	system("pause");
	system("cls");
	menu();
}

//Funcion menu
void menu() {
    char entrada[10];  // Almacena la entrada del usuario
    int opcion, i;

    do {
        printf(BLANCO_NEGRITA"Hola amigo!\nDime, %cQu%c deseas hacer hoy?...\n", 168, 130);
        printf("-----------------------------------------\n");
        printf("      ***      \n");
        printf("   *       *   \n");
        printf("  *  ^     ^  *  \n");
        printf(" *             * \n");
        printf("  *   \\_/   *  \n");
        printf("   *       *   \n");
        printf("      ***      \n");
        printf("1. Practicar sumas f%cciles\n", 160);
        printf("2. Practicar sumas dif%cciles\n", 161);
        printf("3. Salir del juego\n");
        printf("Selecciona una opci%cn: ", 162);

        // Leer entrada como cadena
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
            // Eliminar salto de línea si existe
            entrada[strcspn(entrada, "\n")] = '\0';
            // Validar que la entrada sea un número
            int esNumero = 1;  // Suponemos que es un número
            for (i = 0; i < strlen(entrada); i++) {
                if (!isdigit(entrada[i])) {
                    esNumero = 0;  // No es un número
                    break;
                }
            }
            if (esNumero) {
                opcion = atoi(entrada);  // Convertir la cadena a entero

                system("cls");  // Limpia la pantalla entre opciones
                switch (opcion) {
                    case 1:
                        nivel_facil();
                        break;
                    case 2:
                        nivel_dificil();
                        break;
                    case 3:
                        system("cls");
                        printf(RED"-----------------------------------------\n");
                        printf("==========================================\n");
                        printf("=    AAAAA    DDDD    III  OOOOO  SSSSS =\n");
                        printf("=   A     A   D   D    I   O     O S     =\n");
                        printf("=   AAAAAAA   D   D    I   O     O SSSSS  =\n");
                        printf("=   A     A   D   D    I   O     O     S  =\n");
                        printf("=   A     A   DDDD    III  OOOOO  SSSSS   =\n");
                        printf("==========================================\n");
                        printf("-----------------------------------------\n");
                        printf("-----------------------------------------\n");
                        system("pause");
                        exit(0);
                    default:
                        printf("Opci%cn inv%clida. Int%cntalo de nuevo.\n", 162, 160, 130);
                }
            } else {
                printf("Error: Por favor ingresa un n%cmero v%clido.\n", 163, 160);
                system("pause");
                system("cls");
            }
        }
    } while (1);  // Mantener el menú activo
}

//Funcion del nivel facil (0-10)
void nivel_facil(){
	// Respuestas correctas
    int respuestas[15] = {2, 3, 8, 4, 5, 1, 6, 7, 9, 10, 1, 4, 8, 2, 7}; 
    // Arreglo para verificar preguntas ya mostradas
    int preguntas_presentadas[15] = {0}; 
    int i, numero_aleatorio, respuesta = 0;
    
    printf(AMARILLO"----------------------------------------------\n");
    printf("\tBienvenido al nivel f%ccil\n", 160);
    printf("----------------------------------------------\n");
    printf("      ***      \n");
    printf("   *       *   \n");
    printf("  *  ^     ^  *  \n");
    printf(" *             * \n");
    printf("  *   \\_/   *  \n");
    printf("   *       *   \n");
    printf("      ***      \n");
    printf("----------------------------------------------\n");
    printf(RED"Si desea salir del programa antes de terminar, escriba: 123\n");
    printf(RESET"----------------------------------------------\n");
    system("pause");
    // Inicializar la semilla para los números aleatorios
    srand(time(NULL)); 
	//Ciclo para mostrar las 15 preguntas
    for (i = 0; i < 15; i++) {
        // Generar un número aleatorio único
        do {
        	// Número aleatorio entre 1 y 15
            numero_aleatorio = 1 + rand() % 15;  
            // Repetir si la pregunta ya fue mostrada
        } while (preguntas_presentadas[numero_aleatorio - 1] == 1); 
        // Marcar la pregunta como mostrada
        preguntas_presentadas[numero_aleatorio - 1] = 1; 
        // Mostrar la pregunta según el número aleatorio generado
        switch (numero_aleatorio) {
            case 1: 
				printf(RESET"Pregunta %d:\n 3 + __ = 5\n", i + 1); 
				break;
            case 2: 	
				printf(RESET"Pregunta %d:\n 7 + _ = 10\n", i + 1); 
				break;
            case 3: 
				printf(RESET"Pregunta %d:\n 5 + 3 = _\n", i + 1); 
				break;
            case 4: 
				printf(RESET"Pregunta %d:\n _ + 4 = 8\n", i + 1); 
				break;
            case 5: 
				printf(RESET"Pregunta %d:\n _ + 5 = 10\n", i + 1); 
				break;
            case 6: 
				printf(RESET"Pregunta %d:\n 6 + _ = 7\n", i + 1); 
				break;
            case 7: 
				printf(RESET"Pregunta %d:\n 2 + 4 = _\n", i + 1); 
				break;
            case 8: 
				printf(RESET"Pregunta %d:\n 4 + 3 = _\n", i + 1); 
				break;
            case 9: 
				printf(RESET"Pregunta %d:\n 3 + 6 = _\n", i + 1); 
				break;
            case 10: 
				printf(RESET"Pregunta %d:\n 0 + _ = 10\n", i + 1); 
				break;
            case 11: 
				printf(RESET"Pregunta %d:\n _ + 1 = 2\n", i + 1); 
				break;
            case 12: 
				printf(RESET"Pregunta %d:\n 2 + 2 = _\n", i + 1); 
				break;
            case 13: 
				printf(RESET"Pregunta %d:\n 2 + _ = 10\n", i + 1); 
				break;
            case 14: 
				printf(RESET"Pregunta %d:\n _ + 6 = 8\n", i + 1); 
				break;
            case 15: 
				printf(RESET"Pregunta %d:\n 2 + 5 = _\n", i + 1); 
				break;
            default: 
				printf("ERROR...\n"); 
				break;
        }
        // Repetir la pregunta hasta que la respuesta sea correcta
        do {
    		printf("Escribe tu respuesta: ");
    		//verificar que introduza un numero valido
    		while (scanf("%d", &respuesta) != 1) { 
    			printf("-----------------------------------------\n");
        		printf(RED"Por favor, introduce un n%cmero v%clido.\n", 163, 160);
        		printf("-----------------------------------------\n");
        		while (getchar() != '\n'); // Limpiar el buffer
        		printf(RESET"Escribe tu respuesta: ");
    		}
            //Salir del modulo en caso de que asi lo desee el usuario
            if(respuesta == 123){
        	printf(RED"-----------------------------------------\n");
        	printf("Saliendo del nivel f%ccil...\n", 160);
        	printf("-----------------------------------------\n");
        	system("pause");
        	system("cls");
        	return;
        	//validación de respuesta
			}
            if (respuesta == respuestas[numero_aleatorio - 1]) {
                printf("-----------------------------------------\n");
                printf(AMARILLO"Buen trabajo!");
                break; 
            } else {
                printf("-----------------------------------------\n");
                printf(AMARILLO"Int%cntalo de nuevo!\n", 130);
                printf("-----------------------------------------\n");
                // Repetir la misma pregunta si la respuesta es incorrecta
                switch (numero_aleatorio) {
                    case 1: 
						printf(RESET"Pregunta %d:\n 3 + _ = 5\n", i + 1); 
						break;
                    case 2: 
						printf(RESET"Pregunta %d:\n 7 + _ = 10\n", i + 1); 
						break;
                    case 3: 
						printf(RESET"Pregunta %d:\n 5 + 3 = _\n", i + 1); 
						break;
                    case 4: 
						printf(RESET"Pregunta %d:\n _ + 4 = 8\n", i + 1); 
						break;
                    case 5: 
						printf(RESET"Pregunta %d:\n _ + 5 = 10\n", i + 1); 
						break;
                    case 6: 
						printf(RESET"Pregunta %d:\n 6 + _ = 7\n", i + 1); 
						break;
                    case 7: 
						printf(RESET"Pregunta %d:\n 2 + 4 = _\n", i + 1); 
						break;
                    case 8: 
						printf(RESET"Pregunta %d:\n 4 + 3 = _\n", i + 1); 
						break;
                    case 9: 
						printf(RESET"Pregunta %d:\n 3 + 6 = _\n", i + 1); 
						break;
                    case 10: 
						printf(RESET"Pregunta %d:\n 0 + _ = 10\n", i + 1); 
						break;
                    case 11: 
						printf(RESET"Pregunta %d:\n _ + 1 = 2\n", i + 1); 
						break;
                    case 12: 
						printf(RESET"Pregunta %d:\n 2 + 2 = _\n", i + 1); 
						break;
                    case 13: 
						printf(RESET"Pregunta %d:\n 2 + _ = 10\n", i + 1); 
						break;
                    case 14: 
						printf(RESET"Pregunta %d:\n _ + 6 = 8\n", i + 1); 
						break;
                    case 15: 
						printf(RESET"Pregunta %d:\n 2 + 5 = _\n", i + 1); 
						break;
                    default: 
						printf("ERROR...\n"); 
						break;
                }
            }
        } while (respuesta != respuestas[numero_aleatorio - 1]);

        printf("\n-------------------------------------------------\n");
    }

    printf("Has completado todas las preguntas. ¡Gracias por jugar!\n");
    printf("-----------------------------------------\n");
    printf("==========================================\n");
    printf("=    AAAAA    DDDD    III  OOOOO  SSSSS =\n");
    printf("=   A     A   D   D    I   O     O S     =\n");
    printf("=   AAAAAAA   D   D    I   O     O SSSSS  =\n");
    printf("=   A     A   D   D    I   O     O     S  =\n");
    printf("=   A     A   DDDD    III  OOOOO  SSSSS   =\n");
    printf("==========================================\n");
    system("pause");
    system("cls");
    menu();
}
//Funcion del nivel dificil (10-20)
void nivel_dificil(){
    int respuestas[15] = {5, 16, 20, 2, 20, 3, 4, 17, 15, 20, 17, 13, 16, 19, 5}; // Respuestas correctas
    int preguntas_presentadas[15] = {0}; // Arreglo para verificar preguntas ya mostradas
    int i, numero_aleatorio, respuesta = 0;
    
    printf(AMARILLO"----------------------------------------------\n");
    printf("\tBienvenido al nivel dif%ccil\n", 161);
    printf("----------------------------------------------\n");
    printf("      ***      \n");
    printf("   *       *   \n");
    printf("  *  >     <  *  \n");
    printf(" *     ---     * \n");
    printf("  *   \\_/   *  \n");
    printf("   *       *   \n");
    printf("      ***      \n");
    printf("----------------------------------------------\n");
    printf(RED"Si desea salir del programa antes de terminar, escriba: 123\n");
    printf(RESET"----------------------------------------------\n");
    system("pause");
    
    // Inicializar la semilla para la generación de números aleatorios
    srand(time(NULL));

    //Ciclo para mostrar las 15 preguntas
    for (i = 0; i < 15; i++) {
        do {
        	// Número aleatorio entre 1 y 15
            numero_aleatorio = 1 + rand() % 15;  
        } while (preguntas_presentadas[numero_aleatorio - 1] == 1); // Repetir si la pregunta ya fue mostrada
        // Marcar la pregunta como mostrada
        preguntas_presentadas[numero_aleatorio - 1] = 1; 

        // Generar el número aleatorio de la pregunta
        switch (numero_aleatorio) {
            case 1:
                printf(RESET"Pregunta %d:\n 10 + _ = 15\n", i + 1);
                break;
            case 2:
                printf(RESET"Pregunta %d:\n 11 + 5 = _ \n", i + 1);
                break;
            case 3:
                printf(RESET"Pregunta %d:\n 10 + 10 = _\n", i + 1);
                break;
            case 4:
                printf(RESET"Pregunta %d:\n 18 + _ = 20\n", i + 1);
                break;
            case 5:
                printf(RESET"Pregunta %d:\n 12 + 8 = _\n", i + 1);
                break;
            case 6:
                printf(RESET"Pregunta %d:\n 15 + _ = 18\n", i + 1);
                break;
            case 7:
                printf(RESET"Pregunta %d:\n 16 + _ = 20\n", i + 1);
                break;
            case 8:
                printf(RESET"Pregunta %d:\n 10 + 7 = _\n", i + 1);
                break;
            case 9:
                printf(RESET"Pregunta %d:\n 0 + _ = 15\n", i + 1);
                break;
            case 10:
                printf(RESET"Pregunta %d:\n 6 + 14 = _\n", i + 1);
                break;
            case 11:
                printf(RESET"Pregunta %d:\n 9 + 8 = _\n", i + 1);
                break;
            case 12:
                printf(RESET"Pregunta %d:\n 8 + 5 = _\n", i + 1);
                break;
            case 13:
                printf(RESET"Pregunta %d:\n 7 + 9 = _\n", i + 1);
                break;
            case 14:
                printf(RESET"Pregunta %d:\n 5 + 14 = _\n", i + 1);
                break;
            case 15:
                printf(RESET"Pregunta %d:\n 12 + _ = 17\n", i + 1);
                break;
            default:
                printf("ERROR...\n");
                break;
        }

        // Repetir la pregunta hasta que la respuesta sea correcta
        do {
        	printf("Escribe tu respuesta: ");
    		//verificar que introduza un numero valido
    		while (scanf("%d", &respuesta) != 1) { 
    			printf("-----------------------------------------\n");
        		printf(RED"Por favor, introduce un n%cmero v%clido.\n", 163, 160);
        		printf("-----------------------------------------\n");
        		while (getchar() != '\n'); // Limpiar el buffer
        		printf(RESET"Escribe tu respuesta: ");
    		}
            //Salir del modulo si asi lo desea el usuario
            if(respuesta == 123){
            	printf(RED"-----------------------------------------\n");
            	printf("Saliendo del nivel dif%ccil...\n", 161);
            	printf("-----------------------------------------\n");
            	system("pause");
            	system("cls");
            	return;
			}
            //validación de pregunta
            if (respuesta == respuestas[numero_aleatorio - 1]) {
                printf("-----------------------------------------\n");
                printf(AMARILLO"Buen trabajo!");
                break; 
            } else {
                printf("-----------------------------------------\n");
                printf(AMARILLO"Int%cntalo de nuevo!\n", 130);
                printf("-----------------------------------------\n");

                // Reimprimir la pregunta después de un intento fallido
                switch (numero_aleatorio) {
                    case 1:
                        printf(RESET"Pregunta %d:\n 10 + _ = 15\n", i + 1);
                        break;
                    case 2:
                        printf(RESET"Pregunta %d:\n 11 + 5 = _ \n", i + 1);
                        break;
                    case 3:
                        printf(RESET"Pregunta %d:\n 10 + 10 = _\n", i + 1);
                        break;
                    case 4:
                        printf(RESET"Pregunta %d:\n 18 + _ = 20\n", i + 1);
                        break;
                    case 5:
                        printf(RESET"Pregunta %d:\n 12 + 8 = _\n", i + 1);
                        break;
                    case 6:
                        printf(RESET"Pregunta %d:\n 15 + _ = 18\n", i + 1);
                        break;
                    case 7:
                        printf(RESET"Pregunta %d:\n 16 + _ = 20\n", i + 1);
                        break;
                    case 8:
                        printf(RESET"Pregunta %d:\n 10 + 7 = _\n", i + 1);
                        break;
                    case 9:
                        printf(RESET"Pregunta %d:\n 0 + _ = 15\n", i + 1);
                        break;
                    case 10:
                        printf(RESET"Pregunta %d:\n 6 + 14 = _\n", i + 1);
                        break;
                    case 11:
                        printf(RESET"Pregunta %d:\n 9 + 8 = _\n", i + 1);
                        break;
                    case 12:
                        printf(RESET"Pregunta %d:\n 8 + 5 = _\n", i + 1);
                        break;
                    case 13:
                        printf(RESET"Pregunta %d:\n 7 + 9 = _\n", i + 1);
                        break;
                    case 14:
                        printf(RESET"Pregunta %d:\n 5 + 14 = _\n", i + 1);
                        break;
                    case 15:
                        printf(RESET"Pregunta %d:\n 12 + _ = 17\n", i + 1);
                        break;
                    default:
                        printf("ERROR...\n");
                        break;
                }
            }
        } while (respuesta != respuestas[numero_aleatorio - 1]); // El ciclo continuará hasta que la respuesta sea correcta

        printf("\n-------------------------------------------------\n");
    }

    printf("Has completado todas las preguntas. ¡Gracias por jugar!\n");
    printf("-----------------------------------------\n");
    printf("==========================================\n");
    printf("=    AAAAA    DDDD    III  OOOOO  SSSSS =\n");
    printf("=   A     A   D   D    I   O     O S     =\n");
    printf("=   AAAAAAA   D   D    I   O     O SSSSS  =\n");
    printf("=   A     A   D   D    I   O     O     S  =\n");
    printf("=   A     A   DDDD    III  OOOOO  SSSSS   =\n");
    printf("==========================================\n");
    system("pause");
    system("cls");
    menu();
}
