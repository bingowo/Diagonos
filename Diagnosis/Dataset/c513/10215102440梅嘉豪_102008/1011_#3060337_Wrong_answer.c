#include <stdio.h>
#include <string.h>

char s[10000]={0};
void con(long long n);

int main()
{
    long long n;
    scanf("%x",&n);
    // printf("%d\n",x);
    con(n);
    // printf("%s\n",s);
    long long qa=0,qb=0,ta,tb;
    for(int i=0;i<strlen(s);i++)
    {
        // printf("%d %d\n",qa,qb);
        ta=-qa-qb+(s[i]-'0');
        tb=qa-qb;
        qa=ta;qb=tb;
    }
    if(qa!=0)   printf("%lld",qa);
    if(qb>0)
    {
        if(qa==0)
        {
            if(qb==1)   printf("i");
            else printf("%lldi",qb);
        }
        else
        {
            if(qb==1)   printf("+i");
            else printf("+%lldi",qb);
        }
    }
    else if(qb<0)
    {
        if(qb==-1)   printf("-i");
        else printf("%lldi",qb);
    }
    else if((qa==0)&&(qb==0))   printf("0");

}
// void con(long long n)
// {
//     char t[1000]={0};
//     while(n!=0)
//     {
//         t[strlen(t)]=n%2+'0';
//         n=n/2;
//     }
//     for(int i=strlen(t)-1;i>=0;i--) s[strlen(s)]=t[i];

// }
void con(long long n)
{
    char t[10000]={0};
    int i=0;
    while(n!=0)
    {
        t[i++]=n%2+'0';
        n=n/2;
    }
    t[i]=0;
    int j=0;
    for(int h=strlen(t)-1;h>=0;h--) s[j++]=t[h];


}
