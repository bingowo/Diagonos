#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print(char s[],int len)
{
    int a[100000],b[100000];
    for (int i = 0; i < 100000; ++i) {
        a[i]=0;
        b[i]=0;
    }
    for (int i = 0; i < len; ++i) {
        if (a['s[i]']!=0) {
            printf("%c",s[i]);
            a['s[i]']=1;
        } else{ continue;}
    }
}


int main()
{
    char s[1000000];
    int n=0;
    while(scanf("%c",&s[n])!=0) {n++;}
    
    print(s);
    return 0;
}
