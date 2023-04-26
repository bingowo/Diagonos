#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {   int m,k=0;
        char b;
        scanf("%d%c",&m,&b);
        int a[50];
        while(scanf("%d",&a[k])!=EOF)
        k++;
        double data=0;
        while(k>=0)
        {data=data*1/8+a[k];k--}
        printf("case #%d:\n",i);
        printf("%f\n",data);
        
    }
    return 0;
}