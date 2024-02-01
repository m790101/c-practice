#include <stdio.h>
int getFibonacci(int n);

int main()
{

    int n;
    printf("enter a number:");
    scanf("%d", &n);
    int result = getFibonacci(n);
    printf("result is %d\n", result);
}

int getFibonacci(int n)
{
    // fibonacci(3) = fibonacci(2) + fibonacci(1)

    // setting a array with size n + 1 for storing results
    int fibonacci[n + 1];

    // when n = 0 or 1, the result is 0 or 1
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // for loop from i = 2 to n
    int i;
    // if n=4 first time i = 2 fibonacci[2] = fibonacci[1] + fibonacci[0] = 1
    // n =3 i = 3 fibonacci[3] = fibonacci[2] + fibonacci[1] = 2
    // n=4 fibonacci[4] = fibonacci[3] + fibonacci[2] = 3
    if (n >= 2)
    {
        for (i = 2; i <= n; i++)
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }

    return fibonacci[n];
}
