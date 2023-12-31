#include <16F877A.h>
#device adc=8

#FUSES NOWDT
#FUSES HS
#FUSES NOPUT
#FUSES NOPROTECT
#FUSES NODEBUG
#FUSES BROWNOUT
#FUSES NOLVP
#FUSES NOCPD
#FUSES NOWRT

#use delay(clock=20000000)

void main()
{
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   while(true){
      // D0 = Vermelho
      // D1 = Amarelo
      // D2 = Verde1
      
      // B0 = Vermelho
      // B1 = Amarelo
      // B2 = Verde
        
      output_low(PIN_D1);
      output_low(PIN_D2);
      output_low(PIN_D3);
      output_low(PIN_D4);
      output_low(PIN_D5);
      output_low(PIN_D6);
      output_low(PIN_D7);
      output_low(PIN_B0);
      output_low(PIN_B1);
      output_low(PIN_B2);
      output_low(PIN_B3);
      output_low(PIN_B4);
      output_low(PIN_B5);
      output_low(PIN_B6);
      output_low(PIN_B7);
      
      output_high(PIN_B0); // Acende Luz Vermelha B
      output_high(PIN_D0); // Acende Luz Vermelha D
      delay_ms(1000); // atraso de 1s ou 1000 milesegundos
      output_low(PIN_B0); // Apaga Luz Vermelha B
      output_high(PIN_B2); // Acende Luz Verde B
      delay_ms(5000); // Espera 5s
      output_low(PIN_B2); // Apaga Luz B verde
      output_high(PIN_B1); // Acende Luz B Amarela
      delay_ms(1000);
      output_low(PIN_B1); // Apaga Luz Amarela B
      output_high(PIN_B0); // Acende Luz Vermelha B
      delay_ms(1000);
      output_low(PIN_D0); // Apaga Luz Vermelha D
      output_high(PIN_D2); // Acende Luz Verde D
      delay_ms(5000); // atraso de 5s ou 5000 milesegundos
      output_low(PIN_D2); // Apaga Luz Verde D
      output_high(PIN_D1); // Acende Luz Amarela D
      delay_ms(1000);
   }
}

