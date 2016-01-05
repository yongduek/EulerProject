//
//  Prob-21.cpp
//  Euler-11
//
//  Created by Yongduek Seo on 2016. 1. 5..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<int> vi;

void print (const vi& vec, const string str="") {
    if (!str.empty())
        printf("%s: ", str.c_str());
    for (int i=0; i<vec.size(); i++)
        printf ("%d  ", vec[i]);
    printf("\n");
}

vi findDivisors (const int N, const bool flagProperDivisors=true) {
    vi divisors;
    for (int d=1; d<N; d++)
        if (N%d==0)
            divisors.push_back(d);
    
    if (flagProperDivisors==false)
        divisors.push_back(N);
    
    return divisors;
}

int sumVI(const vi vec) {
    int s=0;
    for (int i=0; i<vec.size(); i++)
        s += vec[i];
    return s;
}
int main()
{
    int number = 220;
    vi d220 = findDivisors(number);
    print (d220, "d(220)");
    int sum = sumVI(d220);
    printf ("sum(d220)= %d\n", sum);
    
    int number2 = sum;
    vi dvs = findDivisors(number2);
    print(dvs, "d("+to_string(sum)+")");
    int sum2 = sumVI(dvs);
    printf ("sum(d(%d))= %d\n", sum, sum2);
    
    if (number == sum2 && number2 == sum)
        printf ("The two numbers %d and %d are amicable numbers.\n", sum, sum2);
    
    printf(" -------------- \n" );
    bool amicableNumbers[10000]={false};
    int sum_ami=0;
    for (int a=2; a<10000; a++) {
        vi divs = findDivisors(a);
        int d_a = sumVI(divs);
        
        if (d_a>=10000) continue;
        
        int b = d_a;
        vi divs2 = findDivisors(b);
        int d_b = sumVI(divs2);
        
        if (d_a == b && d_b == a && a!=b) {
            amicableNumbers[a] = amicableNumbers[b] = true;
            printf ("The two numbers %d and %d are amicable numbers.\n", a, b);
            printf ("d(%d)=%d , d(%d)=%d\n", a, d_a, b, d_b);
            sum_ami += (a + b);
        }
    }
    printf ("sum_ami = %d\n", sum_ami);
    
    int sum_amicalbes = 0;
    for (int i=0; i<10000; i++)
        if (amicableNumbers[i])
            sum_amicalbes += i;
    printf ("# sum_amicables = %d\n", sum_amicalbes);
    return 0;
}