#include<stdio.h>
#include<string.h>

int f(int n,char origin[],int len)
{
    int m=0,new;
    char M[len];
    for(int i=0;i<len;i++)//对M赋值
    {
        M[i]=origin[len-1-i];
        m += (M[i]-'0');
        m = m*10;
    }
    new = n+m;
    char s[5];
    int LEN;
    LEN = new/10;
    for(int i=0;i<LEN;i++)
    {
        int temp=new;
        s[LEN-1-i] = '0' + temp%10;
        temp = temp/10;
    }
    int time=0,mark=0;
    if(len%2 == 0)//偶数位
    {
        for(int i=0;i<len/2;i++)
        {
            if(origin[i] == origin[len-1-i]);
            else
            {
                mark=1;
                break;
            }
        }
    }
    else//奇数位
    {
        for(int i=0;i<len/2;i++)
        {
            if(origin[i] == origin[len-1-i]);
            else
            {
                mark=1;
                break;
            }
        }
    }
    int cnt=0;
    if(mark == 1)
    {
        cnt++;
        return f(new,s,LEN);
    }
        
    else
        return n;
    
}

int main()
{
    char origin[5];
    int n=0,len;
    scanf("%s",origin);
    len = strlen(origin);
    for(int i=0;i<len;i++)
    {
        n += (origin[i]-'0');
        n = 10*n;
    }
    int ans;
    ans = f(n,origin,len);
    printf("%d",ans);
    return 0;
}

