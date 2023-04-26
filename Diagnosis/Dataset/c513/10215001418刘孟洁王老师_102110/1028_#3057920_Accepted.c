#include<stdio.h>
#include<math.h>

int cmp1(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    return c-d;
}

int cmp2(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    return d-c;
}

int main()
{
    char c;
    int ans[1005],p[1005],i=0,j=0,k=0,x=0;
    scanf("%c",&c);
    while(scanf("%d",&p[i])!=EOF)
           i++;
    ans[0]=p[0];
    for(j=1,k=1;j<i;j++)
    {
        x=0;
        while(x<k)
        {
            if(p[j]!=ans[x])  x++;
            else break;
        }
        if(x==k)
        {
            ans[k]=p[j];
            k++;
        }
    }
    switch(c)
    {
        case 'A':qsort(ans,k,sizeof(int),cmp1);break;
        case 'D':qsort(ans,k,sizeof(int),cmp2);break;
    }
    for(i=0;i<k;i++)
        printf("%d%c",ans[i],i==k-1?'\n':' ');//别忘记%c
    return 0;
}
