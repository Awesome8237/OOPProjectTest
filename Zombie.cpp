//
// Created by admin on 5/13/2024.
//
#include "Zombie.h"

bool Zombie::isOutside(){

    if(x > windowSizeX){
        return true;
    }
    else{
        return false;
    }


}