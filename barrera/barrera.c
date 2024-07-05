#include "barrera.h"
#include "MKL25Z4.h"
#include "ctype.h"
int cant_pasos=0, pines[4]={10, 12, 13, 14};
void inMotor(){
    SIM->SCGC5|=SIM_SGC5_PORTA_MASK;
    for (i = 0; i<4; i++){
        PORTA->PCR[pines[i]]|=PORT_PCR_MUX(1);
    }
}

void motor(int grados, char tipoPaso){
    switch (tipoPaso){
    case 'f':
        int pasos= grados/1.8;
        cant_pasos = pasos;
        do{
        if(cant_pasos<=pasos){
            if(cant_pasos==1){
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(0<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==2){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(0<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==3){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
            }else if (cant_pasos==4){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }
            cant_pasos =cant_pasos-4;

        }else if(cant_pasos==0){
            cant_pasos=0;
        }
    }while(cant_pasos==pasos);    

        break;
    case 'n':
      int pasos= grados/1.8;
        cant_pasos = pasos;
        do{
        if(cant_pasos<=pasos){
            if(cant_pasos==1){
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(0<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==2){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(1u<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==3){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }else if (cant_pasos==4){
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }
            cant_pasos =cant_pasos-4;

        }else if(cant_pasos==0){
            cant_pasos=0;
        }
    }while(cant_pasos==pasos);    
    break;
    case 'm':
      int pasos= grados/1.8;
        cant_pasos = pasos;
        do{
        if(cant_pasos<=pasos){
            if(cant_pasos==1){
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(0<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==2){
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(0<<pines[2]);
                PTA->PSOR|=(0<<pines[3]);
            }else if (cant_pasos==3){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
            }else if(cant_pasos==4){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);          
            }else if (cant_pasos==5){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
            }else if (cant_pasos==6){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }else if (cant_pasos==5){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }else if (cant_pasos==5){
                PTA->PSOR|=(0<<pines[0]);
                PTA->PSOR|=(0<<pines[1]);
                PTA->PSOR|=(1u<<pines[0]);
                PTA->PSOR|=(1u<<pines[1]);
            }
            cant_pasos =cant_pasos-8;

        }else if(cant_pasos==0){
            cant_pasos=0;
        }
    }while(cant_pasos==pasos);    
    }
}