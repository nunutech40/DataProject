//
//  read_datadb.c
//  DataProject
//
//  Created by Nunu Nugraha on 21/02/24.
//

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, const char * argv[]) {
    
    // open file dari textdb
    // baca isi filenya
    // tampilkan
    
    FILE *file;
    char line[256];
    
    // open file
    file = fopen("/Users/nununugraha/Documents/Programming/LearningIOS/DataProject/DataProject/textdb.txt", "r");
    if (file == NULL) {
        perror("Tidak bisa membuka file");
        return 1;
    }
    
    // membaca dan menampilkan file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    // close file
    fclose(file);
    
    return 0;
}
