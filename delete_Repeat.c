#include <stdio.h>

int main(){
    int removeDuplicates(int* nums, int numsSize);
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    int c;
    c = removeDuplicates(a, 10);
    return 0;
}

int removeDuplicates(int* nums, int numsSize){
    int i, index;
    if(numsSize == 0) return 0;
    for(i=1, index=0; i<numsSize; i++){
        if(* (nums+i) != * (nums+index)){
            index++;
            * (nums+index) = * (nums+i);
        }
    }
    return index + 1;
}