#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long a=0,b=0,temp,qr,qi;
    int r,j,len,i=0;
    char ans[5000];
    char c;


    scanf("%lld",&temp);
    if(temp)
    {
        if((c=getchar())=='\n')
                a=temp;
            else
            {
                if (c=='+'||c=='-')
                {
                    a=temp;
                    b=((c=='-')?-1:1);
                    if(scanf("%lld",&temp)) 
                        b*=temp;
                }
                else
                    b=temp;
                    if(temp==0)
                        b=1;
            }
    }
    
    //printf("a=%lld\nb=%lld\n",a,b);


    do
    {
        if(((a-b)%2)==0)
            r=0;
        else 
            r=1;
        ans[i++]=r+'0';
        qr=(b+r-a)/2;
        qi=(r-a-b)/2;
        a=qr;
        b=qi;
    } while (!((qr==0)&&(qi==0)));

    len=strlen(ans);
    //printf("len of ans =%d\n",len);


    for(j=len-1;j>=0;--j)
    {
        printf("%c",ans[j]);
    }
    system("pause");
    return 0;
}