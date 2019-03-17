///Este programa limpia la lcd, al conectarse, despues aparece cursor y parpadea 1 segundo, fila1 mensaje "Mecatronica", fila2
//contador=x, donde x va de 0 a 12 y se reinicia, mientreas se inccrementa el mensaje 1 se desplaza 

#include <xc.h>
#include "config.h"
#include <stdio.h>      //para escribir en la lcd
#define _XTAL_FREQ 32000000 //su usa cuando usamos delays
#include "flex_lcd.h"       //sumamente necesaria esta libreria externa para el manejo de la LCD, revisarlo par aconfigurar puertos, mi expressno funciona con el c


void main(void) {
    unsigned char i;//declarar variables
    unsigned char buffer1[16];//declarar 16 posiciones cadena de caracteres con //cada char tiene 8 bites
    //osc
    OSCFRQbits.HFFRQ = 0b110; //32 MHz
    //puertos
    ANSELC=0; //Puesrto D como digital
    ANSELC=0;//Puesrto E como digital
    //inicializacion de LCD
    Lcd_Init();//Inicializa LCD
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(100);
    Lcd_Cmd(LCD_BLINK_CURSOR_ON);
    __delay_ms(1000);
    Lcd_Cmd(LCD_CURSOR_OFF);
    
    int a=2;
    int b=1;
     for (i=0; i<13; i++){
         a=a+1;
         b=b+1;         
      Lcd_Out(1,b, " ");
      Lcd_Out(1,a, "Mecatronica");//escribimos en la lcd        
      sprintf(buffer1, "Contador %03d",i);
      Lcd_Out2(2, 1, buffer1);
      __delay_ms(500);
     }
   
    //ciclo infinito
    while(1){
        for (i=0; i<13; i++)
    {
      Lcd_Out(1,1, "                ");
      sprintf(buffer1, "Contador %03d",i);
      Lcd_Out2(2, 1, buffer1);
      __delay_ms(500);
    }     
        
    }
    
    return;
}
