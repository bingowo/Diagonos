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
        scanf("%s",&a);
        int l=0;
        double data=0;
        char *p=a;
        while(*p)
        {l++;p++;}
        p--;
        while(l>0)
        {data=data*1/8+a[*p];p--}
        printf("case #%d:\n",i);
        printf("%f\n",data);
        
    }
    return 0;
}