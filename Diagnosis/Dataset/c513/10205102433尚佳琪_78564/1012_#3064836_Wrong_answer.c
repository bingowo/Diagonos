#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[100];
    int t[1000]={0},k=0;
    scanf("%s",s);
    int len=strlen(s);
    long long a=0,b=0,qr=0,qi=0;
    int r=0;

    long long tmp=0;
    int i,flag=0,flag2=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='+'||s[i]=='-')
        {
            if(i==0)
            {
                flag=1;
                i++;
            }
            else if(i!=0) break;
        }
        tmp=tmp*10+s[i]-'0';
    }
    if(flag==1)
        tmp=-tmp;
    qr=tmp;
    tmp=0;
    if(i==len)
        qi=0;
    else if(i==len-2)
    {
        if(s[i]=='+')
            qi=1;
        else if(s[i]=='-')
            qi=-1;
    }
    else
    {   if(s[i]=='-')
            flag2=1;
        tmp=0;
        for(int j=i+1;j<len-1;j++)
        {
           tmp=tmp*10+s[j]-'0';
        }
        if(flag2==1)
            tmp=-tmp;
        qi=tmp;
    }
   // printf("%lld %lld",qr,qi);
    while(qr!=0||qi!=0)
    {
        if((abs(qr)%2)!=(abs(qi)%2))
            r=1;
        else
            r=0;
       // printf("%lld %lld ",qr%2,qi%2);
        //printf("%d\n",r);
        t[k++]=r;
        a=(qi-qr+r)/2;
        b=-(qi+qr-r)/2;
        qr=a;
        qi=b;
    }
    for(int i=k-1;i>=0;i--)
        printf("%d",t[i]);

    return 0;
}
