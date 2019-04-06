#include <stdio.h>
#include "header.cpp"


int main () {
    if(wiringPiSetup() == -1)
        return 0;

    int left_IR = 0;
    int right_IR = 0;
 
    while (1) {
        left_IR = digitalRead(LEFT_IR_PIN);
        right_IR = digitalRead(RIGHT_IR_PIN);
        
        while(!left_IR) {
            printf("going right\n");
            //go_right();
            delay(100);
            left_IR = digitalRead(LEFT_IR_PIN);
        }
        
        while(!right_IR){
            printf("going left\n");
            //go_left();
            delay(100);
            right_IR = digitalRead(RIGHT_IR_PIN);
        }
        //go_forward();
        delay(100);
        printf("goint straight\n");
    
    return 1;
}
