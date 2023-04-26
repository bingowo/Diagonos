#include <stdio.h>
#include <stdlib.h>
long long int a[10001];
long long int cmp(const void*c, const void*d){
    long long int m,n,m1,n1;
    m=*(long long int*)c;
    n=*(long long int*)d;
    if(m<0) m=-m;
    if(n<0) n=-n;
    m1=m;
    n1=n;
    while(m>9) m/=10;
    while(n>9) n/=10;
    if(m!=n) return n-m;
    else if(m1>n1) return 1;
    else return -1;
}
