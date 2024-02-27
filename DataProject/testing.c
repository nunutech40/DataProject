//
//  testing.c
//  DataProject
//
//  Created by Nunu Nugraha on 27/02/24.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char birthDate[11]; // Format: YYYY-MM-DD
    char city[50];
    unsigned char math;
    unsigned char english;
    unsigned char logic;
    unsigned char bahasaIndonesia;
    unsigned char softwareEngineering;
    unsigned char computerScience;
    unsigned char writing;
    unsigned char advertising;
    unsigned char copywriting;
    unsigned char publicSpeaking;
} PersonData;

PersonData people[100];
int peopleCount = 0;

bool isValidScore(int score) {
    return score >= 1 && score <= 100;
}

void inputScore(const char* subject, unsigned char* score) {
    int tempScore;
    printf("Enter %s score (1-100): ", subject);
    scanf("%d", &tempScore);
    while (!isValidScore(tempScore)) {
        printf("Invalid score. Please enter a value between 1 and 100: ");
        scanf("%d", &tempScore);
    }
    *score = (unsigned char)tempScore;
}

void inputdata() {
    if (peopleCount >= 100) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", people[peopleCount].name);
    printf("Enter birth date (YYYY-MM-DD): ");
    scanf("%s", people[peopleCount].birthDate);
    printf("Enter city: ");
    scanf("%s", people[peopleCount].city);

    inputScore("math", &people[peopleCount].math);
    inputScore("English", &people[peopleCount].english);
    inputScore("logic", &people[peopleCount].logic);
    inputScore("Bahasa Indo", &people[peopleCount].bahasaIndonesia);
    inputScore("software engineering", &people[peopleCount].softwareEngineering);
    inputScore("computer science", &people[peopleCount].computerScience);
    inputScore("writing", &people[peopleCount].writing);
    inputScore("advertiser", &people[peopleCount].advertising);
    inputScore("copywriter", &people[peopleCount].copywriting);
    inputScore("public speaking", &people[peopleCount].publicSpeaking);
    
    peopleCount++;
    printf("Data saved.\n");
}

void lihatdata() {
    if (peopleCount == 0) {
        printf("No data available.\n");
        return;
    }
    for (int i = 0; i < peopleCount; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Birth Date: %s\n", people[i].birthDate);
        printf("City: %s\n", people[i].city);
        printf("Math: %d\n", people[i].math);
        printf("English: %d\n", people[i].english);
        // Print other fields as needed
        printf("\n");
    }
}

// Placeholder for editdata and caridata functions
// Implement these functions as needed

int main() {
    int choice;
    do {
        printf("1. Input Data\n");
        printf("2. Lihat Data\n");
        printf("3. Edit Data\n");
        printf("4. Cari Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                inputdata();
                break;
            case 2:
                lihatdata();
                break;
            // Implement cases 3 and 4 as needed
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}
