#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

#define Dir PORTC

void step_motor(int speed ,char L_R ,char F_H ,int rotate);

void main(){

    DDRC.2=1;
    DDRC.3=1;
    DDRC.4=1;
    DDRC.5=1;

    PORTC.2=0;
    PORTC.3=0;
    PORTC.4=0;
    PORTC.5=0;
    
    lcd_init(16);
    lcd_clear();    
     
            step_motor(500,'r','f',1); 
    
     while(1){
     

     }

}

void step_motor(int speed ,char L_R ,char F_H ,int rotate){

         unsigned char i,j,z;
         char array[8]={1,3,2,6,4,12,8,9}; 
         char array1[18]={0};
         
         if(F_H=='f'){
               if(L_R=='l'){
                  for(z=0;z<rotate;z++){
                      for(i=0;i<6;i++){ 
                          for(j=5;j>1;j--){
                              delay_ms(speed);
                              Dir=0x01<<j;
                          }
                      }
                  }
               }else if(L_R=='r'){
                  for(z=0;z<rotate;z++){
                      for(i=0;i<6;i++){ 
                          for(j=2;j<6;j++){
                              delay_ms(speed);
                              Dir=0x01<<j;
                          }
                      }                  
                  }               
               }
               
         }else if(F_H=='h'){
               if(L_R=='l'){
                  for(z=0;z<rotate;z++){
                      for(i=0;i<6;i++){ 
                          for(j=8;j>0;j--){
                          
                              Dir=array[j-1]<<2;
                              
                              lcd_clear();
                              lcd_gotoxy(1,0);
                              sprintf(array1,"%d",array[j]);
                              lcd_puts(array1);
                              delay_ms(speed);
                          } 
                         
                      }                  
                  }               
               }else if(L_R=='r'){
                  for(z=0;z<rotate;z++){
                      for(i=0;i<6;i++){ 
                          for(j=0;j<8;j++){
                          
                              Dir=array[j]<<2;
                              
                              lcd_clear();
                              lcd_gotoxy(1,0);
                              sprintf(array1,"%d",array[j]);
                              lcd_puts(array1);
                              delay_ms(speed);
                          }
                      }                  
                  }               
               }                
         
         }



}