#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%c",&a,&b);
        int a[50];
        for(int k=0;k<50&&a[k];k++)
        scanf("%d",&a[k]);
        a[k+1]=0;
        char*p;
        p=a;
        double data=0;
        while(*p)
        {data=data*1/8+a[*p];
        p++;}
        printf("case #%d:\n",i);
        printf("%f\n",data);
        
    }
    return 0;
}