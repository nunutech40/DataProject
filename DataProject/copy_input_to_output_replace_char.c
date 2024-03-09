//
//  copy_input_to_output_replace_char.c
//  DataProject
//
//  Created by Nunu Nugraha on 09/03/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c;
    char tulisan[100];
    int counter = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == (9)) { // Tab
            tulisan[counter++] = '\\';
            tulisan[counter++] = 't';
        } else if (c == (8)) { // Backspace
            tulisan[counter++] = '\\';
            tulisan[counter++] = 'b';
        } else if (c == '\\') { // Backslash
            tulisan[counter++] = '\\';
            tulisan[counter++] = '\\';
        }
        
        tulisan[counter] = c;
        counter ++;
        if (c == '\n') {
            tulisan[counter] = '\0';
            printf("%s\n", tulisan);
            counter = 0;
        }
        
    }
    
    return 0;
}
