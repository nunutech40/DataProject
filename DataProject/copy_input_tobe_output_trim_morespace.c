//
//  copy_input_tobe_output_trim_morespace.c
//  DataProject
//
//  Created by Nunu Nugraha on 08/03/24.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
    int c;
    char tulisan[100];
    int counterChar = 0;
    int counterBlank = 0;

    while ((c = getchar()) != EOF) {

        if (c == (32)) {
            counterBlank ++;
        } else if (c == '\n') {
            tulisan[counterChar] = '\0';
            printf("%s\n", tulisan);
            counterChar = 0;
            counterBlank = 0;
        } else {
            if (counterBlank > 0) {
                tulisan[counterChar] = (32);
                counterChar ++;
                counterBlank = 0;
            }
            tulisan[counterChar] = c;
            counterChar ++;
        }
        
    }
    return 0;
}
