#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct p{
    char s[16];
    int n1;

} a[10000];
int cmp(const void*a,const void*b){
    int a1=((struct p*)a)->n1,b1=((struct p*)b)->n1;
    char*p1=((struct p*)a)->s,*p2=((struct p*)b)->s;
    if(a1>b1)return 1;
    else if(a1<b1) return -1;
    else return strcmp(p1,p2);
}
int main()
{
    int n;
    scanf("%d",&n);
    int b[200];
    for (int i=0; i<n; i++)
    {
        memset(b,-1,sizeof(b));
        scanf("%s",a[i].s);
        char*t=a[i].s;
        int num=0;
        for (int j=0; j<strlen(t); j++)
        {
            if (b[t[j]]==-1)
            {
                if (j==0) b[t[j]]=1;
                else b[t[j]]=num++;
                if (num==1) num++;
            }
        }
        if (num==0)num=2;
        a[i].n1=0;
        for (int j=0; j<strlen(t); j++)
        {
            a[i].n1=a[i].n1*num+b[t[j]];
        }


    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++)
        printf("%s\n",a[i].s);

    return 0;
}