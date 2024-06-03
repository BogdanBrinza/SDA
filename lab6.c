//Laboratorul 6 PC Brinza Bogdan

//

//  ce reprezintă tipul de date pointer în limbajul C?
//	Un pointer este o variabilă care stochează ca valoare adresa de memorie a unei alte variabile.
//  cum se accesează adresa unei variabile în limbajul C?
// 	Putem accesa adresa unei variabile folosind operatorul de adresă ‘&’.
// 	cu ce funcții se poate de alocat memorie dinamică în limbajul C?
// 	Funcțiile utilizate pentru a manipula memoria în programarea C sunt malloc(), calloc() și realloc().
// 	cu ce funcție se poate de eliberat memoria dinamică în limbajul C?
// 	Cu funcția free,  free(pointer);
// 	În ce cazuri este utilizată alocarea dinamică?
// 	Alocarea dinamică e utilizată pentru crearea structurilor de date dinamice, implementarea algoritmilor, tablouri.



/**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#define SIZE 3


// 1 C pentru a crea, inițializa și utiliza pointeri pentru printarea a diferitor variabile.
int main()
{
   int nr = 45;
   int *ptr = &nr;

   printf("%d",*ptr);
    
    return 0;
}/**/
//       2.	Scrieți un program C pentru a aduna două numere folosind pointerii.
int main()
{
   int nr1 = 45;
   int nr2  = 55;
   int *ptr1 = &nr1;
   int *ptr2 = &nr2;

   printf("Suma pointerilor este %d",*ptr1 + *ptr2);
    return 0;
}*/
//    3.	Scrieți un program C pentru a interschimba valorile a două variabile folosind pointerii.
int main()
{
   int nr1 = 45;
   int nr2  = 55;
   int *ptr1 = &nr1;
   int *ptr2 = &nr2;
   int temp;
   temp = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp;

    printf("%d\n",*ptr1);
    printf("%d\n",*ptr1);

    return 0;
}*/
//   4.	Scrieți un program C pentru a inițializa și afișa elementele unei matrici folosind pointerii
int main()
{
   int arr1[size][size];
   int (*p)[size] = arr1;
   printf("A sa trebuiasca sa introduci niste valori:\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
             scanf("%d",&arr1[i][j]);
             }
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                printf("%d ",p[i][j]);
        }
        printf("\n");
        }
        // for(int i = 0; i < size; i++){
           
        //         printf("%d ",*p[0] + 0);
        
        // printf("\n");
    
            for(int i = 0; i < 2; i++){
//         for(int j = 0; j < 2; j++){
//              scanf("%d",p + i * 2 + j);
//              }
//         }
//         for(int i = 0; i < 2; i++){
//             for(int j = 0; j < 2; j++){
//                 printf("%d ",*(p + i * 2 + j));
}*/

//   5.	Scrieți un program C pentru a copia o matrice în alta folosind pointeri.
int main()
{
   int arr1[size][size] = {
        {1,2,3},
        {3,4,5},
        {6,7,8}};
    int *arr2[size][size];

        for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            arr2[i][j] = &arr1[i][j];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",*(*(*(arr2 + i) + j)));
            } 
        printf("\n");
    }
    return 0;
}*/
//   6.	Scrieți un program C pentru a interschimba valorile a două matrice folosind pointeri.
// int main()
// {
//     int ar1[size][size];
//     int(*ptr)[size] = ar1;
//    int arr1[size][size];
//     int (*arr2)[size] = arr1;
//     int temp;
    
//        printf("Introdu prima matrice:\n");    
//         for(int i = 0; i < size; i++)
//         for(int j = 0; j < size; j++)
//            scanf("%d",&ar1[i][j]);
//            for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//            printf("%d ",ar1[i][j]);
//         }
//            printf("\n");
//            }
//          printf("\n");
//          printf("Introdu a doua matrice:\n");
//     for(int i = 0; i < size; i++)
//         for(int j = 0; j < size; j++)
//            scanf("%d",&arr1[i][j]);
//            for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//            printf("%d ",arr1[i][j]);
//         }
//            printf("\n");
//            }
//         printf("\n");
//            for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//             temp = *(*(ptr + i) + j);   
//             *(*(ptr + i) + j) = *(*(arr2 + i) + j);
//             *(*(arr2 + i) + j) = temp;

//             } 
//     }
//          printf("\n");
//           printf("Prima matrice cu valorile inlocuite:\n");    
//     for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//             printf("%d ",arr1[i][j]);
//             } 
//         printf("\n");
//     }

