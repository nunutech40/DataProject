//
//  save_complex_data_to_txt.c
//  DataProject
//
//  Created by Nunu Nugraha on 03/03/24.
//


#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    bool isMarried;
    float height;
    double weight;
    char gender;                // char 1
    short numberOfChildren;     // short integer
    long salary;                // Long integer
    unsigned int zipCode;
    int yearsOfExperience;
    void *anyData;
} Person;

void printPerson(void) {
    
    int experience = 6;
    Person person = {
        .name = "Jhon Doe",
        .age = 33,
        .isMarried = true,
        .height = 178.0,
        .weight = 90.0,
        .gender = 'M',
        .numberOfChildren = 2,
        .salary = 8000000,
        .zipCode = 53371,
        .yearsOfExperience = experience,
    };
    
    printf("Nama: %s\n", person.name);
    printf("Umur: %d\n", person.age);
    if (person.isMarried) {
        printf("Sudah menikah\n");
    } else {
        printf("Belum menikah\n");
    }
    printf("Tinggi badan: %2f KG\n", person.height);
    printf("Berat badan: %2f KG\n", person.weight);
    if (person.gender == 'M') {
        printf("Seorang laki-laki\n");
    } else {
        printf("Seorang wanita\n");
    }
    printf("Memiliki %d anak\n", person.numberOfChildren);
    printf("Gaji: %ld rupiah\n", person.salary);
    printf("Zip code: %u\n", person.zipCode);
    printf("Penglaman ngoding %d tahun\n", person.yearsOfExperience);
    
}


int main(int argc, const char *argv[]) {
    
    Person person;
    int menu = 1;
    FILE *file;
    char *path = "/Users/nununugraha/Documents/Programming/LearningC/DataProject/DataProject/db_text.txt";
    char buffer[255];
    
    do {
        printf("Pilih menu yang akan dilakukan!\n");
        printf("1. Isi data diri\n");
        printf("2. Lihat data diri\n");
        printf("3. Exit\n");
        
        scanf("%d", &menu);
        while (getchar() != '\n');
        
        if (menu == 1) {
            // get input name
            printf("Masukan nama:\n");
            scanf("%s", person.name);
            
            // get input age
            printf("Masukan umur:\n");
            scanf("%d", &person.age);
            
            while (getchar() != '\n');
            // get input married status
            printf("isMarriedYes? Y/N: \n");
            char input;
            scanf("%c", &input);
            if (input == 'Y') {
                person.isMarried = true;
            } else {
                person.isMarried = false;
            }
            
            // get data height
            printf("Masukan tinggi badan: \n");
            scanf("%f", &person.height);
            
            // get data weight
            printf("Masukan berat badan: \n");
            scanf("%lf", &person.weight);
            
            while (getchar() != '\n');
            // get data gender char M or W
            printf("Pilih gender M/W: \n");
            scanf("%c", &person.gender);
            
            // get data number of childer short
            printf("Berapa anaknya? \n");
            scanf("%hd", &person.numberOfChildren);
            
            // get data salary long
            printf("Besar gaji? \n");
            scanf("%ld", &person.salary);
            
            // get data zipCode unsigned char
            printf("Masuka zipCode \n");
            scanf("%u", &person.zipCode);
            
            printf("Sudah kerja berapa lama? \n");
            // Menggunakan person.yearsOfExperience tanpa & karena sudah merupakan alamat
            scanf("%d", &person.yearsOfExperience);
            
            // Mencoba membuka file dengan mode "a+" yang berarti:
            // - Jika file sudah ada, file akan dibuka dan penulisan akan dilakukan di akhir file.
            // - Jika file tidak ada, file baru akan dibuat.
            file = fopen(path, "a+");
            if (file == NULL) {
                perror("Error opening/creating file");
                return 1;
            }
            
            // Posisikan pointer pembacaan file ke akhir file.
            // memposisikan pointer di akhir file berarti nge cek, ada datanya tidak.
            fseek(file, 0, SEEK_END);
            
            // Dapatkan posisi pointer sekarang (yang akan sama dengan ukuran file)
            // dan simpan dalam variabel fileSize.
            long fileSize = ftell(file);
            if (fileSize == 0) {
                //tulis header jika 0 / kosong
                fprintf(file, "%-30s | %-10s | %-10s | %-10s | %-10s | %-10s | %-20s | %-20s | %-10s | %-10s\n",
                        "Nama", "Umur", "Menikah", "Tinggi", "Berat", "Gender", "Jml Anak", "Gaji", "Kode Pos", "Thn Pengalaman");
                for(int i = 0; i < 144; i++) {
                    fputc('-', file);
                }
                fprintf(file, "\n");
            }
            
            // Tulis data ke file
            fprintf(file, "%-30s | %-10d | %-10s | %-10.2f | %-10.2f | %-10c | %-20d | %-20ld | %-10u | %-10d\n",
                    person.name,
                    person.age,
                    person.isMarried ? "true" : "false",
                    person.height,
                    person.weight,
                    person.gender,
                    person.numberOfChildren,
                    person.salary,
                    person.zipCode,
                    person.yearsOfExperience);
            
            fclose(file); // Jangan lupa menutup file
            
        } else if (menu == 2) {
            // open file db_text.txt
            file = fopen(path, "r");
            if (file == NULL) {
                perror("Error opening file");
                return 1;
            }
            
            // baca header
            if (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            } else {
                // Jika gagal membaca header, mungkin file kosong atau terjadi error
                printf("Tidak bisa membaca header atau file kosong.\n");
                fclose(file);
                return 1;
            }
            
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
        }
        
    } while (menu != 3);
    return 0;
}
