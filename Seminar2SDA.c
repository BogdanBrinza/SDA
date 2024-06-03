#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct Document {
    int doc_id;
    char *doc_name;
    int total_nr_of_lines;
    int left_lines_to_print;
    struct Document *next;
} Document;

typedef struct Printer {
    int printer_id;
    int time_to_print;
    Document *printer_doc;
    struct Printer *next;
} Printer;

typedef struct Printed_docs {
    int doc_id;
    char *doc_name;
    int total_nr_of_lines;
    int left_lines_to_print;
    struct Printed_docs *next;
} Printed_docs;

typedef struct Queue {
    Document *front;
    Document *rear;
} Queue;

// Function Prototypes
void add_new_doc_in_queue(Document **queue, Queue *refr, int id, char *name, int total_lines, int left_lines);
void delete_a_document_from_queue(Document **refr, int id);
Printer *initialize_printer(FILE *imprimante);
void add_printer(Printer **printer_list, FILE *imprimante);
void delete_printer(Printer **printers_list, int printer_id);
void distribute_documents(Document **docs_queue, Queue *element, Printer **printers_list);
Printer *pop_printer(Printer **printers_refr);
Document *pop_document(Queue *element);
void update_printers_and_docs_status(Printer **printers_list, Document **docs_queue, Printed_docs **processed_docs);
void delete_a_document_from_waiting_queue(Document **docs_queue);
void add_finished_doc_to_processed_list(Document **printers_doc, Printed_docs **processed_docs);
void show_current_status_of_printers_and_docs(Document *docs_queue, Printer *printers_list, Printed_docs *printed_docs);
Document *sort_documents_after_no_lines(Document *head);
Document *merge_documents(Document *l1, Document *l2);
Printer *sort_printers_after_time_to_print(Printer *head);
Printer *merge_printers(Printer *l1, Printer *l2);
void show_processed_docs(Printed_docs *processed_list);
void free_all_memory(Document **refr1, Printer **refr2);
void show_menu();

// Function Definitions
void add_new_doc_in_queue(Document **queue, Queue *refr, int id, char *name, int total_lines, int left_lines) {
    Document *new_doc = (Document *)malloc(sizeof(Document));
    new_doc->doc_id = id;
    new_doc->doc_name = strdup(name);
    new_doc->total_nr_of_lines = total_lines;
    new_doc->left_lines_to_print = left_lines;
    new_doc->next = NULL;

    if (*queue == NULL) {
        *queue = new_doc;
        refr->front = new_doc;
    } else {
        Document *temp = *queue;
        while (temp->next) {
            temp = temp->next;
        }
        refr->rear = new_doc;
        temp->next = new_doc;
    }
}

void delete_a_document_from_queue(Document **refr, int id) {
    if (*refr == NULL) {
        printf("Document queue is empty\n");
        return;
    }

    Document *curr_node = *refr;
    Document *pre_node = NULL;

    while (curr_node != NULL) {
        if (curr_node->doc_id == id) {
            if (pre_node == NULL) {
                *refr = curr_node->next;
                free(curr_node->doc_name);
                free(curr_node);
                return;
            } else {
                pre_node->next = curr_node->next;
                free(curr_node->doc_name);
                free(curr_node);
                return;
            }
        }
        pre_node = curr_node;
        curr_node = curr_node->next;
    }
}

Printer *initialize_printer(FILE *imprimante) {
    int printing_time;
    static int printers_nr = 1;
    Printer *printer = (Printer *)malloc(sizeof(Printer));
    printer->printer_id = printers_nr;
    fscanf(imprimante, "%d\n", &printing_time);
    printer->time_to_print = printing_time;
    printer->printer_doc = NULL;
    printer->next = NULL;
    printers_nr++;
    return printer;
}

void add_printer(Printer **printer_list, FILE *imprimante) {
    Printer *new_printer = initialize_printer(imprimante);
    if (*printer_list == NULL) {
        *printer_list = new_printer;
    } else {
        Printer *temp = *printer_list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_printer;
    }
}

