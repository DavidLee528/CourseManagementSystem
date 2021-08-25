/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */
#define NDEBUG
#include <iostream>

#include "../include/CMS.h"
#include "../include/interface.h"
#include "../include/data.h"

int main(int argc, char **argv) {

    if (!CInterface::Login()) return 0; 

    return 0; 
}