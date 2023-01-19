#include "timeFunctions.h"
#include "graphics.h"
#include <iostream>
//#include "graphics.cpp"

int main(){
    std::cout<<"lets Get this started";
    int x{0};
    while(true){
        std::cout<<"working";
        ++x;
        if(x == 10000){
            displayWindow();
            break;
        }
    }
}