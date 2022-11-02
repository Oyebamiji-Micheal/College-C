#include <stdio.h>

int main() {

    int counter;
    printf("Enter the value of N: ");
    scanf("%d", &counter);

    for(int i=1; i <= counter; i++) {
        printf("%d\n", i);
    }
    return 0;
}