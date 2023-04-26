#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int diff(int x,int y)
{
    char s1[64] = {0},s2[64] = {0};

    int i = 0,j = 0,sum = 0;
    while(x>0){
        s1[i++] = x%2;
        x/=2;
    }
    while(y>0){
        s2[j++] = y%2;
        y/=2;
    }
    for(int k = 0;k < 64;k++)
    {
        if(s1[k] != s2[k]) sum++;
    }
    printf("%d\n", sum);
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T-->0){
        int x,y;
        scanf("%d %d",&x,&y);
        diff(x,y);
    }
}