void delete_printer(Printer **printers_list, int printer_id) {
    if (*printers_list == NULL) {
        printf("Printer queue is empty\n");
        return;
    }

    Printer *curr_node = *printers_list;
    Printer *pre_iter_printer = NULL;

    while (curr_node) {
        if (curr_node->printer_id == printer_id) {
            if (pre_iter_printer == NULL) {
                *printers_list = curr_node->next;
                free(curr_node);
                return;
            } else {
                pre_iter_printer->next = curr_node->next;
                free(curr_node);
                return;
            }
        }
        pre_iter_printer = curr_node;
        curr_node = curr_node->next;
    }
}

void distribute_documents(Document **docs_queue, Queue *element, Printer **printers_list) {
    if (*docs_queue == NULL || *printers_list == NULL) {
        printf("No documents or printers available.\n");
        return;
    }

    Printer *curr_printer = *printers_list;
    Document *selected_doc = NULL;
    Printer *selected_printer = NULL;

    int available_printers = 0;

    while (curr_printer != NULL) {
        if ((curr_printer->printer_doc == NULL) || (curr_printer->printer_doc->left_lines_to_print == 0)) {
            available_printers++;
        }
        curr_printer = curr_printer->next;
    }

    if (available_printers == 0) {
        printf("No printers available\n");
        return;
    } else {
        while (element->front != element->rear) {
            selected_printer = pop_printer(printers_list);
            selected_doc = pop_document(element);

            if (selected_printer != NULL && selected_doc->left_lines_to_print > 0 && selected_doc != NULL) {
                selected_printer->printer_doc = selected_doc;
                printf("Document = %s(%d/%d) assigned to printer %d with time %d\n",
                       selected_printer->printer_doc->doc_name,
                       selected_printer->printer_doc->left_lines_to_print,
                       selected_printer->printer_doc->total_nr_of_lines,
                       selected_printer->printer_id,
                       selected_printer->time_to_print);
                available_printers--;
            }
        }
    }
}

Printer *pop_printer(Printer **printers_refr) {
    Printer *iter = *printers_refr;
    while (iter != NULL) {
        if (iter->printer_doc == NULL || iter->printer_doc->left_lines_to_print == 0) {
            return iter;
        } else {
            iter = iter->next;
        }
    }
    return NULL;
}

Document *pop_document(Queue *element) {
    if (element->front == NULL)
        return NULL;

    Document *temp = element->front;
    element->front = element->front->next;
    return temp;
}

void update_printers_and_docs_status(Printer **printers_list, Document **docs_queue, Printed_docs **processed_docs) {
    Printer *curr_printer = *printers_list;
    int not_printed = 0;

    while (curr_printer != NULL) {
        if (curr_printer->printer_doc != NULL && curr_printer->printer_doc->left_lines_to_print > 0) {
            curr_printer->printer_doc->left_lines_to_print -= curr_printer->time_to_print;

            if (curr_printer->printer_doc->left_lines_to_print <= 0) {
                curr_printer->printer_doc->left_lines_to_print = 0;
                printf("Document %s(%d/%d) printed with printer %d\n",
                       curr_printer->printer_doc->doc_name,
                       curr_printer->printer_doc->left_lines_to_print,
                       curr_printer->printer_doc->total_nr_of_lines,
                       curr_printer->printer_id);

                add_finished_doc_to_processed_list(&curr_printer->printer_doc, processed_docs);
                delete_a_document_from_waiting_queue(docs_queue);
            } else {
                not_printed++;
            }
        }
        curr_printer = curr_printer->next;
    }
    if (not_printed == 0)
        printf("Documents are in the process of being printed...\n");
}

