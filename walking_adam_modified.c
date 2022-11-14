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
    FILE *pFile = fopen("adam.in", "r");
    char buffer[100];

    while(fgets(buffer, 100, pFile) != NULL) {
        break;
    }

    while(fgets(buffer, 100, pFile) != NULL) {
        int length = strlen(buffer);
        int res = calculate(buffer, length);
        printf("%d\n", res);
    }

    fclose(pFile);
    return 0;
}