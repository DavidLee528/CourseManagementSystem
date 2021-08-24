#define NDEBUG
#include <iostream>

#include "../include/CMS.h"
#include "../include/interface.h"
#include "../include/data.h"

using std::cout; 
using std::cin; 
using std::endl; 

int main(int argc, char **argv) {

    if (!CInterface::Login()) return 0; 

    return 0; 
}