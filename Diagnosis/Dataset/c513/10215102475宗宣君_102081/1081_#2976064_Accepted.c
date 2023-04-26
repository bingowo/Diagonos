#include <stdio.h>
void trans(int *result,int a)
{
    int i = 0;
    do{
        result[i] = a%10;
        a = a/10;
        //printf("%d ",result[i]);
    }while(a>0);
}
void mul(int *result,int a)
{
    int i,carry = 0,t;
    for(i = 0;i<101;i++)
    {
        t = result[i]*a+carry;
        result[i]  = t%10;
        carry = t/10;
        //printf("%d ",result[i]);
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int a,n,k,result[101] = {0};
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0) printf("1");
        else{trans(result,a);
        for(j = 1;j<n;j++)
            mul(result,a);

        for(k = 100;k>=0;k--)
        {if(result[k]!=0) break;}
        for(j = k;j>=0;j--)
            printf("%d",result[j]);}
        printf("\n");

    }

    return 0;
}