//             printf("A doua matrice inlocuita\n");
//      for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//             printf("%d ",ar1[i][j]);
//             } 
//         printf("\n");
//     }
//     return 0;
// }
int main()
{
    int ar1[size][size]= {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int *ptr1 = &ar1[0][0];
     int ar2[size][size]= {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int *ptr2 = &ar2[0][0];
    int temp;
        printf("\n");
           for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp = *((ptr2 + i * size + j));   
            *(ptr2 + i* size + j) = *(ptr1 + i* size + j);
            *(ptr1 + i* size + j) = temp;
            // temp = ar2[i][j];
            // ar2[i][j] = ar1[i][j];
            // ar1[i][j] = temp;
            } }
         printf("\n");
       
        printf("Prima matrice cu valorile inlocuite:\n");    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",*ptr1);
            ptr1++;
            } 
        printf("\n");
    }
        printf("A doua matrice inlocuita\n");
     for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",*ptr2);
             ptr2++;
            } 
        printf("\n");
    }
    return 0;
}*/
//   7.	Scrieți un program C pentru a transpune o matrice folosind pointeri.
int main()
{
   int arr1[size][size] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
   int (*p)[size] = arr1;
   printf("Elementele matricei:\n");

        for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(p + j) + i));
        }
        printf("\n");
    }
}*/
//   8.	Scrieți un program C pentru a căuta un element din matrice folosind pointeri.
int main()
{
   int arr1[size][size] = {
        {1,2,3},
        {9,4,5},
        {6,7,8}};
    int *cautat = &arr1[0][0];
    int element_cautat,gasit = 0, nr = 0;
    printf("\nIntrodu elementul pe il cauti\n");
    scanf("%d",&element_cautat);
   
   for(int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
            nr++; 
           if(*(cautat + i * 3 +j) == element_cautat){
    printf("Elementul %d a fost gasit la pozitia %d\n", element_cautat,nr);
                    gasit = 1; 
                    //break;
                 }
                }
                    }
                     if (!gasit) {
        printf("Elementul %d nu a fost gasit in matrice.\n", element_cautat);
    }
}*/
//   9.	Scrieți un program C pentru a accesa direct elementele de pe diagonala principală a unei 
void find_diagonal(int * matrice, int marime)
{
    int i, j;
    for(i = 0; i < marime; i++){
       for(j = 0; j < marime; j++){
        if(i == j)
        printf("%d ",*(matrice + i*marime + j));
       }
       printf("\n");
    }  
}
int main()
{
   int arr1[size][size] = {
        {1,2,3},
        {9,4,5},
        {6,7,8}};
        int marime = size;
        find_diagonal(&arr1[0][0],marime);
        return 0;

}*/
// 10.	Scrieți un program C pentru a aduna două matrice folosind pointeri.
void aduna_2_matrici(int * matr1, int * matr2,int len);
int main ()
{
   
    int i,j,k,l,m,n;
    int matr1[size][size] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}};
    int matr2[size][size] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}};
    aduna_2_matrici(&matr1[0][0], &matr2[0][0],size);
    
    return 0;
}
void aduna_2_matrici(int * matr1, int * matr2,int len)
{
    int suma[size][size];
    int SUMTOT = 0;
    for (int i = 0; i < size; i++)
    {
         for (int j = 0; j < size; j++)
          {
           suma[i][j] =*(matr1 + i * len + j) + *(matr2 + i * len + j);
            SUMTOT +=suma[i][j];
        }
    }
     printf("%d ",SUMTOT);
}*/
//  11.	Scrieți un program C pentru a multiplica două matrice folosind pointeri.
void inmulteste_2_matrici(int * matr1, int * matr2,int len);
int main ()
{
   
    int i,j,k,l,m,n;
    int matr1[size][size] = {
        {1,3,2},
        {1,90,1},
        {1,1,1}};
    int matr2[size][size] = {
        {1,1,1},
        {1,3,12},
        {1,100,1}};
    int produs[size][size];
    inmulteste_2_matrici(&matr1[0][0], &matr2[0][0],size);
    
    return 0;
}
void inmulteste_2_matrici(int * matr1, int * matr2,int len)
{
    int produs[size][size];
    int PRODUS = 1;
    for (int i = 0; i < size; i++)
    {
         for (int j = 0; j < size; j++)
          {
           produs[i][j] =*(matr1 + i * len + j) * *(matr2 + i * len + j);
           printf("%d ",produs[i][j]);
        }
        printf("\n");
        }
    }*/
