//Laboratorul 4 PC Brinza Bogdan

// Ce reprezintă un tablou unidimensional în limbajul C?
// Tablourile sunt utilizate pentru a stoca mai multe valori într-o singură variabilă. 
// Ce reprezintă un tablou bidimensional în limbajul C?
// Un tablou din numere întregi format din rânduri și coloane. Prima dimensiune reprezintă numărul de rânduri [], în timp ce a doua dimensiune reprezintă numărul de coloane [].
// 	Cu ce operator se accesează elementele unui tablou în limbajul C?
// 	Cu operatorul subscript [] și indexarea.
//	Ce index are primul element din tabloul unidimensional ?
// 	Primul element din tabloul unidimensional are indexul 0
// 	Ce index are ultimul element din tabloul unidimensional cu lungimea N?
// 	Ultimul element din tabloul unidimensional cu lungimea N are indexul n-1.


//Tablouri unidimensionale

//Ex1

#include <stdio.h>

void citeste_si_imprima(int arr[], int n, int index) {
    if (index == n) {
        return;
    }
    printf("%d ", arr[index]);
    citeste_si_imprima(arr, n, index + 1);
}

int main() {
    int n;
    printf("Introduceti lungimea tabloului: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elementele tabloului sunt: ");
    citeste_si_imprima(arr, n, 0);

    return 0;
}

//Ex 2 

#include <stdio.h>

