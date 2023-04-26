#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    int k=0;char s[100];
    while(x!=0||y!=0)
    {
        if(abs(x%2)==1&&abs(y%2)==0)
        {
            if(llabs(x+1)/2%2!=llabs(y/2)%2){x=(x+1)/2;y/=2;s[k++]='E';}
            else if(llabs(x-1)/2%2!=llabs(y/2)%2){x=(x-1)/2;y/=2;s[k++]='W';}
            else 
            {
                if(x==-1)s[k++]='E';
                else s[k++]='W';x/=2;
            }
        }
        else if(abs(y%2)==1&&abs(x%2)==0)
        {
            if(llabs(y+1)/2%2!=llabs(x/2)%2){y=(y+1)/2;x/=2;s[k++]='N';}
            else if(llabs(y-1)/2%2!=llabs(x/2)%2){y=(y-1)/2;x/=2;s[k++]='S';}
            else
            {
                if(y==-1)s[k++]='N';
                else s[k++]='S';x/=2;
            }
        }
        else break;
    }
    if(x==0&&y==0)printf("%d\n%s",k,s);
    else printf("-1");
}