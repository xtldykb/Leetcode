#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

//hash结构
struct myHash{
    int id;
    int value;
    UT_hash_handle hh;
};
struct myHash *intHash = NULL;

//插入函数
void add_item(int id, int value, struct myHash *exist_Struct){
    struct myHash *s;
    s = (struct myHash *)malloc(sizeof(struct myHash));
    s->id = id;
    s->value = value;
    HASH_ADD_INT(exist_Struct, id, s);
}

//查找函数
struct myHash *find_key(int user_key,struct myHash *exist_Struct){
    struct myHash *s;
    HASH_FIND_INT(exist_Struct, &user_key, s);
    return s;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, leftNum;
    
    //struct myHash *intHash = NULL;
    struct myHash *my_find;
    //新建hashtable
    for(i=0;i<numsSize;i++){
        add_item(nums[i], i, intHash);
    }
    //逐个判断
    for(i=0;i<numsSize;i++){
        leftNum = target - nums[i];
        my_find = find_key(leftNum, intHash);
        if(my_find!=NULL && my_find->value!=i){
            * returnSize = 2;
            int* res = (int*)malloc(2*sizeof(int));
            res[0] = i;
            res[1] = my_find->value;
            return res;
        }
    }
}

int main(){
    int nums[4] = {1,3,4,8};
    int numsSize = 4;
    int* result;
    int* returnSize = (int*)malloc(sizeof(int));
    result = twoSum(nums, numsSize, 4, returnSize);
    return 0;
}