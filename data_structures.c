#include <stddef.h>
#include "c_challenges.h"

#define MAX_SZ 100

int stack_arr[MAX_SZ];
int top = -1;

TreeNode root = {0, NULL, NULL};

LinkedList* reverse(LinkedList *head){
    if(head->next == NULL) return head;
    LinkedList *prev = NULL;
    LinkedList *curr = head;
    LinkedList *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}



void insertNode(TreeNode *root_node, TreeNode *node){
    if(root_node->val >= node->val){
        if(root_node->left == NULL){
            root_node->left = node;
        }
        else insertNode(root_node->left, node);
    }
    else {
        if(root_node->right == NULL){
            root_node->right = node;
        }
        else insertNode(root_node->right, node);
    }
}

void insert(TreeNode *node){
    insertNode(node, &root);
}

TreeNode* findMaximum(TreeNode *node){
    if(node->right == NULL) return node;
    return findMaximum(node->right);
}

TreeNode* findParentNode(TreeNode *rootNode, TreeNode *node){
    if(rootNode == NULL) return NULL;
    if(rootNode->left == node || rootNode->right == node) return rootNode;
    TreeNode *left = findParentNode(rootNode->left, node);
    if(left != NULL) return left;
    return findParentNode(rootNode->right, node);
}

TreeNode* findParent(TreeNode *node){
    return findParentNode(&root, node);
}


void deleteNode(TreeNode *node){
    //find node's parent
    TreeNode *parent = findParent(node);
    //if parent not found, return
    if(parent == NULL) return;

    bool isLeftChild = parent->left == node;
    TreeNode *left = node->left;
    TreeNode *right = node->right;

    //if node has only one child, make it the heir
    TreeNode *heir = NULL;
    if(left && right == NULL){
        heir = left;
        return;
    }
    else if(right && left == NULL){
        heir = right;
        return;
    }
    //if node has both children,
    else if(left && right){
        //find the maximum child node of the left child and make it the parent of the right child
        TreeNode *rightMost = findMaximum(left);
        rightMost->right = right;
        heir = left;
    }

    if(isLeftChild) parent->left = heir;
    else parent->right = heir;
}

void push(int data){
    if(top == MAX_SZ-1) return;
    stack_arr[++top] = data;
}
int pop(){
    if(top == -1) return -1;
    int item = stack_arr[top];
    top --;
    return item;
}
int peek(){
    if(top < 0) return -1;
    return stack_arr[top];
}
bool isFull(){
    return top == MAX_SZ - 1;
}
bool isEmpty(){
    return top < 0;
}
