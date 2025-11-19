int jump(int* nums, int numsSize) {
    int jumps = 0;
    int farthest = 0;
    int end = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        // update the farthest place reachable from current range
        if (i + nums[i] > farthest)
            farthest = i + nums[i];

        // if we reached end of current jump, we must jump
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }

    return jumps;
}

