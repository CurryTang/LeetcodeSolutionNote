//
// Created by czk on 18-1-2.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int reverse(int x){
    int sign, absVal, result, lastDigit;
    absVal = abs(x);
    sign = 1;
    result = 0;
    if (x < 0){
        sign = -1;
    }
    while(absVal >= 1){
        lastDigit = absVal % 10;
        absVal /= 10;
        int oldresult = result;
        result = result * 10 + lastDigit;
        if (result < oldresult){
            return 0;
        }
        if (result / 10.0 < oldresult){
            return 0;
        }
    }
    return result * sign;
}


int main(void){
    printf("INT MAX: %d\n", INT_MAX);
    int result = reverse(-153);
    printf("The result of the reverse should be: %d\n", result);
    return 0;
}