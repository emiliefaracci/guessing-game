#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for seeding the random generator w/ current time
#include <chrono>
#include <thread>
#include <string> 
#include <stdexcept>
#include <fstream> 


int main(int argc, char* argv[]){

    std::srand(std::time(0));
    int number_to_guess = std::rand() % 100 + 1; //num 1-100
    int user_guess = 0; 
    int attempts = 0;
    std::string input;

    bool fromFile = false; 
    std::ifstream inputFile; 

    if (argc >= 2) {
        inputFile.open(argv[1]);
        if (!inputFile) {
            std::cerr << "\nCould not open the file:" << argv[1] << std::endl; 
            return 1; 
        }
        fromFile = true; 
    } else {
        std::cout << "\nNo input file given, you must guess." << std::endl; 
    }

    std::cout << "\n\n\nWelcome to my guessing game :)" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n\nI've selected a number 1-100, and you have to guess it" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    while (true){

        if (fromFile) {
            if (!(inputFile >> input)) {
                break; 
            }
        } else {
            std::cout << "\n\nEnter your guess: "; 
            std::cin >> input; 
        }
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            user_guess = std::stoi(input);
            attempts++; 
            if (user_guess < number_to_guess){
                std::cout << "\nToo low! come on... try again!";
            } else if (user_guess > number_to_guess) {
                std::cout << "\nToo big! come on... try again!";
            } else {
                std::cout << "\nCongrats!!!!!";
                break; 
            }
        } catch (std::invalid_argument&) {
            std::cout << "\nInvalid argument"; 
        } catch (std::out_of_range&) {
            std::cout << "\nNum out of range";
        }  
    }

    if (fromFile) {
        std::cout << "\n\n\nOh no, you never guessed the right answer.... try again next time!\n\n\n";
        inputFile.close();
    }
    return 0; 
}