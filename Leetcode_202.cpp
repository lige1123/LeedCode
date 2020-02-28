/*************************************************************************
> File Name: Leetcode_202.cpp
> Author: zhangze
> Mail: zhangze_8_8sina.com
> Created Time: Fri 28 Feb 2020 05:48:52 PM CST
************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int get_next(int n) {
    int temp = 0;
    while (n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
    }
    return temp;
}


bool isHappy(int n){
    int p = n, q = n;
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) break;
    }
    return q == 1;
}



