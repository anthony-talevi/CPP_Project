#include <iostream>
int main(){
    std::cout << "Welcome!  Which version would you like to play?" << std::endl;
    std::cout << "Enter '0' for Qwinto, enter '1' for Qwixx" << std::endl;
    char game;
    while(true){
        std::cin >> game;

        if(game=='0'){
            std::cout << "Qwinto Selected" << std::endl;
            break;
        }
        else if(game=='1'){
            std::cout << "Qwixx Selected" << std::endl;
            break;
        }
        else{
            std::cout << "Invalid input.  Try again." << std::endl;
        }
    }
}
