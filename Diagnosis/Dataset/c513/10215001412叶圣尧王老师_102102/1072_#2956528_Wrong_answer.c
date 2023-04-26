#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    int k=0,flag=0;char s[100];
    while(x!=0||y!=0)
    {
        if(abs(x%2)==1&&abs(y%2)==0)
        {

            if(abs(x)==1&&y==0)
            {
                if(x==-1)s[k++]='W';
                else s[k++]='E';
                x=0;
                flag=1;
            }
            else if(llabs(x+1)/2%2!=llabs(y/2)%2){x=(x+1)/2;y/=2;s[k++]='W';}
            else if(llabs(x-1)/2%2!=llabs(y/2)%2){x=(x-1)/2;y/=2;s[k++]='E';}
        }
        else if(abs(y%2)==1&&abs(x%2)==0)
        {
            if(abs(y)==1&&x==0)
            {
                if(y==-1)s[k++]='S';
                else s[k++]='N';
                y=0;
                flag=1;
            }
            else if(llabs(y+1)/2%2!=llabs(x/2)%2){y=(y+1)/2;x/=2;s[k++]='S';}
            else if(llabs(y-1)/2%2!=llabs(x/2)%2){y=(y-1)/2;x/=2;s[k++]='N';}
        }
        else {flag=-1;break;}
    }
    if(flag==1)
        printf("%d\n%s",k,s);
    else if(flag==0)printf("0");
    else printf("-1");
}
