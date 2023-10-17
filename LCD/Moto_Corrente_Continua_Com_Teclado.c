//#include "D:\Microcontroladores\Prova\2_Motor_Corrente_Continua\Moto_Corrente_Continua_Com_Teclado.h"

#include <16F877A.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits

#use delay(clock=20000000)

#ifndef lcd_enable
 #define lcd_enable pin_E1 // pino enable do LCD
 #define lcd_rs pin_E2 // pino rs do LCD
 //#define lcd_rw pin_e2 // pino rw do LCD
 #define lcd_d4 pin_d4 // pino de dados d4 do LCD
 #define lcd_d5 pin_d5 // pino de dados d5 do LCD
 #define lcd_d6 pin_d6 // pino de dados d6 do LCD
 #define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif
#include "mod_lcd.c"
#include "kbd_ext_board2.c"


void main()
{
   unsigned char tmp = 0;
   int8 valor = 0;
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   lcd_ini(); // Inicializa LCD
   
   while(true){
    tmp = tc_tecla(10);
    
    if (tmp == 'A'){
      valor = 100;
    } else if (tmp>=48 && tmp<=57){
      valor = (int8)tmp - 48;
    } else {
      valor = 0;
    }
    
    valor = valor * 10; // para ficar 10% - 20% - 30%....
    printf(lcd_escreve,"\fPotencia: %d%% \r\n", valor);
    
    set_adc_channel(valor);
   }

}
