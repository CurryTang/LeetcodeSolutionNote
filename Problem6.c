//
// Created by czk on 17-12-28.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows){
    if (numRows == 1){
        return s;
    }
    int length = strlen(s);
    if (length <= numRows){
        return s;
    }
    char *result = malloc(sizeof(char) * (length+1));
    int magic = 2 * numRows - 2;
    int initialDistance = magic;
    int pos = 0;
    int start;
    for(int i = 0;i < numRows;i++){
        start = i;
        int backup = initialDistance;
        while(start < length){
            if (initialDistance == 0){
                initialDistance = magic;
            }
            result[pos++] = s[start];
            start = start + initialDistance;
            initialDistance = magic - initialDistance;
        }
        initialDistance = backup;
        initialDistance -= 2;
    }
    result[pos++] = '\0';
    return result;
}

int main(void){
    char input[15] = "PAYPALISHIRING";
    char *output;
    output = convert(input, 3);
    printf("The result should be:%s\n", output);
    return 0;
}