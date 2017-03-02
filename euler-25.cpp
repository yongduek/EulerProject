//
//  euler-25.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 29..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned long fnum[1000000];

unsigned long fibo (int n) {
    if (fnum[n-1] == 0)
        fnum[n-1] = fibo(n-1);
    if (fnum[n-2] == 0)
        fnum[n-2] = fibo(n-2);
    
    return fnum[n-1] + fnum[n-2];
}
int main()
{
    fnum[0]=1;
    fnum[1]=1;
    fnum[2]=1;
    bool flag=true;
    for (int i=3; flag; i++) {
        long num = fibo(i);
        printf("fibo[%d]= %ld\n", i, num);
        if (log10((double)num)==2) {
            printf("fibo[%d]= %ld\n", i, num);
            break;
        }
    }
    return 0;
}