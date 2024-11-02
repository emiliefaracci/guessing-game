#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for seeding the random generator with current time
#include <chrono>
#include <thread>
#include <string>
#include <stdexcept>
#include <fstream>

void initializeGame(int &number_to_guess);
bool openInputFile(int argc, char* argv[], std::ifstream &inputFile);
void playGame(int number_to_guess, std::ifstream &inputFile, bool fromFile);
void handleGuess(int user_guess, int number_to_guess, int &attempts);

int main(int argc, char* argv[]) {

    std::srand(std::time(0)); 
    int number_to_guess; 
    initializeGame(number_to_guess); 

    std::ifstream inputFile; 
    bool fromFile = openInputFile(argc, argv, inputFile); 

    playGame(number_to_guess, inputFile, fromFile); 

    if (fromFile) {
        std::cout << "\nOh no, you never guessed the answer...";
        inputFile.close(); 
    }
    return 0; 
}

void initializeGame(int &number_to_guess) {
    number_to_guess = std::rand() % 100 + 1; 
    std::cout << "\nWelcome to my guessing game: " << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\nI've selected a number 1-100, and you have to guess it" << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

}

bool openInputFile(int argc, char* argv[], std::ifstream &inputFile) {
    if (argc >= 2) {
        inputFile.open(argv[1]);
        if (!inputFile) {
            std::cerr << "\nCould not open file: " << argv[1] << std::endl; 
            return false; 
        }
        return true; 
    } else { 
        std::cout << "\nNo input file given, you must guess" << std::endl; 
        return false; 
    }
}

void playGame(int number_to_guess, std::ifstream &inputFile, bool fromFile) {
    int user_guess = 0; 
    int attempts = 0; 
    std::string input; 

    while (true) {
        if (fromFile) {
            if (!(inputFile >> input)) {
                break; 
            }
        } else {
            std::cout << "\nEnter your guess: ";
            std::cin >> input; 
        }

        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            user_guess = std::stoi(input); 
            handleGuess(user_guess, number_to_guess, attempts);
        } catch (std::invalid_argument&) {
            std::cout << "\nInvalid argument, please enter a number." << std::endl; 
        } catch (std::out_of_range&) {
            std::cout << "\nNumber of range, please enter a valid number." << std::endl; 
        }
    }
}

void handleGuess(int user_guess, int number_to_guess, int &attempts) {
    attempts++; 

    if (user_guess < number_to_guess) {
        std::cout << "\nToo low!";
    } else if (user_guess > number_to_guess) {
        std::cout << "\nToo high!";
    } else {
        std::cout << "\nCongrats!";
        exit(0);
    }
}