//
//  euler-27.cpp
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
#include <set>
#include <map>

using namespace std;

vector<long> prime1000;
set<long> primes;

bool isPrime (long num) {
    if (num<1) return false;
    if (num%2==0) return false;
    
//    if (num==1681) {
//        printf ("%ld: ", num);
//    }
    
    bool isprime=true;
    for (int k=3; k*k<=num; k+=2)
        if (num%k==0) { isprime=false; break; }
    
//    if (num==1681) {
//        printf ("%s\n", isprime?"prime" : "not prime");
//    }
    
    return isprime;
}

void find_primes ()
{
    primes.insert(2);
    long max = 10000;
    for (long i=3; i<max; i+=2) {
        // check if this number i is prime
        bool isprime=true;
        for (int k=3; k*k<=i; k+=2)
            if (i%k==0) { isprime=false; break; }
        if (isprime)
            primes.insert(i);
    }
    return;
}

int getNumPrimes (long a, long b) {
//    vector<int> ps;
    set<int> ps;
    bool flag = true;
    int n;
    for (n=0; flag; n++) {
        long num = long(n*n + a*n + b);
        if (a==-61 && b==971 ) {
            fprintf (stderr, "(%d, %ld)", n, (num));
        }
        if (isPrime((num))) {
            ps.insert(num);
            if (a==-61 && b==971 )
                {
                printf("%d: %ld %d\n", n, num, ps.size());
//                for (auto it=ps.begin(); it!=ps.end(); ++it)
//                    printf("%ld ", *it);
//                printf("\n");
                }
        }
//            ps.push_back(num);
        else
            flag = false;
    }
    
    if (a==-61 && b==971) {
        printf("(%ld, %ld): ", a, b);
        for (auto it=ps.begin(); it!=ps.end(); ++it)
            printf("%ld ", *it);
        printf("\n");
////        exit (0);
    }
    
//    return n-1;
    return ps.size();
}

int main()
{
    // 1. primes < 1000
    find_primes();
    for (auto it=primes.begin(); it!=primes.end(); ++it) {
        cout << *it << endl;
        if (*it < 1000)
            prime1000.push_back(*it);
    }
    
    //
    
    long ap, bp;
    int nmax=0;
    for (int i=0; i<prime1000.size() && prime1000[i]<1000; i++) {
        long b = prime1000[i];
//    for (long b=-999; b<=999; b++) {
        
        for (long a=-b-2; a<=999; a++) {
            int np = getNumPrimes(a, b);
            if (nmax < np) {
                nmax = np;
                ap = a;
                bp = b;
                printf ("(%ld  %ld) -> %4d  (max=%d)\n", a, b, np, nmax);

            }
        }
    }
    printf ("a*b = %ld\n", ap*bp);
    return 0;
}