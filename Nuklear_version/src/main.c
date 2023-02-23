#include "timeFunctions.h"
#include "graphics.h"
#include <stdio.h>
/*#include "graphics.cpp"**/
int x = 0;
int main(){
    while(1){
        ++x;
        if(x == 10000){
            displayWindow();
            break;
        }
    }
    return 0;
}