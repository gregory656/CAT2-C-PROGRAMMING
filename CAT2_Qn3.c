#include <stdio.h>
#include <stdlib.h>

// Function to get 10 integers from the user and save to "input.txt"
void write_to_file() {
    FILE *file_ptr;
    int numbers[10];

    file_ptr = fopen("input.txt", "w");
    if (file_ptr == NULL) {
        printf("Error: Could not open input.txt for writing.\n");
        return;
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            i--; // Decrement counter to re-prompt for the same number
            continue;
        }
        fprintf(file_ptr, "%d\n", numbers[i]);
    }

    fclose(file_ptr);
    printf("10 integers have been written to input.txt\n");
}

// Function to read from "input.txt", calculate sum and average, and write to "output.txt"
void process_file() {
    FILE *input_file, *output_file;
    int number, sum = 0, count = 0;
    double average;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        return;
    }

    while (fscanf(input_file, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    fclose(input_file);

    if (count == 0) {
        printf("Error: input.txt is empty or contains no valid integers.\n");
        return;
    }

    average = (double)sum / count;

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output.txt for writing.\n");
        return;
    }

    fprintf(output_file, "Sum: %d\n", sum);
    fprintf(output_file, "Average: %.2f\n", average);

    fclose(output_file);
    printf("Sum and average have been written to output.txt\n");
}

// Function to read and display the contents of both files
void display_files() {
    FILE *input_file, *output_file;
    char ch;

    printf("\n--- Contents of input.txt ---\n");
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
    } else {
        while ((ch = fgetc(input_file)) != EOF) {
            putchar(ch);
        }
        fclose(input_file);
    }

    printf("\n--- Contents of output.txt ---\n");
    output_file = fopen("output.txt", "r");
    if (output_file == NULL) {
        printf("Error: Could not open output.txt for reading.\n");
    } else {
        while ((ch = fgetc(output_file)) != EOF) {
            putchar(ch);
        }
        fclose(output_file);
    }
}

int main() {
    write_to_file();
    process_file();
    display_files();

    return 0;
}