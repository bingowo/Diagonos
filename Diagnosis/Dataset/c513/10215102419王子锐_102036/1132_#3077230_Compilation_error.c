#include<stdio.h>

int main()
{
    char code[]="0123456789ABCDEF";
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) 
    {
        char s[32]={0};
        int n,r;
        scanf("%d%d", &n,&r);
        int sum=0;
        while(n)
        {
            sum=sum+n%r;
            n=n/r;
        }
        
        int cnt=0;
        do
        {
            s[cnt++]=code[sum%r];
            sum=sum/r;
        }while(sum);
                
        printf("case #%d:\n",i);
        for(int i=cnt-1;i>=0;i--)printf("%c",s[i]);
        printf("\n");
    }
}
}