#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long long ull;

enum menu_options {
    INIT_ARRAY = 1,PRINT_ARRAY,SORT_FAST,SORT_SLOW,FREE_ARRAY,LINEAR_SEARCH,BINARY_SEARCH,COMPUTE_FIBONACCI,EXIT_PROGRAM
};

// Function prototypes
void display_menu();
ull* generate_random_array(ull num_elements);
void free_array(ull *array);
void print_array(ull *array, ull num_elements);
void selection_sort(ull array[], ull length);
void quick_sort(ull array[], ull start, ull end);
int linear_search(ull array[], int num_elements, int target);
int binary_search(ull array[], int start, int end, int target);
char* reverse_string(char *str);
char* add_strings(char *final_sum, const char *first_str, const char *second_str);
ull get_max_index(ull a[], ull length);
void swap(ull *a, ull *b);
ull partition(ull a[], ull start, ull end);

int main() {
    srand(time(NULL));
    ull *array = NULL;
    int option;
    ull num_elements = 0;

    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); 
        char fib[3][99999];
        double exec_time = 0;
        double start_time = 0;
        double end_time = 0;
        ull target = 0;
        int search_result = 0;
        ull fib_target = 0;

        switch (option) {
            case INIT_ARRAY:
                printf("Enter the number of elements in the array:\n");
                scanf("%llu", &num_elements);
                array = generate_random_array(num_elements);
                break;
            case PRINT_ARRAY:
                printf("The array is:\n");
                print_array(array, num_elements);
                printf("\n");
                break;
            case SORT_FAST:
                printf("Array sorted with quick sort\n");
                start_time = clock();
                quick_sort(array, 0, num_elements - 1);
                end_time = clock();
                exec_time = (end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nExecution time is %lf seconds\n", exec_time);
                break;
            case SORT_SLOW:
                printf("Array sorted with selection sort\n");
                start_time = clock();
                selection_sort(array, num_elements);
                end_time = clock();
                exec_time = (end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nExecution time is %lf seconds\n", exec_time);
                break;
            case FREE_ARRAY:
                free(array);
                array = NULL;
                break;
            case LINEAR_SEARCH:
                printf("Enter a number to search for:\n");
                scanf("%llu", &target);
                start_time = clock();
                search_result = linear_search(array, num_elements, target);
                end_time = clock();
                if (search_result != -1)
                    printf("Number %llu found at index %d\n", target, search_result);
                else
                    printf("Number %llu not found\n", target);
                exec_time = (end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nExecution time is %lf seconds\n", exec_time);
                break;
            case BINARY_SEARCH:
                printf("Enter a number to search for:\n");
                scanf("%llu", &target);
                start_time = clock();
                search_result = binary_search(array, 0, num_elements - 1, target);
                end_time = clock();
                if (search_result != -1)
                    printf("Number %llu found at index %d\n", target, search_result);
                else
                    printf("Number %llu not found\n", target);
                exec_time = (end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nExecution time is %lf seconds\n", exec_time);
                break;
            case COMPUTE_FIBONACCI:
                strcpy(fib[0], "0");
                strcpy(fib[1], "1");
                int i;
                printf("Enter which Fibonacci number to calculate:\n");
                scanf("%llu", &fib_target);
                start_time = clock();
                for (i = 2; i < fib_target; i++) {
                    add_strings(fib[2], fib[1], fib[0]);
                    strcpy(fib[0], fib[1]);
                    strcpy(fib[1], fib[2]);
                }
                end_time = clock();
                printf("Fib(%d) = %s.\n", i, add_strings(fib[2], fib[1], fib[0]));
                exec_time = (end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nExecution time is %lf seconds\n", exec_time);
                break;
            case EXIT_PROGRAM:
                free(array);
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("-------------Menu-------------\n");
    printf("1.       Initialize array with random numbers   \n");
    printf("2.       Display array                          \n");
    printf("3.       Quick sort array                       \n");
    printf("4.       Selection sort array                   \n");
    printf("5.       Free array memory                      \n");
    printf("6.       Linear search for a number             \n");
    printf("7.       Binary search for a number             \n");
    printf("8.       Compute Fibonacci number               \n");
    printf("0.       Exit                                   \n");
    printf("------------------------------\n");
}

ull* generate_random_array(ull num_elements) {
    ull *array = (ull*)malloc(num_elements * sizeof(ull));
    for (ull i = 0; i < num_elements; i++) {
        array[i] = rand();
    }
    return array;
}

void free_array(ull *array) {
    free(array);
}

void print_array(ull *array, ull num_elements) {
    for (ull i = 0; i < num_elements; i++) {
        printf("%llu ", array[i]);
    }
    printf("\n");
}

void selection_sort(ull array[], ull length) {
    ull max_idx, temp;
    for (ull i = 0; i < length - 1; i++) {
        max_idx = get_max_index(array, length - i);
        temp = array[max_idx];
        array[max_idx] = array[length - 1 - i];
        array[length - 1 - i] = temp;
    }
}

void quick_sort(ull array[], ull start, ull end) {
    if (start < end) {
        ull pivot_index = partition(array, start, end);
        quick_sort(array, start, pivot_index - 1);
        quick_sort(array, pivot_index + 1, end);
    }
}

int linear_search(ull array[], int num_elements, int target) {
    for (int i = 0; i < num_elements; i++) {
        if (array[i] == target)
            return i;
    }
    return -1;
}

int binary_search(ull array[], int start, int end, int target) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (array[mid] == target)
            return mid;
        if (array[mid] > target)
            return binary_search(array, start, mid - 1, target);
        return binary_search(array, mid + 1, end, target);
    }
    return -1;
}

ull get_max_index(ull a[], ull length) {
    ull idx_max = 0;
    ull max = a[0];
    for (ull i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
            idx_max = i;
        }
    }
    return idx_max;
}

void swap(ull *a, ull *b) {
    ull temp = *a;
    *a = *b;
    *b = temp;
}

ull partition(ull a[], ull start, ull end) {
    ull pivot = a[end];
    ull idx = start;
    for (ull i = start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(&a[i], &a[idx]);
            idx++;
        }
    }
    swap(&a[end], &a[idx]);
    return idx;
}

char* reverse_string(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (end > start) {
        char temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
    return str;
}

char* add_strings(char *final_sum, const char *first_str, const char *second_str) {
    const char *ptr_first = first_str + strlen(first_str) - 1;
    const char *ptr_second = second_str + strlen(second_str) - 1;
    char *ptr_sum = final_sum;
    int carry = 0;

    while (ptr_first >= first_str || ptr_second >= second_str || carry) {
        int sum = carry;
        if (ptr_first >= first_str)
            sum += *(ptr_first--) - '0';
        if (ptr_second >= second_str)
            sum += *(ptr_second--) - '0';
        *(ptr_sum++) = sum % 10 + '0';
        carry = sum / 10;
    }
    *ptr_sum = '\0';
    return reverse_string(final_sum);
}
