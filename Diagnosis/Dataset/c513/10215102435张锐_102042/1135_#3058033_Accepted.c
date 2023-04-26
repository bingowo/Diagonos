#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int p[1000];
}Q;
void add(Q* a,int s1,int s2,int s3,int s)
{
    int last=0;
    for(int i=999;i>=0;i--)
    {
        int temp=(a[s1].p[i])+(a[s2].p[i])+(a[s3].p[i])+last;
        if(temp<=9) {a[s].p[i]=temp,last=0;}
        else {last=temp/10;a[s].p[i]=(temp-last*10);}
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int temp;
    if(n>5) temp=n+1;
    else temp=6;
    Q* s=(Q*) malloc((temp)*sizeof(Q));
    for(int i=0;i<6;i++) memset(s[i].p, 0, sizeof(int)*1000);
    s[1].p[999]=1;s[2].p[999]=2;s[3].p[999]=3;s[4].p[999]=6;s[5].p[999]=0,s[5].p[998]=1;
    for(int i=6;i<=n;i++)
    {
        memset(s[i].p, 0, sizeof(int)*1000);
        add(s,i-1,i-2,i-4,i);
    }
    int f=0;
    for(;f<1000;f++)
    {
        if(s[n].p[f]!=0) break;
    }
    for(;f<1000;f++) printf("%d",s[n].p[f]);
    free(s);
    return 0;
}