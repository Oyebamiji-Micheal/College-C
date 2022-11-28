#include <stdio.h>

int main() {
    int val = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            val = i * j;
            printf("%d x %d = %d", i, j, val);
            printf("\n");
        }
    }
    return 0;
}