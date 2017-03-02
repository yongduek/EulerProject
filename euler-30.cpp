//
//  euler-30.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 12..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

inline int pow5(int a) { return a*a*a*a*a; }
inline int pow4(int a) { return a*a*a*a; }

int main() {
    for (int i=2; i<1000000; i++) {
        vector<int> ns;
        int a, b=i;
        while (b!=0) {
            a=b%10;
            b = (b-a)/10;
            ns.push_back(a);
        }
        
        if (i==1634)
            printf("--\n");
        
//        for (auto it=ns.begin(); it!=ns.end(); ++it) {
//            printf("%d ", *it);
        }
        printf("\n");
        
        int sum = 0;
        for (auto it=ns.begin(); it!=ns.end(); ++it)
            sum += pow4(*it);
        
        if (i == sum) {
            printf("%d = ", i);
            for (auto it=ns.begin(); it!=ns.end(); ++it) {
                printf(" + %d^5 ", *it);
            }
            printf("\n");
        }
    }
    
    return 0;
}