void imprima_negative(int arr[], int n) {
    printf("Elementele negative ale tabloului sunt: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int n;
    printf("Introduceti lungimea tabloului: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    imprima_negative(arr, n);

    return 0;
}

//Ex 3

#include <stdio.h>

int suma_recursiva(int arr[], int n, int index) {
    if (index == n) {
        return 0;
    }
    return arr[index] + suma_recursiva(arr, n, index + 1);
}

int main() {
    int n;
    printf("Introduceti lungimea tabloului: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int suma = suma_recursiva(arr, n, 0);
    printf("Suma elementelor tabloului este: %d\n", suma);

    return 0;
}

//Ex4

#include <stdio.h>

void max_min_recursiv(int arr[], int n, int index, int *max, int *min) {
    if (index == n) {
        return;
    }

    if (arr[index] > *max) {
        *max = arr[index];
    }

    if (arr[index] < *min) {
        *min = arr[index];
    }

    max_min_recursiv(arr, n, index + 1, max, min);
}

int main() {
    int n;
    printf("Introduceti lungimea tabloului: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];
    max_min_recursiv(arr, n, 1, &max, &min);

    printf("Elementul maxim este: %d\n", max);
    printf("Elementul minim este: %d\n", min);

    return 0;
}

//Ex5

#include <stdio.h>

void gaseste_al_doilea_maxim(int arr[], int n) {
    int max = arr[0];
    int second_max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    printf("Al doilea cel mai mare element este: %d\n", second_max);
}

int main() {
    int n;
    printf("Introduceti lungimea tabloului: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    gaseste_al_doilea_maxim(arr, n);

    return 0;
}


//Ex6

#include <stdio.h>

int main() {
    int n, i, evenCount = 0, oddCount = 0;

    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    int arr[n];

    printf("Introduceti elementele tabloului:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    printf("Numarul total de elemente pare: %d\n", evenCount);
    printf("Numarul total de elemente impare: %d\n", oddCount);

    return 0;
}

//Ex7

#include <stdio.h>

int main() {
    int n, i, negativeCount = 0;

    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    int arr[n];

    printf("Introduceti elementele tabloului:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            negativeCount++;
        }
    }

    printf("Numarul total de elemente negative: %d\n", negativeCount);

    return 0;
}


//Tablouri bidimensionale

//Ex1

#include <stdio.h>

void adunaMatrice(int matrice1[10][10], int matrice2[10][10], int rezultat[10][10], int randuri, int coloane) {
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            rezultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}

int main() {
    int matrice1[10][10], matrice2[10][10], rezultat[10][10];
    int randuri, coloane;

    printf("Introduceți numărul de rânduri și coloane ale matricelor: ");
    scanf("%d %d", &randuri, &coloane);

    printf("Introduceți elementele primei matrice:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            scanf("%d", &matrice1[i][j]);
        }
    }

    printf("Introduceți elementele celei de-a doua matrice:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            scanf("%d", &matrice2[i][j]);
        }
    }

    adunaMatrice(matrice1, matrice2, rezultat, randuri, coloane);

    printf("Matricea rezultată după adunare este:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            printf("%d ", rezultat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Ex2

#include <stdio.h>

void scadeMatrice(int matrice1[10][10], int matrice2[10][10], int rezultat[10][10], int randuri, int coloane) {
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            rezultat[i][j] = matrice1[i][j] - matrice2[i][j];
        }
    }
}

int main() {
    int matrice1[10][10], matrice2[10][10], rezultat[10][10];
    int randuri, coloane;

    printf("Introduceți numărul de rânduri și coloane ale matricelor: ");
    scanf("%d %d", &randuri, &coloane);

    printf("Introduceți elementele primei matrice:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            scanf("%d", &matrice1[i][j]);
        }
    }

    printf("Introduceți elementele celei de-a doua matrice:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            scanf("%d", &matrice2[i][j]);
        }
    }

    scadeMatrice(matrice1, matrice2, rezultat, randuri, coloane);

    printf("Matricea rezultată după scădere este:\n");
    for(int i = 0; i < randuri; i++) {
        for(int j = 0; j < coloane; j++) {
            printf("%d ", rezultat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Ex3

#include <stdio.h>

void multiplyMatrixByScalar(int matrix[10][10], int rows, int cols, int scalar) {
    int result[10][10];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    printf("Matricea rezultat:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, scalar;

    printf("Introduceti numarul de randuri si coloane ale matricei: ");
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Introduceti scalarul: ");
    scanf("%d", &scalar);

    multiplyMatrixByScalar(matrix, rows, cols, scalar);

    return 0;
}


//Ex4 #include <stdio.h>

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Multiplicarea matricelor nu este posibila.\n");
        return;
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

    // Afisare rezultat
    printf("Matricea rezultat:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Introduceti numarul de randuri si coloane ale primei matrici: ");
    scanf("%d %d", &rows1, &cols1);

    int firstMatrix[10][10];

    printf("Introduceti elementele primei matrici:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Introduceti numarul de randuri si coloane ale celei de-a doua matrici: ");
    scanf("%d %d", &rows2, &cols2);

    int secondMatrix[10][10];

    printf("Introduceti elementele celei de-a doua matrici:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    int result[10][10];

    multiplyMatrices(firstMatrix, secondMatrix, result, rows1, cols1, rows2, cols2);

    return 0;
}

//Ex 5

#include <stdio.h>

int areMatricesEqual(int matrix1[10][10], int matrix2[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0; 
            }
        }
    }

    return 1; 
}

int main() {
    int rows, cols;

    printf("Introduceti numarul de randuri si coloane ale matricilor: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[10][10];
    int matrix2[10][10];

    printf("Introduceti elementele primei matrici:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Introduceti elementele celei de-a doua matrici:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (areMatricesEqual(matrix1, matrix2, rows, cols)) {
        printf("Matricile sunt egale.\n");
    } else {
        printf("Matricile nu sunt egale.\n");
    }

    return 0;
}

//Ex 6 

#include <stdio.h>

int main() {
    int n, i, j, suma = 0;

    // Citirea dimensiunii matricei
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    int matrice[n][n];

    // Citirea elementelor matricei
    printf("Introduceti elementele matricei:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Elementul matricei [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    // Calculul sumei diagonalei principale
    for(i = 0; i < n; i++) {
        suma += matrice[i][i];
    }

    // Afișarea rezultatului
    printf("Suma elementelor diagonalei principale este: %d\n", suma);

    return 0;
}

//Ex7

#include <stdio.h>

int main() {
    int n, i, j, suma = 0;

    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    int matrice[n][n];

    printf("Introduceti elementele matricei:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Elementul matricei [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        suma += matrice[i][n - 1 - i];
    }

    printf("Suma elementelor diagonalei secundare este: %d\n", suma);

    return 0;
}


//Ex 8 

#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Introduceti numarul de randuri: ");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &n);

    int matrice[m][n];

    printf("Introduceti elementele matricei:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("Elementul matricei [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Suma fiecarui rand:\n");
    for(i = 0; i < m; i++) {
        int sumaRand = 0;
        for(j = 0; j < n; j++) {
            sumaRand += matrice[i][j];
        }
        printf("Suma randului %d: %d\n", i + 1, sumaRand);
    }

    printf("Suma fiecarei coloane:\n");
    for(j = 0; j < n; j++) {
        int sumaColoana = 0;
        for(i = 0; i < m; i++) {
            sumaColoana += matrice[i][j];
        }
        printf("Suma coloanei %d: %d\n", j + 1, sumaColoana);
    }

    return 0;
}

//Ex9 

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Introduceti dimensiunea matricei patratice: ");
    scanf("%d", &n);

    int matrice[n][n];

    printf("Introduceti elementele matricei:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Elementul matricei [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        int temp = matrice[i][i];
        matrice[i][i] = matrice[i][n - 1 - i];
        matrice[i][n - 1 - i] = temp;
    }

    printf("Matricea cu diagonale schimbate:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Ex10

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Introduceti dimensiunea matricei patratice: ");
    scanf("%d", &n);

    int matrice[n][n];

    printf("Introduceti elementele matricei:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Elementul matricei [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Matricea triunghiulara superioara:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if (j < i) {
                printf("0\t");
            } else {
                printf("%d\t", matrice[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

