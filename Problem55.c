//
// Created by czk on 18-2-4.
//
#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numSize){
    int jump[numSize][numSize];
    // Initialization
    for(int i = 0;i < numSize;i++){
        jump[i][i] = 1;
    }
    for(int i = numSize - 2;i >= 0;i--){
        for(int j = i;j < numSize;j)
    }
}
