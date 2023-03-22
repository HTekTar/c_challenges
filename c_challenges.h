#ifndef C_CHALLENGES
#define C_CHALLENGES

#include <stddef.h>
#include <stdbool.h>


struct LinkedList{
    int val;
    struct LinkedList* next;
} ;

typedef struct LinkedList LinkedList;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



typedef struct TreeNode TreeNode;

LinkedList* reverse(LinkedList *);

void insertNode(TreeNode *node, TreeNode *root);
void deleteNode(TreeNode *);

void push(int);
int pop();
int peek();
bool isFull();
bool isEmpty();

bool Palindrom(const char* , int );
void primeNums();
int binary_search(int *, unsigned int, int);
void fizbuzz();
void matrixMul();
void merge_sort(int *, unsigned int);
void printbits(size_t , const void *);
int reverse_bits(int );
int reverse_bits_2(int );
int reverse_bits_3(int, size_t, size_t);

#endif