#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double s[26];
double Turn(char p)
{
    double x;
    int x1;
    if(p<'a'){ x1 = p-'A';x = s[x1];}
    else if(p>='a'){x1 = p-'a';x = s[x1];}
    return x;
}
int cmp(const void*a,const void*b)
{
    char p1 = *(char*)a,p2 = *(char*)b;
    double x1 = Turn(p1),x2 = Turn(p2);
    if(x1>x2)return -1;
    else if(x1<x2)return 1;
    else if(x1 == x2)
    {
        if(p1-p2=='a'-'A')return -1;
        else if(p2-p1=='a'-'A')return 1;
        else return p2-p1;
    }
}
int main()
{
    int n,i,j;char a[200];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<26;j++)
            scanf("%lf",&s[j]);
        scanf("%s",a);
        qsort(a,strlen(a),sizeof(a[0]),cmp);
        printf("case #%d:\n%s\n",i,a);
    }
    return 0;
}
