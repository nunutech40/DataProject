//
//  read_char.c
//  DataProject
//
//  Created by Nunu Nugraha on 06/03/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int c;
    
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    
    return 0;
}
