//Laboratorul 5 PC Brinza Bogdan

// 	Ce reprezintă un șir de caractere în limbajul C?
// 	Șirurile de caractere sunt utilizate pentru stocarea de text/caractere.
//  Cu ce simbol se finisează un șir de caractere în limbajul C?
// 	Un șir de caractere în limbajul C se finisează cu un caracter nul “\0”, care are codul ASCII 0.
//  Cum citim de la tastatură un șir de caractere cu spații ?
// 	Folosind metoda scanf cu %s și str, sau prin metoda gets(str).

/**/

// Ex 1
#include <stdio.h>
#include <string.h>

int main() {
    char sir[100];
    
    printf("Introdu un sir: ");
    gets(sir);

    int lungime = strlen(sir);

    printf("Lungimea sirului este: %d\n", lungime);

    return 0;
}

//Ex2

#include <stdio.h>
#include <string.h>

int main() {
    char sir1[100], sir2[100];

    printf("Introdu un sir: ");
    gets(sir1);

    strcpy(sir2, sir1);

    printf("Sirul copiat este: %s\n", sir2);

    return 0;
}

//Ex3

#include <stdio.h>
#include <string.h>

int main() {
    char sir1[100], sir2[100];

    printf("Introdu primul sir: ");
    gets(sir1);

    printf("Introdu al doilea sir: ");
    gets(sir2);

    strcat(sir1, sir2);

    printf("Sirul concatenat este: %s\n", sir1);

    return 0;
}

//Ex4

#include <stdio.h>
#include <string.h>

int main() {
    char sir1[100], sir2[100];

    printf("Introdu primul sir: ");
    gets(sir1);

    printf("Introdu al doilea sir: ");
    gets(sir2);

    if (strcmp(sir1, sir2) == 0)
        printf("Cele doua siruri sunt egale.\n");
    else
        printf("Cele doua siruri nu sunt egale.\n");

    return 0;
}

//Ex5

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }

    printf("Șirul cu literele convertite este: %s\n", str);

    return 0;
}

//Ex6

#include <stdio.h>

int main() {
    char str[100];
    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Conversia la literă mică
        }
    }

    printf("Șirul după conversia literelor majuscule în litere mici: %s\n", str);

    return 0;
}
// Ex 7
#include <stdio.h>

int main() {
    char str[100];
    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Conversia la literă mare
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Conversia la literă mică
        }
    }

    printf("Șirul după comutarea literelor: %s\n", str);

    return 0;
}


//Ex8

#include <stdio.h>

int main() {
    char str[100];
    int litere = 0, cifre = 0, caractereSpeciale = 0;

    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            litere++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            cifre++;
        } else {
            caractereSpeciale++;
        }
    }

    printf("Numărul total de litere: %d\n", litere);
    printf("Numărul total de cifre: %d\n", cifre);
    printf("Numărul total de caractere speciale: %d\n", caractereSpeciale);

    return 0;
}
//Ex9

#include <stdio.h>

int main() {
    char str[100];
    int vocale = 0;

    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vocale++;
        }
    }

    printf("Numărul total de vocale: %d\n", vocale);

    return 0;
}

//Ex10

#include <stdio.h>

int main() {
    char str[100];
    int consoane = 0;

    printf("Introduceți un șir: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
                str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                consoane++;
            }
        }
    }

    printf("Numărul total de consoane: %d\n", consoane);

    return 0;
}

//Ex11

#include <stdio.h>
#include <string.h>

int countWords(char *str) {
    int count = 0;
    int isWord = 0;

    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            isWord = 0;
        } else if (isWord == 0) {
            isWord = 1;
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[1000];

    printf("Introduceți șirul: ");
    fgets(str, sizeof(str), stdin);

    int words = countWords(str);
    printf("Numărul total de cuvinte: %d\n", words);

    return 0;
}
// Ex12
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[1000];

    printf("Introduceți șirul: ");
    fgets(str, sizeof(str), stdin);

    reverseString(str);

    printf("Inversul șirului: %s\n", str);

    return 0;
}

//Ex13
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Nu este palindrom
        }

        start++;
        end--;
    }

    return 1; // Este palindrom
}

int main() {
    char str[1000];

    printf("Introduceți șirul: ");
    fgets(str, sizeof(str), stdin);
// Elim sfarsitu
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("Este un palindrom.\n");
    } else {
        printf("Nu este un palindrom.\n");
    }

    return 0;
}
