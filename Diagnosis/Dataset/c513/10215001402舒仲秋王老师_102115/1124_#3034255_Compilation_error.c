#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a,const void* b)
{
    int d1,d2;
    d1=*((int*)a),d2=*((int*)b);
    return d1-d2
}

int GCD(int a,int b)
{
   if(a==0) return b;
   else return GCD(b%a,a);
}

int main()
{
    int N,k;
    scanf("%d",&N);
    for(k=0;k<N;k++)
    {
        int n,i,j;
        scanf("%d",&n);
        int NUM[1001]={0};
        for(i=0;i<n;i++)
            scanf("%d",&NUM[i]);
        qsort(NUM,n,sizeof(NUM[0]),cmp1);
        int num[1001]={0};
        for(i=0,j=0;i<n;i++)
            if(NUM[i]!=NUM[i+1]) num[j++]=NUM[i];
        int flag=j;
        int sum=0;
        for(i=0;i<flag;i++)
            for(j=i+1;j<flag;j++)
                if(GCD(num[i],num[j])==1) sum++;
        printf("case #%d:\n",k);
        printf("%d\n",sum);
    }
    return 0;
}
