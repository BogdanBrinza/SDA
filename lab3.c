//Lab3 PC Brinza Bogdan

// Ce reprezinta functia in limbajul C?
// Functia e un bloc de cod care ruleaza doar cand e apelata.
// Cum se apelează o funcție în limbajul C?
// Apelăm o funcție prin utilizarea numelui ei urmat de paranteze.
// Poti trimite informatie, parametri intr-o functie.
// Ce reprezintă lista de parametri formali pentru o funcție în limbajul C?
// Între parantezele funcției pot fi introduși 1 sau mai mulți parametri pentru transmiterea valorilor către funcții și implementarea algoritmilor complecși.	
// CU functiile poti defini codul o data si sa folosesti de dese ori.
// Recursia este tehnica de a face o functie sa se apeleze singura. E o metoda de a face din probleme grele - probleme simple


/**/


#include <stdio.h>
#include <stdlib.h>

// -	cum se declară o funcție în limbajul C?

void myFunction() {
    printf("I get executed when you call me.\n");
}

int main() {
    myFunction();
    myFunction();
    myFunction();
    myFunction();
  return 0;
}



// Ex 1 - cubul oricarui numar - nr = numarul de 3 ori care face - raspuns

#include <stdio.h>

int functie(int n) {
  return n * n * n;
}

int main() {
  int n;

  printf("Introdu numarul: ");
  scanf("%d", &n);

  printf("Cubul lui %d e %d.", n, functie(n));

  return 0;
}

// sau

#include <stdio.h>
void calculam_Cubul(int numar) {
  int cub = numar * numar * numar;
  printf("Cubul lui %d este %d\n", numar, cub);

}

int main() {
  calculam_Cubul(2);

  return 0;
}


// Ex2 Program care afla diametru, circumferinta si aria cercului

#include <stdio.h>
#include <math.h>

double diametru_cercului(double r) {
    return 2 * r;
}

double circumferinta_cercului(double r) {
    return 2 * M_PI * r;
}


double aria_cercului(double r) {
    return M_PI * r * r;
}

int main() {
    double r;
    printf("Introdu raza cercului: ");
    scanf("%lf", &r);

    printf("Diametrul cercului este: %.2lf\n", diametru_cercului(r));
    printf("Circumferinta cercului este: %.2lf\n", circumferinta_cercului(r));
    printf("Aria cercului este: %.2lf\n", aria_cercului(r));

    return 0;
}

// Ex 3


#include <stdio.h>

// maxim și minim între două numere 


int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}


int min(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  int x, y;


  printf("Introduceți primul număr: ");
  scanf("%d", &x);

  printf("Introduceți al doilea număr: ");
  scanf("%d", &y);


  printf("Numărul maxim este %d\n", max(x, y));
  printf("Numărul minim este %d\n", min(x, y));

  return 0;
}

// Ex 4 - functie -  sa se afle daca un numar e par sau impar 

#include <stdio.h>

int este_par(int numar) {
  return numar % 2 == 0;
}

int main() {
  int numar;

  printf("Introduceți un număr: ");
  scanf("%d", &numar);

  if (este_par(numar)) {
    printf("Numărul este par.\n");
  } else {
    printf("Numărul este impar.\n");
  }

  return 0;
}
// Ex 5 - functie - verificare daca e numar prim din intervalul dat
#include <stdio.h>


int este_prim(int n) {

  if (n <= 1) {
    return 0;
  }


  for (int i = 2; i * i <= n; i++) {
 
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
 
  int a, b, i;


  printf("Introduceți intervalul de numere: ");
  scanf("%d %d", &a, &b);


  for (i = a; i <= b; i++) {
   
    if (eprim(i)) {
      printf("%d ", i);
    }
  }

 
  printf("\n");

  return 0;
}

// Ex 7 - functie - gasirea tuturor numerelelor puternice in intervalul dat

#include <stdio.h>

int nr_divizori(int n) {
  int i, nr_divizori = 0;
  for (i = 1; i <= n; i++) {
    if (n % i == 0) {
      nr_divizori++;
    }
  }
  return nr_divizori;
}

int este_puternic(int n) {
  int i, nr_divizori_n, nr_divizori_i;

  nr_divizori_n = nr_divizori(n);
  for (i = n - 1; i > 0; i--) {
    nr_divizori_i = nr_divizori(i);
    if (nr_divizori_n <= nr_divizori_i) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int inceput, sfarsit;

  printf("Introduceti intervalul: ");
  scanf("%d %d", &inceput, &sfarsit);

  for (int i = inceput; i <= sfarsit; i++) {
    if (este_puternic(i)) {
      printf("%d ", i);
    }
  }

  return 0;
}


// Ex 1 recursii - program pentru a gasi puterea oricarui numar prin recursion

#include <stdio.h>

int power(int x, int n) {
  if (n == 0) {
    return 1;
  } else {
    return x * power(x, n - 1);
  }
}

int main() {
  int x, n;
  printf("Introduceți x: ");
  scanf("%d", &x);
  printf("Introduceți n: ");
  scanf("%d", &n);
  printf("x^n = %d\n", power(x, n));
  return 0;
}

// Ex 2 recursii - program pentru a printa toate numerele naturale intre 1 si n


#include <stdio.h>

void numerenaturale(int n) {
    if (n >= 1) {
        printf("%d ", n);
        numerenaturale(n - 1);
    }
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    numerenaturale(n);

    return 0;
}

// Ex 3 recursii - program

#include <stdio.h>

void imprima_numere(int a, int b) {
  if (a <= b) {
    if (a % 2 == 0) {
      printf("%d ", a);
    }
    imprima_numere(a + 1, b);
  }
}

int main() {
  int a, b;

  printf("Introduceți începutul intervalului: ");
  scanf("%d", &a);

  printf("Introduceți sfârșitul intervalului: ");
  scanf("%d", &b);

  printf("Numere pare: ");
  imprima_numere(a, b);

  return 0;
}

// Ex 4 recursii

#include <stdio.h>

// suma tuturor numerelor naturale intre 1 si n

int suma(int n) {

  if (n == 0) {
    return 0;
  }


  return suma(n - 1) + n;
}

int main() {

  int n;
  printf("Introduceți valoarea lui n: ");
  scanf("%d", &n);


  printf("Suma tuturor numerelor naturale cuprinse între 1 și %d este %d.\n", n, suma(n));

  return 0;
}

// Ex 6 program pentru a gasi inversarea oricarui numar folosind recursion, exemplu: 2021 - 1202

#include <stdio.h>
#include <stdio.h>
int inversul = 0,rest;
int invers(int numar)
{   if(numar){
        rest = numar %10;
        inversul = inversul * 10 + rest;
        invers(numar/10);
        }
    else return inversul;
    return inversul;
}

int main()
{
    int numar,Inversul = 0;
    
    printf("Introduceti un numar: ");
    scanf("%d", &numar);
    
    printf("%d",invers(numar));
    return 0;
}