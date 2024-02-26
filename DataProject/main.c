//
//  main.c
//  DataProject
//
//  Created by Nunu Nugraha on 21/02/24.
//

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, const char * argv[]) {
    char name[100];
    int age;
    FILE *file;
    
    printf("Masukan nama: ");
    scanf("%99s", name);
    
    printf("Masukan umur: ");
    scanf("%d", &age);
    
    // buka file textdb.txt
    file = fopen("/Users/nununugraha/Documents/Programming/LearningIOS/DataProject/DataProject/textdb.txt", "a");
    if (file == NULL) {
        perror("Error open file"); // Fungsi ini akan mencetak pesan error berdasarkan nilai errno.
            
            // Cek error karena permission
        if (errno == EACCES) {
            printf("Permission denied: Anda tidak memiliki akses untuk menulis ke file ini.\n");
        }
        return 1; // Return an error code
    }
    
    // save datanya ke text
    fprintf(file, "Name: %s, Age: %d\n", name, age);
    
    // Close the file
    fclose(file);
    
    printf("Nama dan Umur sudah di save, silahkan di cek!");
    
    return 0;
}
