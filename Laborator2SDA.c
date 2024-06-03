#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 50

struct struct_el {
    int population_number;
    char *country_name;
    struct struct_el *next;
};

typedef struct struct_el State;
State* head;

int choice;
int element_count;
int value1;
char **word_array;

static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //52 juma toate mari juma toate mici

void init_list();
char* init_string();
void print_list();
void delete_element(int position);
void insert_end();
void insert_begin();
void insert_at_position(int n);
int search_position_by_number(int number);
int search_position_by_string(char *search_str);
void reverse_list(State** root);
void sort_list();
void clean_list();
void free_memory();

int main()
{
    int option;
    int position;
    int search_number;
    char search_str[SIZE];
    head = NULL;
    srand(time(NULL));
    init_list();
    print_list();
    while(1){
        printf("-------------Menu-------------\n");
        printf("1.     Display elements                        \n");
        printf("2.     Find position of an element             \n");
        printf("3.     Free memory                             \n");
        printf("4.     Sort elements                           \n");
        printf("5.     Insert element at the end               \n");
        printf("6.     Insert element at the beginning         \n");
        printf("7.     Insert element at a specific position   \n");
        printf("8.     Delete element from a position          \n");
        printf("9.     Reverse the order of elements           \n");
        printf("10.    Clear the list                          \n");
        printf("0.     Exit                                    \n");
        printf("-------------------------------\n");
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 1:
                print_list();
                break;
            case 2:
                printf("For population number press the nr 1\n");
                printf("For country name press the nr 2\n");
                scanf("%d",&choice);
                getchar();
                switch(choice)
                {
                    case 1:
                        printf("Enter the search element (exact number)\n");
                        scanf("%d",&search_number);
                        getchar();
                        position = search_position_by_number(search_number);
                        if(position != -1)   printf("Element '%d' is at position %d\n",search_number,position);
                        else                printf("Element '%d' was not found in the list\n",search_number);
                        break;
                    
                    case 2:
                        printf("Enter the search element (exact word)\n");
                        fgets(search_str, SIZE, stdin);
                        int str_length = strlen(search_str);
                        if(str_length > 0 && search_str[str_length - 1] == '\n')
                        {
                            search_str[str_length - 1] = '\0';
                        }
                        position = search_position_by_string(search_str);
                        if(position != -1)   printf("Element '%s' is at position %d\n",search_str,position);
                        else                printf("Element '%s' was not found in the list\n",search_str);
                        break;
                }
                break;
            case 3:
                free_memory();
                break;
            case 4:
                printf("To sort by population number press the nr 1\n");
                printf("To sort by country names press the nr 2\n");
                scanf("%d",&choice);
                sort_list();
                break;
            case 5:
                element_count++;
                insert_end();
                break;
            case 6:
                element_count++; 
                insert_begin();
                break;
            case 7:
                printf("Enter position:");
                scanf("%d",&position);
                getchar();
                element_count++;
                if(position > element_count || position <=0) {
                    printf("Invalid position!\n");
                    break;
                }
                insert_at_position(position);
                break;
            case 8:
                printf("Enter position:");
                scanf("%d",&position);
                getchar();
                if(position > element_count || position <=0) {
                    printf("Invalid position!\n");
                    break;
                }
                element_count--;
                delete_element(position);
                break;
            case 9:
                reverse_list(&head);
                break;
            case 10:
                clean_list();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}

char* init_string() {
    char temp[SIZE];
    printf("Enter value 2 (Country name)\n");
    fgets(temp, SIZE, stdin);
    int str_length = strlen(temp);
    if(str_length > 0 && temp[str_length - 1] == '\n')
    {
        temp[str_length - 1] = '\0';
    }
    
    char* name = malloc(sizeof(char) * (str_length + 1));
    strcpy(name, temp);
    return name;
}

void init_list() {
    head = NULL;
    printf("Enter the number of elements to create a list: ");
    scanf("%d", &element_count);
    getchar();
    int len = (rand() % 13) + 1;

    for (int i = 0; i < element_count; i++) {
        State* temp = (State*)malloc(sizeof(State));
        printf("Enter value: %d\n", i + 1);
        temp->population_number = (rand() % 10) + 1;
        temp->country_name = (char*)malloc((len + 1) * sizeof(char));
        for (int k = 0; k < len; k++) {
            temp->country_name[k] = alphabet[rand() % (sizeof(alphabet) - 1)];
        }
        temp->country_name[len] = '\0';

        if (head == NULL) {
            temp->next = NULL;
            head = temp;
        } else {
            temp->next = NULL;
            State *temp1 = head;
            while (temp1->next != NULL) {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
}

void print_list()
{
    printf("Population number\tCountry name\n");
    State* temp = head;
    while(temp != NULL)
    {
        printf("%-23d%-20s\n",temp -> population_number,temp -> country_name);
        temp = temp -> next;
    }
    printf("\n\n");
}

void delete_element(int position)
{
    State * temp1 = head;
    if(position == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0; i < position - 2; i++)
        temp1 = temp1->next;

    State * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    print_list();
    printf("\n");
}

void insert_end()
{
    State* temp = (State*)malloc(sizeof(State));
    printf("Enter node values: \n");
    printf("Enter value 1 (Population number)\n");
    scanf("%d",&value1);
    getchar();
    if(head == NULL)
    {
        temp->population_number = value1;
        temp->country_name = init_string();
        temp->next = head;
        head = temp;
    }
    else{
        temp -> population_number = value1;
        temp->country_name = init_string();
        temp->next = NULL;
        State * temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1->next = temp;
    }
    print_list();
    printf("\n");
}

void insert_begin()
{
    printf("Enter node values:\n");
    printf("Enter value 1 (Population number)\n");
    scanf("%d",&value1);
    getchar();
    State* temp = (State*)malloc(sizeof(State));
    temp -> population_number = value1;
    temp -> country_name = init_string();
    temp -> next = head;
    head = temp;
    print_list();
    printf("\n");
}

void insert_at_position(int n)
{
    printf("Enter node values: \n");
    printf("Enter value 1 (Population number)\n");
    scanf("%d",&value1);
    getchar();
    State* temp1 = (State*)malloc(sizeof(State));
    temp1->population_number = value1;
    temp1 -> country_name = init_string();
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    State *temp2  = head;
    for(int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    print_list();
    printf("\n");
}

int search_position_by_number(int number)
{
    State* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(temp->population_number == number)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}

int search_position_by_string(char *search_str)
{
    State* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(strcmp(temp->country_name,search_str) == 0)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}

void reverse_list(State** root)
{
    State * prev = NULL;
    State * curr = *root;
    while(curr != NULL){
        State * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
    print_list();
    printf("\n");
}

void list_to_array()
{
    State *ptr = head;
    State *prev = NULL;
    int i = 0;
    word_array = malloc(sizeof(char*) * element_count);
    while(ptr != NULL)
    {
        prev = ptr;
        word_array[i++] = ptr->country_name;
        ptr = ptr->next;
    }
}

void sort_list()
{
    State *end, *r, *p, *q, *temp;
    if(choice == 1){
        for(end = NULL; end != head->next; end = p){
            
            for(r = p = head; p-> next!=end; r=p, p=p->next){
                q = p -> next;
                if(p -> population_number > q -> population_number)
                {
                    p->next = q->next;
                    q->next = p;
                    if(p != head)
                    {
                        r->next = q;
                    }
                    else
                    {
                        head = q;
                    } 
                        temp = p;
                        p = q;
                        q = temp;
                }
            }
        }
    }
    else if(choice == 2){

        list_to_array();
        int i, j;
        for (i = 0; i <= element_count - 1; i++){

                int min_index = i; 
            for (j = i + 1; j <= element_count - 1; j++){

            if(strcmp(word_array[min_index],word_array[j]) > 0){
                        min_index = j; 
                    }
                }
            if (min_index != i) {
                char * temp_string = word_array[i];
                word_array[i] = word_array[min_index];
                word_array[min_index] = temp_string;
            }
            }
        State *ptr = head; 
        i = 0;
        while(ptr != NULL){
            ptr->country_name = word_array[i++];
            ptr = ptr->next;   
        }
    }
    print_list();
}

void free_memory()
{
    State * curr = head;
    while(curr != NULL){
        State * temp = curr;
        curr = curr -> next;
        free(temp);
    }
    head = NULL;
}

void clean_list()
{
    State * curr = head;
    while(curr != NULL){
        curr->population_number = 0;
        curr -> country_name = NULL;
        curr = curr -> next;
    }
    print_list();
}
