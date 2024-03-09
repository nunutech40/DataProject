//
//  count_row.c
//  DataProject
//
//  Created by Nunu Nugraha on 09/03/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file;
    char *path = "/Users/nununugraha/Documents/Programming/LearningC/DataProject/DataProject/db_text.txt";
    int counterNewLine = 0;
    int ch;
    
    file = fopen(path, "r"); // open file dan baca
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) { // baca char
        if (ch == '\n') {
            counterNewLine ++;
        }
    }
    fclose(file);
    
    printf("Baris dari file ini adalah: %d\n", counterNewLine);
    
    return 0;
}