void delete_a_document_from_waiting_queue(Document **docs_queue) {
    Document *pre_iterator = NULL;
    Document *iterator = *docs_queue;
    while (iterator != NULL) {
        if (iterator->left_lines_to_print == 0) {
            if (pre_iterator == NULL) {
                *docs_queue = iterator->next;
                free(iterator->doc_name);
                free(iterator);
            } else {
                pre_iterator->next = iterator->next;
                free(iterator->doc_name);
                free(iterator);
            }
        }
        pre_iterator = iterator;
        iterator = iterator->next;
    }
}

void add_finished_doc_to_processed_list(Document **printer_doc, Printed_docs **processed_docs) {
    Printed_docs *iter_printed_list = NULL;
    Printed_docs *new_doc = (Printed_docs *)calloc(1, sizeof(Printed_docs));
    new_doc->doc_id = (*printer_doc)->doc_id;
    new_doc->doc_name = strdup((*printer_doc)->doc_name);
    new_doc->total_nr_of_lines = (*printer_doc)->total_nr_of_lines;
    new_doc->left_lines_to_print = (*printer_doc)->left_lines_to_print;
    (*printer_doc) = NULL;

    iter_printed_list = *processed_docs;

    if (iter_printed_list == NULL) {
        *processed_docs = new_doc;
    } else {
        while (iter_printed_list->next != NULL) {
            iter_printed_list = iter_printed_list->next;
        }
        iter_printed_list->next = new_doc;
    }
}

void show_current_status_of_printers_and_docs(Document *docs_queue, Printer *printers_list, Printed_docs *printed_docs) {
    show_processed_docs(printed_docs);

    printf("Queue of unprocessed documents:\n");
    Document *temp_doc = docs_queue;

    while (temp_doc != NULL) {
        printf("Document %d: %s (%d/%d)\n",
               temp_doc->doc_id,
               temp_doc->doc_name,
               temp_doc->left_lines_to_print,
               temp_doc->total_nr_of_lines);
        temp_doc = temp_doc->next;
    }

    printf("\nList of printers:\n");
    Printer *temp_printer = printers_list;

    while (temp_printer != NULL) {
        printf("Printer %d: print time %d\n",
               temp_printer->printer_id,
               temp_printer->time_to_print);

        temp_printer = temp_printer->next;
    }
}

Document *sort_documents_after_no_lines(Document *head) {
    if (head == NULL || head->next == NULL)
        return head;

    Document *temp = NULL;
    Document *slow = head;
    Document *fast = head;

    while (fast != NULL && fast->next != NULL) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    Document *l1 = sort_documents_after_no_lines(head);
    Document *l2 = sort_documents_after_no_lines(slow);

    return merge_documents(l1, l2);
}

