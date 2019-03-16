/* 
 * File:   main.c
 * Author: Ing. Ricardo Presilla
 *
 * Created on 5 de mayo de 2017, 12:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <bios.h>

int puerto,k,j,dato,config;
char lectura[1],dato1[2];

char leer(){
    do{
        dato=bioscom(2,0x83,puerto);
    }while (!kbhit());/*Espera que se pulse una tecla*/
    return(dato);
 }

void main(void){
    system("cls");/*Limpiar pantalla*/
    printf("Ingrese puerto COM a usar: ");
    scanf("%d", &puerto);
    while(puerto<1 || puerto>4){
        system("cls");
        printf("ERROR... Debe ingresar 1, 2, 3 o 4 !!!\n\n");
        printf("Ingrese puerto COM a usar: ");
        scanf("%d", &puerto);
    }
    puerto--;
    config=0x83;
    /*Inicializa el puerto serial*/
    bioscom(0,config,puerto);
    system("cls");
    printf("RECEPCION DE DATOS VIA SERIE\n");
    printf("Config --> COM %d \\ 1200 bps \\ 8N1 \n", puerto+1);
    printf("Escape --> Salir \n");
    printf("MONITOR DE RECEPCION: ");
    do{
        if(!kbhit()) dato1[0]=leer();
            if(!kbhit()){
                gotoxy(40,12);
            printf("%1s ",dato1);
        }
    }while(!kbhit());
 }
 
