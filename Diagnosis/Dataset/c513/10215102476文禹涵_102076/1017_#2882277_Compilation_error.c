#include<stdio.h>
 
int main()
{
    char s[51];
    scanf("%s",s);
    long long data[100];
    int cnt = 0;
    long long flag = 1;
    for(int i=0;s[i];i++)
    {
        switch(s[i])
        {
            case '(': flag = flag*1000;break;
            case ')': flag = flag/1000;break;
            default: data[cnt++] = Roma[s[i]]*flag; break;
            
        }
        
    }
    long long ans = 0;
    for(int i=0;i<cnt-1;i++)
    {
        if(data[i]<data[i+1]) 
        ans -= data[i];
        else ans += data[i];
        
    }
    ans += data[cnt-1];
    printf("%lld\n",ans);
}