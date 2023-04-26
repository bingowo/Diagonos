#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

map[10001]={0};

long long int change(int a)
{
    map[2]=1;
    long long int res;
    if (a==0){
        res=0;
        map[a]=res;
    }
    else if (a==1||a==2){
        res=1;
        map[a]=res;
    }
    else {
        res= map[a-1]+map[a-2];
        map[a]=res;
    }
    return res;
}

int main()
{
    int t;
    int a;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&a);
        printf("case #%d:\n",i);
        printf("%lld\n", change(a));
    }
    return 0;
}