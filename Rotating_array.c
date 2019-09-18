#include <stdio.h>

int main(){
    void rotate(int* nums, int numsSize, int k);
    int a[2] = {1, 2};
    rotate(a, 2, 2);
    return 0;
}

void rotate(int* nums, int numsSize, int k){
    int temp1, prev, i, j, current;
    if(numsSize==0||numsSize==1)return;
    for(i=0,j=0,current=0,prev=* nums;i<numsSize;i++){
        j=(j+k)%numsSize;
        temp1=*(nums + j);
        *(nums + j)=prev;
        prev=temp1;
        if(j==current){
            j++;current++;
            prev=* (nums + j);
        }
    }
}