//
//  baca_inputan.c
//  DataProject
//
//  Created by Nunu Nugraha on 28/02/24.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char nama[26];
    printf("Masukan nama kamu! \n");
    fgets(nama, sizeof(nama), stdin); // membaca inputan termasuk spasi
    
    // hapus newline di akhir string
    size_t len = strlen(nama);
    if (len > 0 && nama[len - 1] == '\n'){ // cari spasi
        nama[len - 1] = '\n'; // hapus newline
    }
    
    printf("Nama kamu adalah %s\n", nama);
    return 0;
}
