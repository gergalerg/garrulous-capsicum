#ifndef _BSTree_h_
#define _BSTree_h_
#include <stdio.h>
#include <stdlib.h>

const void *defaultGetKey(const void *pData);

// obtain a key that corresponds to the data passed into it.
typedef const void *GetKeyFunc_t(const void *dData);


// compoares to keys and returns -1 to 0 to +1 int.
// Like bsearch() func in c
typedef int CmpFunc_t(const void *pKey1, const void *pKey2);

// Node in tree
typedef struct Node { struct Node *left, *right;
        size_t size;
        char data[];
    } Node_t;

// Struct to represent Tree
typedef struct {
    struct Node *pRoot; // Pointer to the root
    CmpFunc_t *cmp; // compares two keys
    GetKeyFunc_t *getKey; // Converts data into key value
} BST_t;


// Function prototypes for BSTree.
// dynamically generates a new object iwth the type BST_t and
// returns a pointer to it
BST_t *newBST(CmpFunc_t *cmp, GetKeyFunc_t *getKey);

// Dynamically generates a new node, copies the data referenced
// by pData to the node, and inserts the node in the specified tree
_Bool BST_insert( BST_t *pBST, const void *pData, size_t size);

static _Bool insert(BST_t *pBST, Node_t **ppNade, const void *pData,
                    size_t size);

// searches the tree and returns pointer to the data item that
// matches the key reference by the pKey args
const void *BST_search(BST_t *, const void *pKey);

// deletes the first node whose data contents matche the key 
// referenced by  pKey
_Bool BST_erase(BST_t *pBST, const void *pKey);

// deletes all nodes in tree
void BST_clear(BST_t *pBST);

// traverese the tree in a certain order and calls the func referenced by action
// to manipulate the data contents of each node.
int BST_inorder(BST_t *pBST, _Bool (*action)(void *pData));

int BST_rev_inorder(BST_t *pBST, _Bool(*action)(void *pData));

int BST_preorder(BST_t *pBST, _Bool(*action)(void *pData));

int BST_postorder(BST_t *pBST,  _Bool (*action)(void *pData));

static const void *search(BST_t *pBST, const Node_t *pNode,
                        const void *pKey);

static _Bool erase(BST_t *pBST, Node_t **ppNode, const void *pKey );

static void clear(Node_t *pNode);

static int inorder( Node_t *pNode, _Bool(*action)(void *pData));

#endif // end _BSTree_h_