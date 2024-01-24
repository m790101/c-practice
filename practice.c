#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArray(char text[]);
double cube(double num)
{
    return num * num * num;
}

int max(int num1, int num2)
{
    int result;
    if (num1 > num2)
    {
        result = num1;
    } else {
        result = num2;
    }
    return result;
}

void checkLetter(char letter)
{
    switch (letter)
    {
    case 'a':
        printf("awesome!\n");
        break;
    case 'b':
        printf("you are Asian not Bsian!\n");
        break;
    case 'c':
        printf("such a faluire!\n");
        break;
    default:
        printf("what!?\n");
        break;
    }
}

struct Student{
    char name[10];
    int age;
};

int main(void)
{
    const int num = 5;
    double numDouble = 3.0;
    char testString[] = "john";
    char letter;
    int numWhile = 0;
    int arrayNum[] = {1, 2, 3, 4, 5};
    struct Student john;

    john.age = 32;
    printf("john's age is %d\n", john.age);
    char name[] = "john";
    strcpy(john.name, name);
    printf("john's name is %s\n", john.name);
    // while (numWhile < 5)
    // {
    //     printf("%d\n", numWhile);
    //     numWhile++;
    // }
    // printf("enter your grade:");
    // scanf("%s", &letter);
    // checkLetter(letter);
    // printArray(testString);
    // printf("cube of %.2f is %.2f\n", numDouble, cube(numDouble));
    // printf("max number is %d\n", max(2, 3));
    // double age = 32;
    // char s[] = "hiiii";
    // printf("enter your age:");
    // scanf("%[^\n]",s);
    // printf("%s\n",s);

    return 0;
}


void printArray(char text[])
{
    printf("hello %s\n", text);
}