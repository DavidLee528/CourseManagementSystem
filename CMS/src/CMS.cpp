#include <iostream>

#include "../include/CMS.h"
#include "../include/interface.h"

int main(int argc, char **argv) {

    if (!CInterface::Login()) return 0; 
    CInterface::rMain(); 

    return 0; 
}