//  12.	Scrieți un program C pentru a găsi lungimea șirului folosind pointeri. 
int main() 
{
    char str[25];
    char *ptr;
    int length = 0;

    printf("Introdu lungime unui sir:\n");
    gets(str);

    ptr=str;

    while(*ptr != '\0')
    {
        length++;
        ptr++;
        
    }
    printf("Lungimea sirului este %d",length);


      return 0;                 
}*/
//      13.	Scrieți un program C pentru a copia un șir în altul folosind pointeri. 
void copiere_str(char * destinatie,char * sursa)
{
    while(*sursa != '\0')
    {
        *destinatie = *sursa;
        *sursa++;
        *destinatie++;
    }
    *destinatie = '\0';
}
int main() 
{
    char str[25] = "Care";
    char str2[25] = "salut?";

    
    copiere_str(str,str2);

    printf("Sirul final este %s",str);


      return 0;                 
}*/
//  14.	Scrieți un program C pentru a concatena două șiruri de caractere folosind pointeri. 
int main() 
{
    char str1[25] = "Care";
    char str2[25] = " salut?";
    char *ptr1 = str1;
    char *ptr2 = str2;
    while(*ptr1)
    {
        *ptr1++;
    }
     while(*ptr2)
    {
        *ptr1 = *ptr2;
        *ptr2++;
        *ptr1++;
    }
    *ptr1= '\0';
    printf("Sirul final este %s",str1);
      return 0;                 
}*/
//  15.	Scrieți un program C pentru a compara două șiruri de caractere folosind pointeri. 
int main() 
{
    char str1[25] = "Care";
    char str2[25] = "Care";
    char *p1 = str1;
    char *p2 = str2;
    int semn = 0;

    while(*p1 != '\0' || *p2 != '\0')
    {
        if(*p1 != *p2)
        {
            semn = 1;
            break;
        }
        p1++;
        p2++;
    }
    if(semn == 0){
      printf("Sirurile sunt egale");
        }
        else printf("Sirurile nu sunt egale");
    
      return 0;                 
}*/
//  16.	Scrieți un program C pentru a găsi inversul unui șir folosind pointeri. 
/void reverseString(char *start) {
    char *end = start, temp;

    while (*end != '\0') {
        end++;
    }
    end--;  

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    gets(input);  

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}*/
//  17.	Scrieți un program C pentru a sorta elementele unei matrici folosind pointeri. 

int  main()
{
    int a[7][7] ={{67, 0 , -78},
                  {1, 8956, 9},
                  {34,7,-290}};
    int i ,j,k,m,n,temp; 
    printf("Numarul de randuri\n");
    scanf("%d",&m);
    printf("Numarulde coloane\n");
    scanf("%d",&n);
    printf("Elementele\n");
    // for(i=0;i<m;i++)
    //   {
    //     for(j=0;j<n;j++)
    //         scanf("%d",&a[i][j]);
    //   }
       
    printf("Matricea introdusa:\n");
    for(i=0;i<m;i++)
        {
            printf("\n");
            for(j=0;j<n;j++)
            {
                printf("%d ",*(*(a+i)+j));
            }
        }
    // for(i=0;i<n;i++)
    //     {
    //         for(k=0;k<m-1;k++)
    //         {
    //             for(j=0;j<m -1;j++)
    //             {
    //                 if( *(*(a+j)+i)> *(*(a+(j+1))+i)) 
    //                 {
    //                 temp=*(*(a+j)+i);
    //                 *(*(a+j)+i)=*(*(a+(j+1))+i);
    //                 *(*(a+(j+1))+i)=temp;
    //                 }
    //             }
    //         }
    //     }
        //Metoda alta 2
         for(i = 0; i < n * m  - 1; i++)
        {
            for(j = 0; j < m * n - 1 ; j++)
            {
                    if( a[j / m][j % m]> a[(j + 1 )/ m][(j + 1 )% m]) 
                    {
                    temp = a[j / m][j % m];
                    a[j / m][j % m] = a[(j + 1 )/ m][(j + 1 )% m];
                    a[(j + 1 )/ m][(j + 1 )% m]=temp;
                    }
            }
        }
    
    printf("\nMatricea sortata:\n");
        for(i=0;i<m;i++)
            {
            for(j=0;j<n;j++)
            {
                printf("%d ",*(*(a+i)+j));
            }
                printf("\n");
        }
        
        return 0;
}*/
//  18.	Scrieți un program C pentru a returna mai multe valori de la funcție folosind pointeri.

/struct Book
{
    char name[20];
    int pages;
    float price;

};
struct Book initialize()
{
    struct Book book = {"carare",300,100};
    return book;
};

int main()
{
    struct Book book = initialize();
    printf("Name = %s\n",book.name);
    printf("Pages = %d\n",book.pages);
    printf("Price = %f\n",book.price);

    return 0;
}*/



struct Book {
    char name[20];
    int pages;
    float price;
};

void initialize(struct Book *book) {
    snprintf(book->name, sizeof(book->name), "%s", "carare");
    (*book).pages = 300;
    book->price = 100.2;
}

int main() {
    struct Book book;
    
    initialize(&book);

    printf("Nume = %s\n", book.name);
    printf("Pagini = %d\n", book.pages);
    printf("Pret = %f\n", book.price);

    return 0;
}*/


//Asa nu se returneaza mai multe valori dintro functie

/void Return(int *nr1,int *nr2,int *nr3,int *nr4,int *nr5)
{

    *nr1 = 1;
    *nr2 = 2;
    *nr3 = 3;
    *nr4 = 4;
    *nr5 = 5;
}
int main()
{
    int nr1,nr2,nr3,nr4,nr5;
    printf("Inrodu valorile numerelor\n");
                Return(&nr1,&nr2,&nr3,&nr4,&nr5);
            printf("%d %d %d %d %d \n",nr1,nr2,nr3,nr4,nr5);
    return 0;
}*/

/int *Return(int *nr1)
{
    for(int i = 0; i < 10; i++)
        {
            *(nr1 + i) = i + 1;
        }
        return nr1;
}
int main()
{
    int nr1[10];
    Return(nr1);
    for(int i = 0; i < 10; i++) 
        {
            printf("%d ",nr1[i]);
        }  
         
    return 0;
}*/