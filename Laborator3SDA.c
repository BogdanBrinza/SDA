#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 30

struct Node {
    int age;
    char *name;
    struct Node *left;
    struct Node *right;
};

typedef struct Node TreeNode;
TreeNode* root;
unsigned int node_count = 0;

void show_menu();
void add_node();
void print_tree();
void inorder_traversal(TreeNode *root);
void postorder_traversal(TreeNode *root);
void preorder_traversal(TreeNode *root);
int get_tree_depth(TreeNode *root);
TreeNode* insert_node(TreeNode *root, int age, char *name);
int find_node_depth_by_age(TreeNode *root, int age);
int find_node_depth_by_name(TreeNode *root, char *name);
void delete_tree(TreeNode **root);
void show_all_leaves(TreeNode *root);
void clean_tree(TreeNode *root);
bool search_node_by_age(TreeNode *root, int age);
bool search_node_by_name(TreeNode *root, char *name);
int total_nodes();
char* get_input_string(char *str);

int main() {
    int option;
    root = NULL;
    srand(time(NULL));

    while (1) {
        show_menu();
        scanf("%d", &option);
        getchar(); // pentru a consuma newline-ul rămas

        switch (option) {
            case 1:
                add_node();
                break;
            case 2:
                print_tree();
                break;
            case 3:
                printf("Inorder traversal:\n");
                inorder_traversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal:\n");
                postorder_traversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal:\n");
                preorder_traversal(root);
                printf("\n");
                break;
            case 6:
                printf("Tree depth: %d\n", get_tree_depth(root));
                break;
            case 7:
                {
                    int search_option;
                    printf("1. Search by age\n");
                    printf("2. Search by name\n");
                    scanf("%d", &search_option);
                    getchar();

                    if (search_option == 1) {
                        int age;
                        printf("Enter age:\n");
                        scanf("%d", &age);
                        getchar();
                        if (search_node_by_age(root, age)) {
                            printf("Node found\n");
                        } else {
                            printf("Node not found\n");
                        }
                    } else {
                        char name[MAX_NAME_LENGTH];
                        printf("Enter name:\n");
                        get_input_string(name);
                        if (search_node_by_name(root, name)) {
                            printf("Node found\n");
                        } else {
                            printf("Node not found\n");
                        }
                    }
                }
                break;
            case 8:
                {
                    int depth_option;
                    printf("1. Depth by age\n");
                    printf("2. Depth by name\n");
                    scanf("%d", &depth_option);
                    getchar();

                    if (depth_option == 1) {
                        int age;
                        printf("Enter age:\n");
                        scanf("%d", &age);
                        getchar();
                        printf("Node depth: %d\n", find_node_depth_by_age(root, age));
                    } else {
                        char name[MAX_NAME_LENGTH];
                        printf("Enter name:\n");
                        get_input_string(name);
                        printf("Node depth: %d\n", find_node_depth_by_name(root, name));
                    }
                }
                break;
            case 9:
                {
                    int height_option;
                    printf("1. Height by age\n");
                    printf("2. Height by name\n");
                    scanf("%d", &height_option);
                    getchar();

                    if (height_option == 1) {
                        int age;
                        printf("Enter age:\n");
                        scanf("%d", &age);
                        getchar();
                        printf("Node height: %d\n", get_tree_depth(root) - find_node_depth_by_age(root, age));
                    } else {
                        char name[MAX_NAME_LENGTH];
                        printf("Enter name:\n");
                        get_input_string(name);
                        printf("Node height: %d\n", get_tree_depth(root) - find_node_depth_by_name(root, name));
                    }
                }
                break;
            case 10:
                printf("Leaves:\n");
                show_all_leaves(root);
                printf("\n");
                break;
            case 11:
                clean_tree(root);
                break;
            case 12:
                delete_tree(&root);
                break;
            case 13:
                printf("Total nodes: %d\n", total_nodes());
                break;
            case 0:
                delete_tree(&root);
                exit(0);
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

void show_menu() {
    printf("-------------Menu-------------\n");
    printf("1.       Add node                 \n");
    printf("2.       Print tree               \n");
    printf("3.       Inorder traversal        \n");
    printf("4.       Postorder traversal      \n");
    printf("5.       Preorder traversal       \n");
    printf("6.       Tree depth               \n");
    printf("7.       Search node              \n");
    printf("8.       Node depth               \n");
    printf("9.       Node height              \n");
    printf("10.      Show leaves              \n");
    printf("11.      Clean tree               \n");
    printf("12.      Delete tree              \n");
    printf("13.      Total nodes              \n");
    printf("0.       Exit                     \n");
    printf("-------------------------------\n");
}

void add_node() {
    int age;
    char name[MAX_NAME_LENGTH];

    if (root == NULL) {
        printf("Enter root age:\n");
    } else {
        printf("Enter node age:\n");
    }
    scanf("%d", &age);
    getchar(); // pentru a consuma newline-ul rămas

    printf("Enter node name:\n");
    get_input_string(name);

    root = insert_node(root, age, name);
}

void print_tree() {
    printf("Tree elements:\n");
    inorder_traversal(root);
    printf("\n");
}

void inorder_traversal(TreeNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("Age: %d, Name: %s\n", root->age, root->name);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(TreeNode *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("Age: %d, Name: %s\n", root->age, root->name);
    }
}

void preorder_traversal(TreeNode *root) {
    if (root != NULL) {
        printf("Age: %d, Name: %s\n", root->age, root->name);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int get_tree_depth(TreeNode *root) {
    if (root == NULL) 
        return -1;
    int left_depth = get_tree_depth(root->left);
    int right_depth = get_tree_depth(root->right);
    return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
}

TreeNode* insert_node(TreeNode *root, int age, char *name) {    
    if (!root) {
        root = (TreeNode*)calloc(1, sizeof(TreeNode));
        root->name = malloc((strlen(name) + 1) * sizeof(char));
        strcpy(root->name, name);
        root->age = age;
        node_count++;
        return root;
    }
    
    int balance = get_tree_depth(root->left) - get_tree_depth(root->right);
    
    if (balance <= 0)
        root->left = insert_node(root->left, age, name);
    else 
        root->right = insert_node(root->right, age, name);

    return root;
}

int find_node_depth_by_age(TreeNode *root, int age) {
    if (root == NULL) 
        return -1;

    int dist = -1;

    if ((root->age == age) ||
        (dist = find_node_depth_by_age(root->left, age)) >= 0 ||
        (dist = find_node_depth_by_age(root->right, age)) >= 0)
        return dist + 1;

    return dist;   
}

int find_node_depth_by_name(TreeNode *root, char *name) {
    if (root == NULL) 
        return -1;

    int dist = -1;

    if ((strcmp(root->name, name) == 0) ||
        (dist = find_node_depth_by_name(root->left, name)) >= 0 ||
        (dist = find_node_depth_by_name(root->right, name)) >= 0)
        return dist + 1;

    return dist;   
}

bool search_node_by_age(TreeNode *root, int age) {
    if (root == NULL) {
        return false;
    }
    
    if (root->age == age) {
        return true; 
    }
    
    bool found_in_left_subtree = search_node_by_age(root->left, age);
    bool found_in_right_subtree = search_node_by_age(root->right, age);
    
    return found_in_left_subtree || found_in_right_subtree;
}

bool search_node_by_name(TreeNode *root, char *name) {
    if (root == NULL) {
        return false;
    }
    
    if (strcmp(root->name, name) == 0) {
        return true; 
    }
    
    bool found_in_left_subtree = search_node_by_name(root->left, name);
    bool found_in_right_subtree = search_node_by_name(root->right, name);
    
    return found_in_left_subtree || found_in_right_subtree;
}

int total_nodes() {
    return node_count;
}

char* get_input_string(char *str) {
    fgets(str, MAX_NAME_LENGTH, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

void delete_tree(TreeNode **root) {
    if (*root) {
        delete_tree(&(*root)->left);
        delete_tree(&(*root)->right);
        free((*root)->name);
        free(*root);
        *root = NULL;
    }
    node_count = 0;
}

void show_all_leaves(TreeNode *root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("Leaf: Age: %d, Name: %s\n", root->age, root->name);
        return;
    }

    if (root->left)
        show_all_leaves(root->left);
    if (root->right)
        show_all_leaves(root->right);
}

void clean_tree(TreeNode *root) {
    if (root != NULL) {
        clean_tree(root->left);
        root->age = 0;
        free(root->name);
        root->name = NULL;
        clean_tree(root->right);
    }
}
