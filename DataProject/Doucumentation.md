

Documentasi singkat tentang tipe data pada C dan operasi yang dapat dilakukan dengan masing-masing tipe data:

### Tipe Data Primitif

1. **Integer**
   - Deskripsi: Menyimpan bilangan bulat.
   - Tipe: `int`, `short`, `long`, `long long`, `unsigned int`, `unsigned short`, `unsigned long`, `unsigned long long`
   - Operasi: Penambahan, pengurangan, perkalian, pembagian, modulo, increment (++) dan decrement (--), perbandingan, bitwise operations (AND, OR, XOR, NOT, shift left, shift right).

2. **Floating Point**
   - Deskripsi: Menyimpan bilangan real.
   - Tipe: `float`, `double`, `long double`
   - Operasi: Penambahan, pengurangan, perkalian, pembagian, perbandingan.

3. **Character**
   - Deskripsi: Menyimpan satu karakter.
   - Tipe: `char`, `unsigned char`, `signed char`
   - Operasi: Penugasan, perbandingan, operasi bitwise.

4. **Boolean**
   - Deskripsi: Menyimpan nilai kebenaran (`true` atau `false`).
   - Tipe: `_Bool` (dengan header `<stdbool.h>` mendefinisikan `true` dan `false`)
   - Operasi: Operasi logika (AND, OR, NOT).

5. **Void**
   - Deskripsi: Menunjukkan ketiadaan tipe.
   - Operasi: Digunakan sebagai tipe pengembalian fungsi yang tidak mengembalikan nilai atau untuk pointer ke memori tanpa tipe.

### Tipe Data Kompleks

1. **Array**
   - Deskripsi: Koleksi elemen dengan tipe yang sama.
   - Operasi: Akses elemen, penugasan, inisialisasi, traversal (menggunakan loop).
   
   ```
   #include <stdio.h>
    int main() {
        int numbers[5] = {1, 2, 3, 4, 5}; // Inisialisasi array

        // Traversal menggunakan loop
        for(int i = 0; i < 5; i++) {
            printf("%d\n", numbers[i]); // Akses dan cetak elemen
        }

        return 0;
    }
   ```

2. **Struct**
   - Deskripsi: Kumpulan variabel (disebut anggota) dengan tipe yang mungkin berbeda.
   - Operasi: Akses anggota, penugasan, inisialisasi.
   ```
    #include <stdio.h>

    typedef struct {
        int id;
        char name[50];
    } Person;

    int main() {
        Person p1; // Deklarasi struct
        p1.id = 1; // Penugasan anggota
        sprintf(p1.name, "%s", "John Doe"); // Penugasan anggota

        printf("ID: %d, Name: %s\n", p1.id, p1.name); // Akses dan cetak anggota
        return 0;
    }

   ```

3. **Union**
   - Deskripsi: Kumpulan variabel yang berbagi lokasi memori yang sama.
   - Operasi: Akses anggota, penugasan, inisialisasi.
   ```
   #include <stdio.h>
    union Data {
        int i;
        float f;
        char str[20];
    };

    int main() {
        union Data data;        
        data.i = 10;
        printf("data.i : %d\n", data.i);

        data.f = 220.5;
        printf("data.f : %f\n", data.f);

        sprintf(data.str, "%s", "C Programming");
        printf("data.str : %s\n", data.str);

        return 0;
    }

   ```

4. **Pointer**
   - Deskripsi: Variabel yang menyimpan alamat memori.
   - Operasi: Dereferensi, penugasan alamat, operasi aritmatika pointer, perbandingan.
   ```
    #include <stdio.h>

    int main() {
        int val = 30;
        int *ptr = &val; // Penugasan alamat

        printf("Value of val : %d\n", *ptr); // Dereferensi dan cetak nilai

        *ptr = 40; // Mengubah nilai melalui pointer
        printf("Value of val : %d\n", val); // Cetak nilai yang diubah

        return 0;
    }

   ```

### Operasi Umum

- **Aritmatika**: `+`, `-`, `*`, `/`, `%` untuk tipe numerik.
- **Perbandingan**: `==`, `!=`, `<`, `>`, `<=`, `>=`.
- **Logika**: `&&`, `||`, `!`.
- **Bitwise**: `&`, `|`, `^`, `~`, `<<`, `>>`.
- **Assignment**: `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`.
- **Akses**: `.` untuk struct, `->` untuk pointer ke struct, `[]` untuk array.
- **Manipulasi Memori**: `malloc`, `calloc`, `realloc`, `free` (memerlukan header `<stdlib.h>`).

### Contoh Kode

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    Person p1 = {1, "John Doe"};
    int *ptr = &numbers[0];

    printf("Array element: %d\n", numbers[2]);
    printf("Person ID: %d, Name: %s\n", p1.id, p1.name);
    printf("Pointer arithmetic: %d\n", *(ptr + 2));

    return 0;
}
```

Documentasi ini memberikan gambaran dasar tentang tipe data dan operasi yang dapat dilakukan dalam bahasa pemrograman C. Untuk penggunaan yang lebih lanjut dan kompleks, akan sangat berguna untuk merujuk pada dokumentasi bahasa C yang lebih lengkap dan detil.


