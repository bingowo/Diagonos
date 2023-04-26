#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {   int m;
        char b;
        scanf("%d%c",&m,&b);
        int a[50];
        int k;
        for(k=0;k<50&&a[k];k++)
        scanf("%d",&a[k]);
        a[k+1]=0;
        double data=0;
        int l=0;
        while(a[l])
        {data=data*1/8+a[l];
        l++;}
        printf("case #%d:\n",i);
        printf("%f\n",data);
        
    }
    return 0;
}