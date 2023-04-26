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
    if(x>16)
        x=x/16;
    
    //算出二进制表达
    int a[250];
    long long int m=0,n=0;
    long long int temp=x;
    for(int i=0;i<250;i++)
    {
        if(temp==0)
            break;
        a[i]=temp%2;
        temp = temp/2;
        long long int k=m;
        m = m*(-1)+n*(-1);
        n = k-n;
        if(a[i]==1)
        {
        	m--;
        	n++;
        }
            
    }
    if(m!=0)
        printf("%lld",m);
    if(n>1)
        printf("+%lldi",n);
    else if(n==0);
    else if(n==1)
        printf("i");
    else if(n==-1)
        printf("-i");
    else
        printf("%lldi",n);
    return 0;
}
