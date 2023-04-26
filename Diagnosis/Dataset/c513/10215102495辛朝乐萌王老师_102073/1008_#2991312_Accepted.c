#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int solve(int m,int n)
{
    int count = 0;
    int flag=m^n;
    int num=1;
    for (int i=0; i<32; i++,num=num<<1) {
        if((flag&num)==num){count++;}
    }
    return count;
}

int main()
{
    int t;
    int m,n;
    int count;
    scanf("%d",&t);
    for(int i=0; i<t; i++) {
        scanf("%d %d",&m,&n);
        count = solve(m, n);
        printf("%d\n",count);
    }
    return 0;
}
