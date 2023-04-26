#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

map[10001]={0};

long long int change(int a)
{
    map[0]=0;
    map[1]=1;
    map[2]=1;
    long long int res;
    if (a==0){
        res=0;
    }
    else if (a==1||a==2){
        res=1;
    }
    else {
        res= map[a-1]+ map[a-2];
        map[a]=res;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        int a;
        scanf("%d",&a);
        printf("case #%d:\n",i);
        printf("%lld", change(a));
    }
    return 0;
}