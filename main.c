#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

#define DADOS  PORTB
#define EN PORTDbits.RD7
#define RS PORTDbits.RD6

void LCD_init (void)
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    ANSELH = 0;
    TRISB = 0;
}

void LCD_on (void)
{
    RS = 0;
    EN = 1;
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_lincol (char lin, char col)
{
    //Ligar o Display
    RS = 0;
    EN = 1;
    DADOS = 0x80 + ( (lin*40)+ col);
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_printChar (char c)
{
    //Inserir a letra no LCD
    RS = 1;
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void main (void)
{
    LCD_init();
    LCD_on();
    
    LCD_lincol (0 , 4 );
    LCD_print ("limpol");
}

void LCD_print (char * str )
{
    char i = 0;
    while ( *(str+i) != 0 )
    {
        LCD_printChar( *(str+i) );
        ++i;
    }    
}
