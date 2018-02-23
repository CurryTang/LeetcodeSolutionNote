//
// Created by czk on 18-2-23.
//
#include <stdio.h>
#include <wchar.h>
#include <malloc.h>

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int leftsize = 0, rightsize = 0;
    if (!root){
        return NULL;
    }
    
    int *left_part = inorderTraversal(root->left, &leftsize);
    int *right_part = inorderTraversal(root->right, &rightsize);
    
    *returnSize = 1 + leftsize + rightsize;
    int *ret = malloc(sizeof(int) * (*returnSize));
    int i, j;
    for(i = 0;i < leftsize;i++){
        ret[i] = left_part[i];
    }
    ret[i++] = root->val;
    for(j = 0;j < rightsize;j++){
        ret[i+j] = right_part[j];
    }
    free(left_part);
    free(right_part);
    return ret;
}
