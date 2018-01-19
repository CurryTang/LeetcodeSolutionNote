//
// Created by czk on 18-1-19.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>

int minDistance(char *word1, char *word2){
    int range = strlen(word1);
    int length = strlen(word2);
    int result[range + 1][length + 1];
    for(int j = 0;j <= range;j++){
        // must be all deletes
        result[j][0] = j;
    }
    for(int j = 0;j <= length;j++){
        // must be insertions
        result[0][j] = j;
    }
    for(int i = 1;i <= range;i++){
        for(int j = 1;j <= length;j++){
            // four actions possible: copy(0), insert(1), delete(1), replace(1)
            result[i][j] = INT_MAX;
            if (word1[i - 1] == word2[j - 1]){
                result[i][j] = result[i - 1][j - 1];
            }
            if(word1[i - 1] != word2[j - 1] && result[i][j] > result[i - 1][j - 1] + 1){
                // replace
                result[i][j] = result[i - 1][j - 1] + 1;
            }if (result[i - 1][j] + 1 < result[i][j]){
                // delete
                result[i][j] = result[i - 1][j] + 1;
            }if (result[i][j - 1] + 1 < result[i][j]){
                // insert
                result[i][j] = result[i][j - 1] + 1;
            }
        }
    }
    return result[range][length];
}


int main(void){
    char testChar1[10] = "a";
    char testChar2[15] = "b";
    int result1 = minDistance(testChar1, testChar2);
    printf("The final result should be %d\n", result1);
    return 0;
}