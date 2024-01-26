#include <stdio.h>


// int fibonacci(int n);
int fibonacci2(int n);

int main(){
    int num;
    printf("pick a number:");
    scanf("%d", &num);
    printf("your number is %d\n", num);
    printf("the fibonacci number is %d\n", fibonacci2(num));
    return 0;
}


// int fibonacci(int n){
//     if (n == 0){
//         return 0;
//     }
//     if (n == 1){
//         return 1;
//     }
//     int fib[100];

//     return fibonacci(n-1) + fibonacci(n-2);
// }

int fibonacci2(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    if (n < 2){
        return fib[n];
    } else {
        int i;
        for(i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    }
    return fib[n];
}