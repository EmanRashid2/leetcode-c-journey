int removeElement(int* nums, int numsSize, int val){
    int k = 0; // index for placing non-val elements

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[k] = nums[i]; // move non-val element to the front
            k++;
        }
    }

    return k; // number of elements not equal to val
}

