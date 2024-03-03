//
//  testing2.c
//  DataProject
//
//  Created by Nunu Nugraha on 02/03/24.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    
    char nama[100];
    int age;
    int *umur;
    strcpy(nama, "Nunu");
    printf("cek data nama: %s\n", nama);
    
    printf("Cek data alamat memory dari nama: %p\n", (void *)nama); // cek alamat memorynya
    
    age = 33;
    printf("Agenya: %d\n", age);
    printf("Cek alamat memory dari Age: %p\n", (void *)&age);
    
    umur = &age;
    printf("Umurnya: %d\n", *umur);
    printf("Cek alamat memory dari umur: %p\n", (void *)&umur);
    
    
    return 0;
}
