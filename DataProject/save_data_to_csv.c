//
//  save_data_to_csv.c
//  DataProject
//
//  Created by Nunu Nugraha on 08/03/24.
//

#include <stdio.h>



int main(int argc, const char* argv[]) {
    
    long c, nl;
    
    nl = 0;
    while ((c = getchar()) && c != EOF) {
        nl++;
        if (c == '\n') {
            printf("%ld\n", nl - 1);
            nl = 0;
        }
    }
    
    
    return 0;
}
