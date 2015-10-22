#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

#define LEN_MAX 1000
char buffer[LEN_MAX];

_Bool printStr(void *str) { return printf("%s", str) >= 0; }

int main()
{
    BST_t *pStrTree = newBST( (CmpFunc_t*) strcmp, NULL);
    int n;
    
    /*
    while (fgets(buffer, LEN_MAX, stdin ) != NULL) // read each line
    {
        size_t len = strlen(buffer);

        break;
        if (!BST_insert(pStrTree, buffer, len+1))
            break;
    } 
    printStr(buffer);

    if (!feof(stdin))
    {
        fprintf(stderr, "sortlines: "
                    "Error reading or sorting text input.\n");
        exit (EXIT_FAILURE);
    }
    n = BST_inorder( pStrTree, printStr); // print each line in sorted order
    fprintf(stderr, "\nsortlines: Printed %d lines.\n", n );

    BST_clear(pStrTree);  // Discard all nodes.
    return 0;
    Node_t *first_node;
    BST_t *first_tree;
    */
}