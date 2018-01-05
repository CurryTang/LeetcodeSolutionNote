//
// Created by czk on 18-1-5.
//

#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

bool isPalindrome(int x){
    if (x < 0){
        return false;
    }
    if (x >= 0 && x <= 9){
        return true;
    }
    int length = floor(log10(x)) + 1;
    for(int i = 0;i < floor(length / 2);i++){
        int div1 = (int)pow(10, length -1 - i);
        int div1_prime = 10;
        int div2 = 10;
        int div2_prime = (int)pow(10, i);
        int num1 = ((int)floor(x / div1)) % div1_prime;
        int num2 = ((int)floor(x / div2_prime)) % div2;
        if (num1 != num2){
            return false;
        }
    }
    return true;
}

int main(void){
    int test1 = 11234211;
    int test2 = INT_MAX;
    bool result1 = isPalindrome(test1);
    bool result2 = isPalindrome(test2);
//    int test = 1234567;
//    for(int i = 0;i < 7;i++){
//        int div2 = 10;
//        int div2_prime = (int)pow(10, 6 - i);
//        printf("%d\n", ((int)floor(test / div2_prime)) % div2);
//    }
    return 0;
}