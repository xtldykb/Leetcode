#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int firstUniqChar(char * s){
    int i, alphaList[26];
    //第一次存入数组
    for(i=0;i<strlen(s);i++){
        alphaList[s[i] - 'a'] += 1;
    }
    //第二次提取判断第一个值为1的
    for(i=0;i<strlen(s);i++){
        if(alphaList[s[i] - 'a'] == 1)return i;
    }
    return -1;
}

int main(){
    char s[] = 'leetcode';
    int res = firstUniqChar(s);
    retrun 0;
}