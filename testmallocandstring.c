//
// Created by czk on 17-12-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char s[10] = "abcdefg";
    char *malloc_s = malloc(sizeof(char) * strlen(s) + 1);
    char *str = s;
    char *mallocstring = malloc_s;
    while(*str != '\0'){
        *mallocstring = *str;
        mallocstring++;
        str++;
    }
    *mallocstring = '\0';
    printf("The length of the declared string should be: %d\n", (int)strlen(s));
    printf("The allocated string:%s\n", malloc_s);
    printf("The the equivalence of [] operator: %c", malloc_s[3]);
    free(malloc_s);
    return 0;
}