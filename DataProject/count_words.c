//
//  count_words.c
//  DataProject
//
//  Created by Nunu Nugraha on 09/03/24.
//

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, const char * argv[]  ) {
    int c, counterW, state;
    counterW = 0;
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') { // state berubah out ketika saat pertama jalan, dan ketika masuk ke spek di atas
            state = OUT;
        } else if (state == OUT) { // jadi cuma nge hitung ketika statenya berubah dari out ke in
            state = IN; // jadi saat berubah dari out ke in, setelah spasi, tab atau new line berarti, kita menghitung satu kata.
            counterW ++;
        }
    }
    printf("cek berapa banyak kata: %d\n", counterW);
    return 0;
}
