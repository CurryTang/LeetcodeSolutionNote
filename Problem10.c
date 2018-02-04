//
// Created by czk on 18-2-4.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p){
    int m = strlen(s);
    int n = strlen(p);
    bool match[m + 1][n + 1];
    for(int i = 0;i <= m;i++){
        for(int j = 0;j <= n;j++){
            match[i][j] = false;
        }
    }
    match[m][n] = true;


    for(int i = m;i >= 0;i--){
        for(int j = n - 1;j >= 0;j--){
            bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
            if (j + 1 < n && p[j+1] == '*'){
                match[i][j] = (match[i][j + 2]) || (first_match && match[i + 1][j]);
            } else {
                match[i][j] = first_match && match[i + 1][j + 1];
            }
        }
    }

    return match[0][0];

}

int main(void){
    char testString1[10] = "aaa";
    char testp[10] = "aa";
    bool result = isMatch(testString1, testp);
    return 0;
}