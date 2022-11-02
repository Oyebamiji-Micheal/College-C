#include <stdio.h>
#include <string.h>


int main() {

    char name[50];

    for(int i=10; i>0; i--) {
        printf("Enter student name (%d remaining): ", i);
        fgets(name, 50, stdin);
        name[strlen(name)-1] = '\0';
        printf("%s accepted!\n", name);
    }

    printf("You have successfully entered all names!\n");
    return 0;

}