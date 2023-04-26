#include <stdio.h>
#include <stdlib.h>

int cmp(const void*p1,const void*p2)
{
    int*p1_=*(int(*)[2])p1;
    int*p2_=*(int(*)[2])p2;
    if(p1_[0]<=p2_[0])return 1;
    else return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
    int num1[200] ={0};
    int num2[200] ={0};
    int n;
    scanf("%d",&n);
    int (*p)[2] = (int(*)[2])malloc(sizeof(int)*1e6*2);
    int po=0;
    memset(p,0,sizeof(int)*1e6*2);
    for(int k=0;k<n;k++)
    {
        int a;
        int b;
        scanf("%d%d",&a,&b);
        if(a==b)continue;
        else
        {
            num1[a]++;
            num2[b]++;
            p[po][0] = a;
            p[po][1] = b;
            po++;
        }
    }
    qsort(p,po,sizeof(int)*2,cmp);
    int flag =0;
    for(int z=1;z<po;z++)
    {
        if(p[z][0]==p[z-1][0])
        {
            if(p[z][1]!=p[z-1][1])flag=1;
        }
    }
    int q;
    for(q=0;q<101;q++)
    {
        if(num1[q]&&num2[q])
        {
            flag=1;
            break;
        }
    }
    if(flag)printf("Poor dxw!\n");
    else printf("Lucky dxw!\n");
    }
    return 0;
}
