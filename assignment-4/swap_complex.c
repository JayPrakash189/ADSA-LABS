#include <stdio.h>

struct complex
{
    int real;
    int imaginary;
};

int main()
{
    struct complex a = {3, 5};
    printf("Actual: %di + %dj\n", a.real, a.imaginary);

    int temp_real = a.real;
    int temp_imaginary = a.imaginary;
    a.real = temp_imaginary;
    a.imaginary = temp_real;

    printf("Swapped: %di + %dj", a.real, a.imaginary);
}