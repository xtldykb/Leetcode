#include <stdlib.h>
#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int pos, * res;
    //returnSize = (int*)malloc(sizeof(int));
    for(pos=digitsSize-1;pos>=0;pos--){
        if(digits[pos]!=9)break;
    }
    if(pos>=0){
        * returnSize = digitsSize;
        res = (int*)malloc(digitsSize*sizeof(int));
        res = digits;
        res[pos]+=1;
        for(pos++;pos<digitsSize;pos++){
            res[pos]=0;
        }
    }
    else{
        * returnSize = digitsSize+1;
        res = (int*)malloc((digitsSize+1)*sizeof(int));
        res[0] = 1;
        for(pos=1;pos<digitsSize+1;pos++){
            res[pos] = 0;
        }
    }
    return res;
}

int main(){
    int digitsSize, * returnSize, * result;
    int digits[3] = {1, 2, 3};
    digitsSize = 3;
    returnSize = (int*)malloc(sizeof(int));
    result = plusOne(digits, digitsSize, returnSize);
    free(result);
    free(returnSize);
    return 0;
}