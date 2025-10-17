#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

float x;
float* coefficients;
int counter;
int i;
float* results;

int main(int argc, char** argv) {

    FILE* file = fopen("test.txt", "rb");
    fscanf(file, "%f\n", &x); x=2;
    int position = ftell(file);

    while (1) {
        int character = getc(file);
        if (character == ' ' || character == '\n' || character == '\r' || character == EOF) {
            counter++;
            if (character == '\n' || character == '\r' || character == EOF) break;
        }
    }
    coefficients = (float*) calloc(counter, sizeof (float));
    fseek(file, position, SEEK_SET);
    i = counter-1;

    while (true) {
        char character = getc(file);
        char* current = NULL;

        if (character == ' ' || character == '\n' || character == '\r' || character == EOF) {
            int arg_size = ftell(file) - position;
            current = (char*) calloc(1, arg_size + 1);
            fseek(file, position, SEEK_SET);
            fread(current, arg_size, 1, file);
            sscanf(current, "%f", &coefficients[i--]);
            free(current);
            position = ftell(file);
            if (character == '\n' || character == '\r' || character == EOF) break;
        }
    }
    fclose(file);

    results = (float*) calloc(counter, sizeof (float));
    results[0] = coefficients[0];
    printf("%f\t| \t\t| %f\n", coefficients[0], results[0]);
    for (int i = 1; i != counter; ++i) {
        results[i] = coefficients[i] + results[i - 1] * x;
        printf("%f\t| %f\t| %f\n", coefficients[i], results[i - 1], results[i]);
    }

    printf("W%u(%f) = %f", counter - 1, x, results[counter - 1]);
    return 0;
}
