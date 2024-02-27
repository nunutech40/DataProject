//
//  array_c.c
//  DataProject
//
//  Created by Nunu Nugraha on 27/02/24.
//

#include <stdio.h>



int main(int argc, const char * argv[]) {
    int numbers[5] = {};
    int value = 0;
    
    
    for (int i = 0; i < 5; i++) {
        printf("Masukan data ke %d: ", i);
        scanf("%d", &value);
        
        if (value < 0 && value > 100) {
            printf("Silahkan ulang salah masukan data");
            return 1;
        }
        numbers[i] = i;
    }
    
    return 0;
}

