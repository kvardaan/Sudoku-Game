# Sudoku Game

A simple Sudoku Game implemented in C++ using a backtracking algorithm for solving puzzles.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [How to Use](#how-to-use)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project provides a Sudoku Game implemented in C++. The game includes a Sudoku Solver that uses a backtracking algorithm to find solutions for puzzles.

## Features

- **Backtracking Algorithm**: The solver efficiently explores possible solutions for the Sudoku puzzle using a backtracking approach.
- **User Interface**: The project includes a simple command-line interface to input Sudoku puzzles, play the game, and visualize solutions.

## How to Use

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/kvardaan/Sudoku-Game.git
    ```

2. Compile the source code using a C++ compiler:

    ```bash
    g++ sudoku.cpp -o sudoku_game
    ```

3. Run the executable:

    ```bash
    ./sudoku_game
    ```

4. Follow the on-screen instructions to input a Sudoku puzzle, play the game, and explore solutions.

## Example

Here is an example of how to use the Sudoku Game:

```cpp
#include <iostream>
#include "sudoku.cpp"

int main() {
    int initialGrid[N][N] = {
        // Your Sudoku puzzle here
    };

    SudokuSolver sudoku(initialGrid);
    sudoku.printGrid("Initial");

    if (sudoku.solve())
        sudoku.printGrid("Solved");
    else
        std::cout << "No solution exists";

    return 0;
}
