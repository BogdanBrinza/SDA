#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 30

typedef struct Node {
    int key;
    char name[MAX_NAME_LENGTH];
    int age;
    float sum_to_give;
    struct Node *left;
    struct Node *right;
} TreeNode;

typedef struct Queue {
    TreeNode *tree_node;
    struct Queue *next;
} Queue;

typedef struct {
    Queue *front;
    Queue *rear;
} QueueHead;

TreeNode* root;
unsigned int node_count = 0;

void show_menu();
void add_node();
void print_tree();
void inorder_traversal(TreeNode *root);
void postorder_traversal(TreeNode *root);
void preorder_traversal(TreeNode *root);
void dfs_traversal(TreeNode *root);
void bfs_traversal(TreeNode *root);
int get_tree_depth(TreeNode *root);
TreeNode* insert_node(TreeNode *root, int key, char *name, int age, float sum);
TreeNode* delete_node(TreeNode *root, int key);
TreeNode* create_tree_node(int key, char *name, int age, float sum);
int find_node_depth_by_key(TreeNode *root, int key);
bool search_node_by_key(TreeNode *root, int key);
int total_nodes(TreeNode *root);
void delete_tree(TreeNode **root);
void show_all_leaves(TreeNode *root);
void clean_tree(TreeNode *root);
void print_level_order(TreeNode *root);
Queue* create_new_queue_node(TreeNode *node);
void add_to_queue(QueueHead *queue, TreeNode *node);
TreeNode* remove_from_queue(QueueHead *queue);
void reflect_tree(TreeNode **root);
TreeNode** create_array_to_store_tree(TreeNode *root, int *nr_of_nodes);
TreeNode** get_tree_to_array(TreeNode *root, TreeNode **tree_nodes, int *i);
TreeNode* create_balance_tree(int start, int end, TreeNode **tree_nodes);

int main() {
    int option;
    root = NULL;
    srand(time(NULL));

    while (1) {
        show_menu();
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                add_node();
                break;
            case 2:
                print_tree();
                break;
            case 3:
                {
                    int key;
                    printf("Enter key to search for:\n");
                    scanf("%d", &key);
                    getchar();
                    if (search_node_by_key(root, key)) {
                        printf("Node with key %d found.\n", key);
                    } else {
                        printf("Node with key %d not found.\n", key);
                    }
                }
                break;
            case 4:
                printf("Inorder traversal:\n");
                inorder_traversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal:\n");
                preorder_traversal(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal:\n");
                postorder_traversal(root);
                printf("\n");
                break;
            case 7:
                printf("DFS traversal:\n");
                dfs_traversal(root);
                printf("\n");
                break;
            case 8:
                printf("BFS traversal:\n");
                bfs_traversal(root);
                printf("\n");
                break;
            case 9:
                delete_tree(&root);
                printf("aight, removed the tree ))\n");
                break;
            case 0:
                delete_tree(&root);
                exit(0);
                break;
            default:
                printf("incorrect option u got a range 0-9\n");
        }
    }

    return 0;
}

void show_menu() {
    printf("-------------Menu-------------\n");
    printf("1.       Add node              \n");
    printf("2.       Print tree            \n");
    printf("3.       Search node by key    \n");
    printf("4.       Inorder traversal     \n");
    printf("5.       Preorder traversal    \n");
    printf("6.       Postorder traversal   \n");
    printf("7.       DFS traversal         \n");
    printf("8.       BFS traversal         \n");
    printf("9.       Delete tree           \n");
    printf("0.       Exit                  \n");
    printf("------------------------------\n");
}

void add_node() {
    int key, age;
    char name[MAX_NAME_LENGTH];
    float sum;

    printf("Enter key for the node:\n");
    scanf("%d", &key);
    getchar();
    printf("Enter name for the node:\n");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter age for the node:\n");
    scanf("%d", &age);
    getchar();
    printf("Enter sum to give for the node:\n");
    scanf("%f", &sum);
    getchar();

    root = insert_node(root, key, name, age, sum);
}

void print_tree() {
    printf("Tree elements:\n");
    inorder_traversal(root);
    printf("\n");
}

void inorder_traversal(TreeNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("Key: %d, Name: %s, Age: %d, Sum: %.2f\n", root->key, root->name, root->age, root->sum_to_give);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(TreeNode *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("Key: %d, Name: %s, Age: %d, Sum: %.2f\n", root->key, root->name, root->age, root->sum_to_give);
    }
}

void preorder_traversal(TreeNode *root) {
    if (root != NULL) {
        printf("Key: %d, Name: %s, Age: %d, Sum: %.2f\n", root->key, root->name, root->age, root->sum_to_give);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void dfs_traversal(TreeNode *root) {
    preorder_traversal(root);
}

void bfs_traversal(TreeNode *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    QueueHead queue = {NULL, NULL};
    add_to_queue(&queue, root);
    while (queue.front != NULL) {
        TreeNode *node = remove_from_queue(&queue);
        printf("Key: %d, Name: %s, Age: %d, Sum: %.2f\n", node->key, node->name, node->age, node->sum_to_give);
        if (node->left != NULL) {
            add_to_queue(&queue, node->left);
        }
        if (node->right != NULL) {
            add_to_queue(&queue, node->right);
        }
    }
}

TreeNode* create_tree_node(int key, char *name, int age, float sum) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    strcpy(node->name, name);
    node->age = age;
    node->sum_to_give = sum;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert_node(TreeNode *root, int key, char *name, int age, float sum) {
    if (root == NULL) {
        return create_tree_node(key, name, age, sum);
    }
    if (key < root->key) {
        root->left = insert_node(root->left, key, name, age, sum);
    } else {
        root->right = insert_node(root->right, key, name, age, sum);
    }
    return root;
}

TreeNode* delete_node(TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode *temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            root->key = temp->key;
            strcpy(root->name, temp->name);
            root->age = temp->age;
            root->sum_to_give = temp->sum_to_give;
            root->right = delete_node(root->right, temp->key);
        }
    }
    return root;
}

bool search_node_by_key(TreeNode *root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->key == key) {
        printf("Node found:\nKey: %d, Name: %s, Age: %d, Sum: %.2f\n", root->key, root->name, root->age, root->sum_to_give);
        return true;
    }
    if (key < root->key) {
        return search_node_by_key(root->left, key);
    } else {
        return search_node_by_key(root->right, key);
    }
}

int total_nodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + total_nodes(root->left) + total_nodes(root->right);
}

void delete_tree(TreeNode **root) {
    if (*root != NULL) {
        delete_tree(&(*root)->left);
        delete_tree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

Queue* create_new_queue_node(TreeNode *node) {
    Queue *new_node = (Queue*)malloc(sizeof(Queue));
    new_node->tree_node = node;
    new_node->next = NULL;
    return new_node;
}

void add_to_queue(QueueHead *queue, TreeNode *node) {
    Queue *new_node = create_new_queue_node(node);
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

TreeNode* remove_from_queue(QueueHead *queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Queue *temp = queue->front;
    TreeNode *node = temp->tree_node;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}
