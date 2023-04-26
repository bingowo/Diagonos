#include<stdio.h>
#include<string.h>

int main()
{
    char s[20];
    scanf("%s",s);
    int len;
    long long int x=0;
    len = strlen(s);
    for(int i=2;i<len;i++)//得到初始数字x的十进制表达
    {
        if(s[i]>64 && s[i]<91)
            x+=s[i]-'A'+10;
        else
            x+=s[i]-'0';
        
        x=x*16;
    }
    x=x/16;
    printf("%lld\n",x);
    //算出二进制表达
    
    long long int temp=x/2;
    long long int m=x%2,n=0;
    for(int i=1;i<250;i++)
    {
        if(temp==0)
            break;
        long long int k=m;
        m = m*(-1)+n*(-1);
        n = k-n;
        if(i>0 && temp%2==1)
        {
        	m--;
        	n++;
        }
        temp = temp/2;
    }
    
    if(m==0)
    {
        if(n==0)
            printf("0");
        else if(n==1)
            printf("i");
        else if(n==-1)
            printf("-i");
        else
        {
            printf("%lldi",n);
        }
    }
    else
    {
        printf("%lld",m);
        if(n==0);
        else if(n==1)
            printf("+i");
        else if(n==-1)
            printf("-i");
        else if(n>0)
        	printf("%lldi",n);
        else if(n<0)
            printf("%lldi",n);
    }
    return 0;
}
