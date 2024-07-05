#include "semaforo.h"
#include "MKL25Z4.h"
int s[2] = {2,3};
int led_r[3] = {4,5, 6};
int led_a = 7;
int led_v[3] = {8, 9, 10};
int i, est_ledr, est_ledv;
int boton=15;
void insemaforo(){
    SIM->SCGC5|=SIM_SGC5_PORTA_MASK;
    for (i = 0; i <2; i++){
        PORTA-> PCR[s[i]]|=PORT_PCR_MUX(1);
    }
    for (i = 0; i <3; i++){
        PORTA-> PCR[led_r[i]]|=PORT_PCR_MUX(1);
        PORTA-> PCR[led_v[i]]|=PORT_PCR_MUX(1);
   }  
    PORTA-> PCR[7]|=PORT_PCR_MUX(1);
    PORTx -> PCR[15]|=PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
}
void tipoSemaforo(char tipo, char color, int semtipo){

    switch (semtipo)
    {
    case 1:
        if(tipo=='g'){
            if(color == 'r'){
            PTA->PSOR|=(1u<<led_r[1]);
            PTA->PSOR|=(0<<led_v[1]);
            }else if (color== 'v'){
                PTA->PSOR|=(1u<<led_v[1]);
                PTA->PSOR|=(0<<led_r[1]);
            }
        }else if (tipo=='n'){
            if(color == 'r'){
                PTA->PSOR|=(1u<<led_r[0]);
                PTA->PSOR|=(0<<led_v[0]);
                PTA->PSOR|=(0<<led_a);
            }else if (color== 'v'){
                PTA->PSOR|=(1u<<led_v[0]);
                PTA->PSOR|=(0<<led_r[0]);
                PTA->PSOR|=(0<<led_a);
            }else if (color=='a'){
                PTA->PSOR|=(1<<led_a);
                PTA->PSOR|=(0<<led_v[0]);
                PTA->PSOR|=(0<<led_r[0]);
            }
        }
        
        break;
    case 2:
        if(tipo=='g'){
            if(color == 'r'){
            PTA->PSOR|=(1u<<led_r[3]);
            PTA->PSOR|=(0<<led_v[3]);
            }else if (color== 'v'){
                PTA->PSOR|=(1u<<led_v[3]);
                PTA->PSOR|=(0<<led_r[3]);
            }
        }else if (tipo=='n'){
            if(color == 'r'){
                PTA->PSOR|=(1u<<led_r[0]);
                PTA->PSOR|=(0<<led_v[0]);
                PTA->PSOR|=(0<<led_a);
            }else if (color== 'v'){
                PTA->PSOR|=(1u<<led_v[0]);
                PTA->PSOR|=(0<<led_r[0]);
                PTA->PSOR|=(0<<led_a);
            }else if (color=='a'){
                PTA->PSOR|=(1<<led_a);
                PTA->PSOR|=(0<<led_v[0]);
                PTA->PSOR|=(0<<led_r[0]);
            }
        }
        
        break;
    }
    if (boton==1){
        for (i = 0; i <3; i++){
            
        }
    }
    
}