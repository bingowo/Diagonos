#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {   int m;
        char b;
        scanf("%d%c",&m,&b);
        char a[50];
        scanf("%s",&a);
        double data=0;
        int l=0;
        while(a[l]!=' ')
        {data=data*1/8+a[l]-'0';
        l++;}
        printf("case #%d:\n",i);
        printf("%f\n",data);
        
    }
    return 0;
}