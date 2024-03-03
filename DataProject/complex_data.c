//
//  complex_data.c
//  DataProject
//
//  Created by Nunu Nugraha on 02/03/24.
//

#include <stdio.h>
#include <stdbool.h>

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
    int *yearsOfExperience;
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
        .yearsOfExperience = &experience,
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
    printf("Penglaman ngoding %d tahun\n", person.yearsOfExperience ? *person.yearsOfExperience : 0);
    
}


int main(int argc, const char *argv[]) {
    
    
    return 0;
}
