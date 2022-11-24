#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void calculate(char testcase[100000][20], int no_of_testcases);


int main() {
    FILE *pFile = fopen("files.in", "r");

    char buffer[255];
    char testcase[100000][20];
    int no_of_testcases;

    // remove the first line in buffer
    while(fgets(buffer, 100, pFile) != NULL) {
        break;
    }

    while(fgets(buffer, 100, pFile) != NULL) {
        // check if current line is an integer
        if (sscanf(buffer, "%d", &no_of_testcases) == 1) {
            for(int i = 0; i < no_of_testcases; i++) {
                // remove 'no of test cases' from buffer
                fgets(buffer, 100, pFile);
                // store 'actual test cases' only in string array
                strcpy(testcase[i], buffer);
            }
            // call function responsible for deleting duplicate files
            calculate(testcase, no_of_testcases);
        }
    }
    fclose(pFile); 
    return 0;
}


void calculate(char testcase[100000][20], int no_of_testcases) {
    char filenames[no_of_testcases][10];
    int file_ids[no_of_testcases];
    
    int pointer = 0; // a pointer to adjacent available space in filenames 

    // extract file attributes(filename and id) for each testcase
    for(int i = 0; i < no_of_testcases; i++) {
        bool checker = true; // this variable assumes a file has no duplicate
        int total_n = 0;
        int n, file_id;

        // extract file id from testcase - @credit: Stackoverflow
        while (1 == sscanf(testcase[i] + total_n, "%*[^0123456789]%d%n", &file_id, &n)) {
            total_n += n;
        }

        // extract filename from testcase
        char* filename = strtok(testcase[i], " ");

        // for each testcase check if a file is duplicated 
        for (int j = 0; j < no_of_testcases; j++) {
            if(strcmp(filenames[j], filename) == 0 && file_id < file_ids[j]) {
                // replace file_id with lower id
                file_ids[j] = file_id;
                checker = false; 
            }
        }

        // this block executes if a file has no duplicate 
        if(checker) {
            // add filename to next available location
            strcpy(filenames[pointer], filename);
            // add file_id to corresponding array location 
            file_ids[pointer] = file_id;
            // increment pointer to next available space
            pointer++;
        }
    }

    // sort file_ids - @credit: TutorialsPoint
    int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
    }

    qsort(file_ids, pointer, sizeof(int), cmpfunc);

    // std output: print file_ids  
    for(int k = 0; k < pointer; k++) {
        printf("%d ", file_ids[k]);
    }
    printf("\n");
}