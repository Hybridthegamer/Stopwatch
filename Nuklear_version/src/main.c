#include "timeFunctions.h"
#include "graphics.h"
#include <stdio.h>
//#include "graphics.cpp"

int main(){
    printf("lets Get this started");
    int x = 0;
    while(1){
        printf("working");
        ++x;
        if(x == 10000){
            displayWindow();
            break;
        }
    }
}