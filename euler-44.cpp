//
//  euler-44.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 24..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<long> ps;

long pentagon (long j) { return j*(3*j-1)/2; }
bool isPentagonal( long x ) {
    double p = (sqrt(24*x+1) + 1)/6.;
    return (p == ((int)p));
}
int main()
{
    long i=1, j, a, b, diffmin = 1000000;
    bool notfound=true;
    while (notfound) {
        long pi = pentagon(i++);
        for (j=i-1; j>0; j--) {
            long pj = pentagon(j);
            if (pi==2167 && pj==1020) {
                printf("2167\n");
            }
            if (isPentagonal(pi+pj) && isPentagonal(pi-pj)) {
                printf (" > found: %ld + %ld = %ld  (d=%ld)\n", pi, pj, pi+pj, pi-pj);
                if (diffmin < (pi-pj)) {
                    a=pi, b=pj;
                    diffmin = pi-pj;
                }
            }
        }
    }
    
    return 0;
}