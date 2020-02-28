/*************************************************************************
> File Name: Leetcode_287.cpp
> Author: zhangze
> Mail: zhangze_8_8sina.com
> Created Time: Fri 28 Feb 2020 05:39:08 PM CST
************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int findDuplicate(int* nums, int numsSize) {
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    q = nums[0];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}


