//
//  menu_dan_exit.c
//  DataProject
//
//  Created by Nunu Nugraha on 28/02/24.
//

#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    int umur;
} Person;

int main(int argc, const char * argv[]) {
    
    // tampilkan menu
    int menu = 1;
    int umur;
    char nama[26];
    Person persons[26];
    int personCount = 0;
    
    do {
        printf("Pilih menu: \n");
        printf("1. Masukan data diri\n");
        printf("2. Cek Data Diri yang sudah direkap\n");
        printf("3. Exit\n");
        scanf("%d", &menu);
            
        // bersihkan buffer input
        while (getchar() != '\n');
        
        if (menu == 1) {
            printf("Masukan Nama:\n");
            scanf("%25s", nama);
            
            printf("Masukan umur:\n");
            scanf("%d", &umur);
            
            
            
            // bersihkan buffer input
            while (getchar() != '\n');
            printf("Nama anda %25s, dan umur anda %d telah di saved!\n", nama, umur);
            personCount ++;
            
            Person newPerson;
            strcpy(newPerson.nama, nama); // salin data dari nama ke data tujuan adalah newPerson nama
            newPerson.umur = umur;
            persons[personCount] = newPerson;
        } else if (menu == 2) {
            printf("Daftar data diri:\n");
            printf("%-30s | %-10s\n",  "Nama", "Umur"); // %-30S adalah rata kiri untuk 30 maksimal 30 karakter.
            printf("-----------------------------------------\n");
            
            for (int i = 0; i <= personCount; i++) {
                printf("%-30s | %-10d\n", persons[i].nama, persons[i].umur);
            }
        }
        
    } while (menu != 3);
    
    
    return 0;
}
