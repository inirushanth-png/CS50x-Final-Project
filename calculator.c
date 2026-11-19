#include <cs50.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100
#define HISTORY_FILE "history.txt"

// Function declaration
bool read_line(const char *prompt, char *input, size_t size);
bool get_int_input(const char *prompt, int *value);
bool get_double_input(const char *prompt, double *value);

void save_history(const char *operation, double num1, double num2, double result);
void view_history(void);
void display_result(const char *operation, double num1, double num2, double result);

int main(void)
{
    int choice;
    double num1, num2, result;

    while (1)
    {
        printf("\n================================\n");
        printf("   CS50x COMMAND-LINE CALCULATOR\n");
        printf("==================================\n");

        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Power (x^y)\n");
        printf("6. Square Root (sqrt)\n");
        printf("7. View Calculation History\n");
        printf("8. Exit\n");

        printf("----------------------------------------\n");

        if (!get_int_input("Choose an option (1-8): ", &choice))
        {
            printf("\nInput ended. Exiting calculator.\n");
            break;
        }

        // Exit the calculator
        if (choice == 8)
        {
            printf("Exiting calculator. Thanks for using it!\n");
            break;
        }

        // View the calculation history
        if (choice == 7)
        {
            view_history();
            continue;
        }

        // Square root operation.
        if (choice == 6)
        {
            if (!get_double_input("Enter a number: ", &num1))
            {
                printf("\nInput ended. Exiting calculator.\n");
                break;
            }

            if (num1 < 0)
            {
                printf("Error: Cannot calculate the square root of a negative number.\n");
            }
            else
            {
                result = sqrt(num1);
                display_result("Square Root", num1, 0, result);
            }

            continue;
        }

        // Validate menu selection
        if (choice < 1 || choice > 8)
        {
            printf("Invalid option! Please choose between 1 and 8.\n");
            continue;
        }

        // Get two numbers for basic operations
        if (!get_double_input("Enter first number: ", &num1))
        {
            printf("\nInput ended. Exiting calculator.\n");
            break;
        }

        if (!get_double_input("Enter second number: ", &num2))
        {
            printf("\nInput ended. Exiting calculator.\n");
            break;
        }

        // Perform the selected calculation.
        switch (choice)
        {
            case 1:
                result = num1 + num2;
                display_result("Addition", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                display_result("Subtraction", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                display_result("Multiplication", num1, num2, result);
                break;

            case 4:
                if (num2 == 0)
                {
                    printf("Error: Division by zero is not allowed!\n");
                }
                else
                {
                    result = num1 / num2;
                    display_result("Division", num1, num2, result);
                }
                break;

            case 5:
                result = pow(num1, num2);
                display_result("Power", num1, num2, result);
                break;
        }
    }

    return 0;
}

// Read one line of user input
bool read_line(const char *prompt, char *input, size_t size)
{
    printf("%s", prompt);

    if (fgets(input, size, stdin) == NULL)
    {
        return false;
    }

    size_t length = strlen(input);

    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }
    else if (length == size - 1)
    {
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        input[0] = '\0';
    }

    return true;
}

// Get and validate an integer
bool get_int_input(const char *prompt, int *value)
{
    char input[INPUT_SIZE];

    while (1)
    {
        if (!read_line(prompt, input, sizeof(input)))
        {
            return false;
        }

        char *end;
        errno = 0;

        long number = strtol(input, &end, 10);

        while (isspace((unsigned char) *end))
        {
            end++;
        }

        if (end == input || *end != '\0' || errno == ERANGE || number < INT_MIN || number > INT_MAX)
        {
            printf("Invalid input! Please enter a valid integer.\n");
            continue;
        }

        *value = (int) number;
        return true;
    }
}

// Get and validate a decimal number
bool get_double_input(const char *prompt, double *value)
{
    char input[INPUT_SIZE];

    while (1)
    {
        if (!read_line(prompt, input, sizeof(input)))
        {
            return false;
        }

        char *end;
        errno = 0;

        double number = strtod(input, &end);

        while (isspace((unsigned char) *end))
        {
            end++;
        }

        if (end == input || *end != '\0' || errno == ERANGE || !isfinite(number))
        {
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        *value = number;
        return true;
    }
}

// Display a result and save it to calculation history
void display_result(const char *operation, double num1, double num2, double result)
{
    if (!isfinite(result))
    {
        printf("Error: This operation produced an invalid or out-of-range result.\n");
        return;
    }

    printf("Result: %.2f\n", result);

    save_history(operation, num1, num2, result);
}

// Save calculations to history.txt
void save_history(const char *operation, double num1, double num2, double result)
{
    FILE *file = fopen(HISTORY_FILE, "a");

    if (file == NULL)
    {
        printf("Warning: Could not save calculation history.\n");
        return;
    }

    if (strcmp(operation, "Square Root") == 0)
    {
        fprintf(file, "%s of %.2f -> Result: %.2f\n", operation, num1, result);
    }
    else
    {
        fprintf(file, "%s: %.2f, %.2f -> Result: %.2f\n", operation, num1, num2, result);
    }

    fclose(file);
}

// Read and display saved calculation history
void view_history(void)
{
    FILE *file = fopen(HISTORY_FILE, "r");

    if (file == NULL)
    {
        printf("\nNo history found yet.\n");
        return;
    }

    char line[256];
    bool found = false;

    printf("\n=== CALCULATION HISTORY ===\n");

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
        found = true;
    }

    if (!found)
    {
        printf("No calculations saved yet.\n");
    }

    printf("=============================\n");

    fclose(file);
}
