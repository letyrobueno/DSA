/*
  To compile it in Linux (terminal): g++ -o program loops.cpp
  To run it in Linux (terminal): ./program
*/

#include <iostream> 
main(){
    for(int i=0; i<=15; i++)
        std::cout << "Hello World: " << i << std::endl;
    std::cout << std::endl;

    for(int i=0; i<=14; i+=2)
        std::cout << "Hello World: " << i << std::endl;
    std::cout << std::endl;

    for(int i=0; i<=12; i+=4)
        std::cout << "Hello World: " << i << std::endl;
    std::cout << std::endl;
}
