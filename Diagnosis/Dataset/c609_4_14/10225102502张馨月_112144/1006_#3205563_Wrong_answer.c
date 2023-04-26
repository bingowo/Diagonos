#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    char test[62];
    for(int i=0;i<t;i++)
    {
        scanf("%s",&test);
        int a[128];
        long long res=0;

        int digit=0,j;
        int n=1;
        char *p=test;
        for(j=0;j<128;j++)
            a[j]=-1;           
        a[*p]=1;       

        while(*++p)   
        {
            if(a[*p]==-1) 
            {
                a[*p]=digit;
                digit=digit?digit+1:2;
                n++;  
            }
        }
        if(n<2) n=2;


        p=test;
        while(*p)
            res=res*n+a[*p++];
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}