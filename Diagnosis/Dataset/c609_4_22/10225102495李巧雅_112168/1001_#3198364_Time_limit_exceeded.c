#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T,N,R,a,b,i,j,n;
    char s[100];
    scanf("%d\n",&T);
    for(a=0;a<=T;a++)
    {
        scanf("%d %d\n",&N,&R);
    }
    while(N)
    {
        b=0;
        if(N%R>9)
        {
            s[b++]=((N%R+1)%10+64)+'0';
        }
        else
            s[b++]=N%R+'0';
        N/=R;
    }
    int t;
    for(i=0,j=b,n=0;n<=(i+j)/2;i++,j--)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    return s;
}
