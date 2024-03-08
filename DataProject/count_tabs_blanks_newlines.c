//
//  count_tabs_blanks_newlines.c
//  DataProject
//
//  Created by Nunu Nugraha on 08/03/24.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
    int countBlanks = 0; // 32
    int countNewLine = 0; // 10 or / \n
    int countTabs = 0; // TAB or 9
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == (32)) {
            countBlanks++;
        } else if (c == '\n') {
            countNewLine++;
        } else if (c == (9)) {
            countTabs++;
        }
        
        if (c == '\n') {
            int result = countTabs + countNewLine + countBlanks;
            printf("cek tabs: %d\n and blanks: %d\n and NewLine: %d\n", countTabs, countBlanks, countNewLine);
            printf("cek totalnya: %d\n", result);
        }
    }
    
    return 0;
}
