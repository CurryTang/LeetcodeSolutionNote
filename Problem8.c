//
// Created by czk on 18-1-5.
//

#include <stdio.h>
#include <limits.h>

int myatoi(char *str){
    int i = 0, sign = 1, abs = 0;
    while(str[i] == ' ') i++;
    if (str[i] == '+' || str[i] == '-'){
        sign = (str[i] == '+') ? 1 : -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        if (abs > INT_MAX / 10 || (abs == INT_MAX / 10 && (str[i] - '0' > 7))){
            if (sign == 1){
                return INT_MAX;
            }
            return INT_MIN;
        }
        abs = 10 * abs + str[i++] - '0';
    }
    return sign * abs;
}

int main(void){
    char testCase[50] = "      -2147483647";
    char testCaseb[50] = "     010";
    int result1 = myatoi(testCase);
    int result2 = myatoi(testCaseb);
    printf("The result should be %d\t%d\n", result1, result2);
    return 0;
}