Document *merge_documents(Document *l1, Document *l2) {
    Document *ptr = (Document *)malloc(sizeof(Document));
    Document *curr = ptr;

    while (l1 != NULL && l2 != NULL) {
        if (l1->left_lines_to_print >= l2->left_lines_to_print) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != NULL) {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL) {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}

Printer *sort_printers_after_time_to_print(Printer *head) {
    if (head == NULL || head->next == NULL)
        return head;

    Printer *temp = NULL;
    Printer *slow = head;
    Printer *fast = head;

    while (fast != NULL && fast->next != NULL) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    Printer *l1 = sort_printers_after_time_to_print(head);
    Printer *l2 = sort_printers_after_time_to_print(slow);

    return merge_printers(l1, l2);
}

Printer *merge_printers(Printer *l1, Printer *l2) {
    Printer *ptr = (Printer *)malloc(sizeof(Printer));
    Printer *curr = ptr;

    while (l1 != NULL && l2 != NULL) {
        if (l1->time_to_print >= l2->time_to_print) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != NULL) {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL) {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}

void show_processed_docs(Printed_docs *processed_list) {
    printf("Queue of processed documents:\n");
    Printed_docs *temp_doc = processed_list;

    while (temp_doc != NULL) {
        printf("Document %d: %s (%d/%d)\n",
               temp_doc->doc_id,
               temp_doc->doc_name,
               temp_doc->left_lines_to_print,
               temp_doc->total_nr_of_lines);
        temp_doc = temp_doc->next;
    }
}

void free_all_memory(Document **refr1, Printer **refr2) {
    Document *curr1 = *refr1;
    while (curr1 != NULL) {
        Document *temp = curr1;
        curr1 = curr1->next;
        free(temp->doc_name);
        free(temp);
    }
    *refr1 = NULL;

    Printer *curr2 = *refr2;
    while (curr2 != NULL) {
        Printer *temp = curr2;
        curr2 = curr2->next;
        free(temp);
    }
    *refr2 = NULL;
}

void show_menu() {
    printf("-------------Menu-------------\n");
    printf("\n       ---  Select an option: ---           \n");
    printf("1.       Add documents->                      \n");
    printf("2.       Add printers->                       \n");
    printf("3.       Show current queue status            \n");
    printf("4.       Cancel a document                    \n");
    printf("5.       Free all memory                      \n");
    printf("6.       Distribute documents to printers     \n");
    printf("7.       Update printer and document status   \n");
    printf("8.       Delete a printer by ID               \n");
    printf("9.       Show processed documents             \n");
    printf("0.       Exit                                 \n");
    printf("------------------------------\n");
}

int main() {
    Document *docs_queue = NULL;
    Printer *printers_list = NULL;
    Printed_docs *printed_docs = NULL;
    Queue *queue_refr = NULL;
    queue_refr = (Queue *)calloc(1, sizeof(Queue));
    FILE *file = fopen("Doc1.txt", "r");
    FILE *imprimante = fopen("Imprimante.txt", "r");
    Document *iter = NULL;
    int total_docs = 1;
    int option;

    while (1) {
        int nr_of_printers;
        int nr_of_docs;
        char doc_name[30];
        int doc_nr_of_lines;
        int doc_nr_of_left_lines;
        int doc_id_to_delete;
        int printer_id_to_delete;
        show_menu();
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1:
                printf("Enter the number of documents\n");
                scanf("%d", &nr_of_docs);
                getchar();

                for (int i = 1; i <= nr_of_docs; i++) {
                    int id = total_docs;
                    total_docs++;
                    fscanf(file, "%d,%29[^,],%d,%d\n", &id, doc_name, &doc_nr_of_lines, &doc_nr_of_left_lines);
                    add_new_doc_in_queue(&docs_queue, queue_refr, id, doc_name, doc_nr_of_lines, doc_nr_of_left_lines);
                }
                break;

            case 2:
                printf("Enter the number of printers\n");
                scanf("%d", &nr_of_printers);
                getchar();
                for (int i = 0; i < nr_of_printers; i++) {
                    add_printer(&printers_list, imprimante);
                }
                break;

            case 3:
                show_current_status_of_printers_and_docs(docs_queue, printers_list, printed_docs);
                break;

            case 4:
                printf("Enter the document ID to delete\n");
                scanf("%d", &doc_id_to_delete);
                delete_a_document_from_queue(&docs_queue, doc_id_to_delete);
                break;

            case 5:
                free_all_memory(&docs_queue, &printers_list);
                break;

            case 6:
                docs_queue = sort_documents_after_no_lines(docs_queue);
                printers_list = sort_printers_after_time_to_print(printers_list);
                iter = docs_queue;
                queue_refr->front = docs_queue;
                while (iter) {
                    iter = iter->next;
                }
                queue_refr->rear = iter;

                distribute_documents(&docs_queue, queue_refr, &printers_list);
                break;

            case 7:
                update_printers_and_docs_status(&printers_list, &docs_queue, &printed_docs);
                break;

            case 8:
                printf("enter the specific printer id to delete\n");
                scanf("%d", &printer_id_to_delete);
                delete_printer(&printers_list, printer_id_to_delete);
                break;

            case 9:
                show_processed_docs(printed_docs);
                break;

            case 0:
                free_all_memory(&docs_queue, &printers_list);
                fclose(file);
                fclose(imprimante);
                return 0;

            default:
                printf("you have 0-9 cases, please choose accordingly\n");
        }
    }
}
