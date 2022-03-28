/*
 Si crei un programma che sfrutti i timer
 e la comunicazione seriale. 
 Il programma dovrà mostrare a video il tempo intercorso 
 tra la pressione e il rilascio del pulsante 
 sia in microsecondi sia in millisecondi 
 sfruttando le due funzioni messe a disposizione 
 dalla libreria "mbed.h" .read_ms() e .read_us().
 */

#include "mbed.h"

DigitalIn button(USER_BUTTON);
Serial pc(SERIAL_TX, SERIAL_RX);
Timer timer;

int main(){
        
    while(true){
    
        while(button.read() == 0){
            timer.start();
            }   
                
        if(button.read() == 1 && timer.read_us() > 0){
            timer.stop();
            pc.printf("Il bottone è stato premuto per: %d microsecondi\r\n", timer.read_us());
            pc.printf("Il bottone è stato premuto per: %d millisecondi\r\n", timer.read_ms());
            timer.reset();
            }
        }
        
        return 0;
    }

