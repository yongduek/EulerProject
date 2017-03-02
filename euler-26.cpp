//
//  euler-26.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 12..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int cycleLength (int d) {
    set<int> rs;
    vector<int> a;
    int n = 1;
    int q, r;
    while (1)
        {
        q = n/d;
        r = n%d;
        a.push_back (q);
        if (!rs.empty() && (rs.find(r) != rs.end())) {
            break;
        }
        rs.insert(r);
        n = r*10;
        }
    if (r==0) return 0;
//    printf("-- 1/%d\n", d);
//    printf(" rc (%d): ", rs.size());
//    for (auto it=rs.begin(); it!=rs.end(); ++it)
//        printf("%d ", *it);
//    printf("\n");
//    printf("rest %d again\n", r);
//    for (int k=0; k<a.size(); ++k)
//        printf("%d", a[k]);
//    printf("\n");
    // now auto-correlation to find the period
    return rs.size();
}

int main()
{
    int maxlen = 0, maxi;
    for (int i=7; i<=1000; i+=2) {
        if (i%5==0) continue;
        int len = cycleLength (i);
        if (maxlen < len) maxi=i, maxlen=len;
    }
    printf("max cycle length of %d = %d\n", maxi, maxlen);
    return 0;
}