#include <16F877A.h>
#include <string.h>
#include <stdio.h>

//#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits

#use delay(clock=4000000)

#ifndef lcd_enable
 #define lcd_enable pin_A3 // pino enable do LCD
 #define lcd_rs pin_A5 // pino rs do LCD
 #define lcd_rw pin_A4 // pino rw do LCD
 #define lcd_d4 pin_d4 // pino de dados d4 do LCD
 #define lcd_d5 pin_d5 // pino de dados d5 do LCD
 #define lcd_d6 pin_d6 // pino de dados d6 do LCD
 #define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif
#include "mod_lcd.c"
#include "kbd_ext_board2.c"
#include "2408.c"


long int End_HL(byte H, byte L){
   return (H<<8)+ L;
}

char* IntToHex(int value) {
   int a;
   int b;
   char* buffer;
   
   a = value && 16;
   b = (value>>4)&16;
   buffer[0] = (a<10)?'0'+a:'A'-(a-10);
   buffer[1] = (b<10)?'0'+b:'A'-(b-10);
   
   return buffer;
}

void WRITE_FLOAT_EXT_EEPROM(long int n, float data) {
   int i;
   
   for (i = 0; i < 4; i++)
   write_ext_eeprom(i + n, *((int8*)&data + i) ) ;
}

float READ_FLOAT_EXT_EEPROM(long int n) {
   int i;
   float data;
   
   for (i = 0; i < 4; i++)
   *((int8*)&data + i) = read_ext_eeprom(i + n);
   
   return((float)data);
}

void eeprom_int16(unsigned int endereco, int16 valor_i16)
{
   write_ext_eeprom(endereco, make8(valor_i16,0));
   write_ext_eeprom(endereco+1, make8(valor_i16,1));
}

void main()
{
   unsigned char tmp = 0;
   char senha[4] = "";
   int8 cont = 0;
   int1 senhaEstaCorreta = 1;
   char senha_memoria[4] = "1234";
   
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
   delay_ms(10);
   init_ext_eeprom();
   delay_ms(10);

   // Escrevendo a senha na mem�ria
   write_ext_eeprom(0x1, '1');
   write_ext_eeprom(0x2, '2');
   write_ext_eeprom(0x3, '3');
   write_ext_eeprom(0x4, '4');
   
   int8 i;
   
   for(i = 0; i < 4; i++){
      senha[i] = 0;
   }
   
   while(true){
    printf(lcd_escreve,"\fBem vindo!!\nSenha: %s", senha);
    delay_ms(300);
    tmp = tc_tecla(200);
    
    if (((int)tmp >= 48 && (int)tmp <= 57) || ((int)tmp >=65 && (int)tmp <= 68) || ((int)tmp == 42 || (int)tmp == 35)){ 
       senha[cont] = tmp;
       
       cont++;
       delay_ms(200);
    }
    
    if (cont == 4){
      for(i = 0; i < cont; i++){
         printf(lcd_escreve, "\fPosicao[%d]: %d", i+1, read_ext_eeprom((int16)i+1));
         delay_ms(1000);
         if(senha[i] != read_ext_eeprom((int16)i+1)){
            senhaEstaCorreta = 0;
         }
      }
      if(senhaEstaCorreta == 1){
         printf(lcd_escreve, "\fPARABENS PORTA\nABERTA!!");
         delay_ms(10000);
      } 
      else {
         printf(lcd_escreve, "\fSENHA INCORRETA!");
         delay_ms(10000);
      }
   }
   }
}
