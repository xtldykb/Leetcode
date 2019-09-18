#include <stdlib.h>
#include <stdio.h>
typedef int bool;

bool cmp(const int a, const int b){
    return(a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int Max, i, *Res, *ResReal, * pnums1, * pnums2;
    pnums1 = nums1;
    pnums2 = nums2;
    i = 0;
    if(nums1Size>nums2Size)Max=nums1Size;
    else Max=nums2Size;
    Res = (int *)malloc(sizeof(int)*Max);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    while((nums1<pnums1+nums1Size) && (nums2<pnums2+nums2Size)){
        if(*nums1<*nums2)nums1++;
        else if(*nums1>*nums2)nums2++;
        else{
            *(Res+i) = *nums1;
            i++;nums1++;nums2++;
        }
    }
    * returnSize = i;
    ResReal = (int*)realloc(Res, i*sizeof(int));
    return ResReal;
}

int main(){
    int *p, nums1Size, nums2Size, *returnSize, i;
    int nums1[4] = {1, 2, 2, 1};
    int nums2[2] = {2, 2};
    nums1Size = 4;
    nums2Size = 2;
    returnSize = (int*)malloc(sizeof(int));
    p = intersect(nums1, nums1Size, nums2, nums2Size, returnSize);
    for(i=0;i<*returnSize;i++){
        printf("%d\n",*(p+i));
    }
    free(p);
    free(returnSize);
    return 0;
}