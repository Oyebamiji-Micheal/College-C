#include <stdio.h>

int main() {
    char s[1000], res[1000];
    int counter = 0;

    printf("Enter a string: ");
    fgets(s, 1000, stdin);

    while (s[counter] != '\0')
        counter++;
    
    int end = counter - 1;

    for (int i=0; i < counter; i++) {
        res[i] = s[end];
        end--;
    }

    res[counter] = '\0';
    printf("%s\n", res);

    return 0;
}