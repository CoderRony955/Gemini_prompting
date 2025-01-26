#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h> // ncurses library for enhanced output

// Function to clear the screen (platform-independent)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


int main() {
    char operator;
    double num1, num2, result;

    // Initialize ncurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters

    // Main calculator loop
    while (1) {
        clearScreen(); // Clear the screen for each operation

        // Display a nicely formatted prompt using ncurses
        mvprintw(1, 1, "Simple Calculator");
        mvprintw(3, 1, "Enter operator (+, -, *, /, %% for modulo, or 'q' to quit): ");
        mvprintw(4,1,"Note: Use 'q' to quit anytime.");
        scanw(" %c", &operator);


        if (operator == 'q' || operator == 'Q') {
            break; // Exit the loop if the user enters 'q'
        }

        mvprintw(5, 1, "Enter two operands: ");
        scanw("%lf %lf", &num1, &num2);

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    mvprintw(7, 1, "Error: Division by zero!");
                    getch(); // Wait for a key press before continuing
                    continue; // Go to the next iteration of the loop
                }
                result = num1 / num2;
                break;
            case '%':
                if (num2 == 0) {
                    mvprintw(7, 1, "Error: Modulo by zero!");
                    getch();
                    continue;
                }
                result = fmod(num1, num2); // Use fmod for floating-point modulo
                break;
            default:
                mvprintw(7, 1, "Error: Invalid operator!");
                getch();
                continue;
        }


        // Display the result using ncurses for better formatting
        mvprintw(7, 1, "Result: %.2lf", result); //format to two decimal places
        mvprintw(9,1,"Press any key to continue...");
        getch(); // Wait for a key press before clearing the screen again.
    }


    // End ncurses mode
    endwin();
    return 0;
}

// To compile and run this code (assuming you have ncurses installed):

// 1. **Compile:**  `gcc your_file_name.c -lncurses -o calculator`  (Replace `your_file_name.c` with your actual filename).
// 2. **Run:** `./calculator`


// This improved version uses `ncurses` for a cleaner, more professional-looking interface.  Error handling is included (division by zero), and the loop continues until the user explicitly quits.  Remember to install the `ncurses` development package if it's not already on your system (e.g., `sudo apt-get install libncurses5-dev` on Debian/Ubuntu, or the equivalent for your distribution).
