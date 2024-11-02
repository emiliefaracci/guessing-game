# Guessing Game

Welcome to the Guessing Game! In this project, you will guess a randomly chosen number between 1 and 100. 

## Overview

This game allows you to either input guesses manually or read them from a file. You’ll receive feedback on each guess until you find the correct number or run out of guesses.

## Getting Started

1. **Clone the Repository**: 
   ```bash
   git clone https://github.com/yourusername/guessing-game.git
   cd guessing-game
   ```

2. **Compile the Code**: 

    ```g++ guessing_game.cpp -o guessing_game```

3. **Run the Game**: 

Manual Input:
```./guessing_game```

From a File: 
Prepare a text file with your guesses (one per line) and run:
bash
```./guessing_game guesses.txt```

4. **Make Your Guess**: 

Follow the prompts to enter your guess. You’ll receive hints if your guess is too low or too high.

## Features
- Random number generation for unique gameplay.
- Interactive user input or file-based guessing.
- Real-time feedback for each guess.
- Error handling for invalid input.

## Requirements
A C++ compiler (e.g., g++, clang++ for Mac)

## Tips for Success
Start guessing around 50 to narrow down the range quickly.
If using a file, ensure your guesses are reasonable. (There won't be feedback)

## Enjoy the Game!
Thank you for checking out the Guessing Game. Have fun guessing!
