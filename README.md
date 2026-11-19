# CS50x Command-Line Calculator

#### Video Demo: https://youtu.be/T16xoXG4Bm8

#### Description:

## Introduction

The CS50x Command-Line Calculator is a command-line application written in the C programming language. I developed this project as my final project for CS50's Introduction to Computer Science.

The main purpose of this application is to perform mathematical calculations through a simple menu-driven interface. Instead of using a graphical interface, users interact with the program through the terminal. The program displays a menu of available mathematical operations, accepts user input, performs the selected calculation, and displays the result.

I chose to develop a calculator because it allowed me to apply several programming concepts I learned during CS50x, including variables, functions, loops, conditional statements, switch statements, input validation, and file handling.

## Features

The calculator provides eight menu options:

1. **Addition:** Adds two numbers and displays their sum.
2. **Subtraction:** Subtracts the second number from the first number.
3. **Multiplication:** Multiplies two numbers.
4. **Division:** Divides the first number by the second number. It also checks for division by zero to prevent invalid calculations.
5. **Power:** Calculates the result of raising one number to the power of another number.
6. **Square Root:** Calculates the square root of a given number and prevents calculations involving negative inputs.
7. **Calculation History:** Allows users to view previously saved calculations.
8. **Exit:** Allows users to exit the application.

The calculator uses the `double` data type to support decimal numbers. Results are displayed with two decimal places. The program continues running in a loop, allowing users to perform multiple calculations without restarting the application.

## How the Program Works

When the program starts, it displays a menu containing the eight available options. The user selects an operation by entering its corresponding number.

Depending on the selected operation, the program requests one or two numerical inputs. A `switch` statement determines which mathematical operation should be performed. The program then calculates and displays the result.

For mathematical operations such as square root and power, I use functions from the C mathematics library, including `sqrt()` and `pow()`.

I also use separate functions to handle input, validate values, display results, and manage calculation history. This keeps the program organized and separates different responsibilities into individual functions.

## Input Validation and Error Handling

An important part of this project is handling invalid user input and mathematical errors.

Instead of relying only on `scanf()`, I use `fgets()` to read user input as a line of text. The program then uses `strtol()` and `strtod()` to convert the input into integers and decimal numbers. This approach helps identify invalid entries and prevents incorrect input from being used in calculations.

The program also checks for situations such as division by zero, square roots of negative numbers, and mathematical operations that produce invalid or out-of-range results.

For example, if a user attempts to divide a number by zero, the program displays an error message instead of performing the division. Invalid menu selections and invalid numerical inputs are also handled without terminating the application unexpectedly.

## Calculation History and File Handling

I wanted the calculator to preserve previous calculations instead of displaying results only during the current session.

For this purpose, the program uses a text file called `history.txt`. Whenever a calculation is completed successfully, the `save_history()` function opens the file in append mode and stores the operation, input values, and result.

I chose a text file instead of a database because this project is a small command-line application and does not require a complex storage system.

The `view_history()` function opens the history file in read mode and displays the saved records in the terminal. This allows users to review their previous calculations, even after closing and restarting the application.

The history file is created automatically when the program successfully saves its first calculation.

## Project Files

**calculator.c:** This is the main C source file. It contains the `main()` function, the menu system, mathematical operations, input handling, validation, and calculation history functionality. It also includes separate functions such as `read_line()`, `get_int_input()`, `get_double_input()`, `display_result()`, `save_history()`, and `view_history()`.

**history.txt:** This text file stores the user's calculation history. It is generated automatically by the program when the first successful calculation is saved.

**README.md:** This document describes the project, its features, implementation, design decisions, and instructions for running the application.

## Design Decisions

I decided to use a menu-driven interface instead of requiring users to enter complete mathematical expressions. This makes the application easier to navigate and allows each operation to be handled separately.

I used a `while` loop so that users can perform multiple calculations during one session. I chose a `switch` statement to organize the different mathematical operations and make the program easier to understand.

I also divided the program into separate functions instead of placing all the code inside `main()`. This improves the organization of the source code and makes individual parts easier to understand and maintain.

Another important decision was to use `fgets()`, `strtol()`, and `strtod()` for input handling. This allows the program to validate user input more carefully than simply reading values with `scanf()`.

Finally, I chose a text file for calculation history because it provides a simple way to preserve information between program sessions without introducing unnecessary database complexity.

## Requirements and How to Run

The project is written in C and is designed to run in a command-line environment. It uses standard C libraries and the C mathematics library.

In the CS50 Codespace, when the source file is named `calculator.c`, compile the program using:

    make calculator

Then execute it using:

    ./calculator

The menu will appear in the terminal, and users can begin performing calculations.

## Conclusion

Developing this project allowed me to combine several programming concepts into one functional C application. Through mathematical operations, input validation, functions, loops, conditional statements, and file handling, I gained practical experience in building a command-line program.

This project also helped me understand the importance of organizing code, handling unexpected input, and designing a program that can preserve data between sessions.
