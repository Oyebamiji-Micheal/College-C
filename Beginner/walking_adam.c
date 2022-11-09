#include <stdio.h>
#include <string.h>


int calculate(char test_input[], int length) {
    int num_u = 0;
    for (int i=0; i<length; i++) {
        if (test_input[i] == 'U') {
            num_u++;
        }
        else {
            return num_u;
        }
    }
    return num_u;
}

int main() {
    int tests;
    char test_input[1000];
    //printf("Enter the number of test cases: ");
    scanf("%d", &tests);

    for (int i=0; i<tests; i++) {
        //printf("Enter test case: ");
        scanf("%s", test_input);
        int length = strlen(test_input);
        int res = calculate(test_input, length);
        printf("%d\n", res);
    } 
    return 0;
}