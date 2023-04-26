#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {   char s[1000];
        scanf("%s\n",&s);
        int a[50];
        for(int k=0;k<50;k++)
        a[k]=-2;
        a['-']=-1;
        a['0']=0;
        a['1']=1;
        long long int data=0;
        char *p;
        p=s;
        while(*p)
        {data=data*3+a[*p];
        p++;}
        printf("case #%d:\n",i);
        printf("%lld\n",data);
    }
    return 0;
    
    
}