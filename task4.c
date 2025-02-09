#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a file using Run-Length Encoding (RLE)
void compress(FILE *input, FILE *output) {
    char current_char, next_char;
    int count;

    current_char = fgetc(input);  // Read the first character
    while (current_char != EOF) {
        count = 1;  // Initialize count for each character
        next_char = fgetc(input);  // Read the next character
        while (next_char == current_char) {
            count++;
            next_char = fgetc(input);
        }
        // Write the character and count to the output file
        fprintf(output, "%d%c", count, current_char);

        // Move to the next character
        current_char = next_char;
    }
    printf("\nCompression completed.\n");
}

// Function to decompress a file that has been compressed using RLE
void decompress(FILE *input, FILE *output) {
    int count;
    char current_char;

    while (fscanf(input, "%d%c", &count, &current_char) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(current_char, output);  // Write the character 'count' times
        }
    }
    printf("\nDecompression completed.\n");
}

// Function to display the contents of a file
void displayFileContent(FILE *file) {
    rewind(file); // Move the file pointer to the beginning
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to the console
    }
    printf("\n");
}

int main() {
    int choice;
    char filename[100];

    // Ask the user whether to compress or decompress
    printf("Choose operation:\n1. Compress a new file\n2. Decompress an existing file\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // Consume any leftover newline character in buffer

    if (choice == 1) {
        // Compression: Create a new file and compress it
        printf("Enter the name of the new file to create and compress: ");
        scanf("%s", filename);
        getchar(); // Consume newline

        FILE *input = fopen(filename, "w+");  // Open for writing and reading
        if (input == NULL) {
            printf("Error opening the file!\n");
            return 1;
        }

        // Ask the user to enter content to write to the file
        printf("Enter content for the file (Type 'exit' to stop):\n");
        char line[100];
        while (1) {
            printf("Enter line: ");
            fgets(line, sizeof(line), stdin);
            if (strncmp(line, "exit", 4) == 0) {
                break;
            }
            fputs(line, input);  // Write the line to the file
        }

        // Show the content before compression
        printf("\nOriginal content of the file:\n");
        displayFileContent(input);

        // Open the output file for compression
        FILE *output = fopen("compressed.txt", "w");
        if (output == NULL) {
            printf("Error creating compressed file!\n");
            fclose(input);
            return 1;
        }

        // Rewind input file for reading and compress it
        rewind(input);
        compress(input, output);
        fclose(output);
        fclose(input);

        // Show the compressed file content
        printf("\nCompressed content of the file (compressed.txt):\n");
        output = fopen("compressed.txt", "r");
        displayFileContent(output);
        fclose(output);

    } else if (choice == 2) {
        // Decompression: Read an existing compressed file
        printf("Enter the name of the compressed file to decompress: ");
        scanf("%s", filename);
        getchar(); // Consume newline

        FILE *input = fopen(filename, "r");
        if (input == NULL) {
            printf("Error opening the compressed file! Make sure it exists.\n");
            return 1;
        }

        FILE *output = fopen("decompressed.txt", "w");
        if (output == NULL) {
            printf("Error creating decompressed file!\n");
            fclose(input);
            return 1;
        }

        // Perform decompression
        decompress(input, output);
        fclose(output);
        fclose(input);

        // Show the decompressed file content
        printf("\nDecompressed content of the file (decompressed.txt):\n");
        output = fopen("decompressed.txt", "r");
        displayFileContent(output);
        fclose(output);

    } else {
        printf("Invalid choice! Please enter 1 for compression or 2 for decompression.\n");
    }

    return 0;
}
