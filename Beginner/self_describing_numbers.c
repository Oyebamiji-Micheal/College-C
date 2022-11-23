#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int counter(char buffer[15], int real_length, int number);

const char* compare(char buffer[15], int number_count[15], int real_length);

int main() {
    FILE *pFile = fopen("self.in", "r");
    char buffer[15];

    // remove first buffer from file in buffer
    while (fgets(buffer, 15, pFile) != NULL) {
        break;
    }
   
    while (fgets(buffer, 15, pFile) != NULL) {
         // get the actual length of each testcase
        int temp_length = strlen(buffer);
        int real_length = 0;
        for (int i = 0; i < temp_length; i++) {
            if(buffer[i] != '\n') {
                real_length++;
            }
        }

        /* store the number of occurences of integers in the range 0 to 'real_length'
        into an integer array
        */
        int number_count[real_length]; 
        for(int j = 0; j < real_length; j++) {
            int no_of_occurences = counter(buffer, real_length, j);
            number_count[j] = no_of_occurences;
        }

        // compare original testcase with 'number_count' 
        // testcase is self describing if both are equal
        // testcase is not self describing otherwise
        const char* answer = compare(buffer, number_count, real_length);
        printf("%s\n", answer);
    }
    return 0;
}

// count the number of times a specific number occur in an array
int counter(char buffer[15], int real_length, int number) {
    int no_of_occurences = 0;

    for (int i = 0; i < real_length; i++) {
        // convert number into char
        // nb: number will always be in the range 0 to 9 inclusive
        char temp_number = number + '0';
        if(buffer[i] == temp_number) {
            no_of_occurences++;
        }
    }
    return no_of_occurences;
}


const char* compare(char buffer[15], int number_count[15], int real_length) {
    for(int k = 0; k < real_length; k++) {
        char temp_number = number_count[k] + '0';
        if(buffer[k] != temp_number) {
            return "Not self-describing";
        }
    }
    return "Self-describing";
}