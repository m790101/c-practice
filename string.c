#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "akins";
    int length = strlen(name);
    printf("length of name is %d\n", length);
    char nameCopy[50];
    strcpy(nameCopy, name);

    printf("nameCopy is %s\n", nameCopy);

    return 0;
}
