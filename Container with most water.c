#include <stdio.h>

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate current area
        int minHeight = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = minHeight * width;

        if (area > max_area)
            max_area = area;

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

