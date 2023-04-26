#include<stdio.h>
#include<string.h>

int main()
{
    char s[250];
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
    //算出二进制表达
    
    long long int temp=x;
    int a[505];
    int mark;
    for(int r=0;;r++)//倒着放二进制
    {
        if(temp==0)
        {
            mark = r;
            break;
        }
        a[r] = temp%2;
        temp = temp/2;
    }
    //从mark-1位开始，倒着往前
    long long int sh1=0,sh2=0,yu=1,m,n;
    for(int i=mark-1;i>0;i--)
    {
        long long int tp = sh1;
        sh1 = sh1*(-1)+sh2*(-1)+yu;
        sh2 = tp - sh2;
        yu = a[i-1];
    }
    long long int z = sh1;
    m = sh1*(-1)+sh2*(-1)+yu;
    n = z - sh2;
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
        	printf("+%lldi",n);
        else if(n<0)
            printf("%lldi",n);
    }
    return 0;
}
