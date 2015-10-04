#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t SIZE = 200;
static char DATA[] = "This is the payload\n";

typedef struct Node {
    struct Node *left, *right; // Pointers to the right an dleft child nodes
    size_t size;   // size of the data payload
    char data[];    // the data itself
} Node_t;

Node_t *fillNode (Node_t* first, Node_t* second, 
                char *d1) 
{
    Node_t* prim = calloc(1, sizeof(Node_t) + SIZE);
    prim->left = first;
    prim->right = second;
    prim->size = SIZE; 
    memcpy(prim->data, d1, prim->size);
    //strcpy(prim->data, d1);
    return prim;
}

int main()
{
    //size_t size = 100;
    //char* data = "This is the payload\n";
    Node_t *second;
    Node_t *third;
    Node_t *first;
    first = calloc(1, sizeof(Node_t) + SIZE);
    first->left = NULL;
    first->right = NULL;
    first->size = SIZE; 
    //memcpy(first->data, DATA, sizeof(DATA) +1);
    strcpy(first->data, DATA);

    char DATA2[] = "Second Payload! It works!\n";
    Node_t* from_func = fillNode(third, second, DATA2);

    printf("%s", from_func->data);
}