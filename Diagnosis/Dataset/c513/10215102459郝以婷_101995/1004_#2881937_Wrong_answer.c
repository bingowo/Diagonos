#include <stdio.h>
#include <string.h>

int main()
{
    int a1,a0,b[32],c[32],i,j,b1[64],c1[64],t;
    double a2;
    char d[11],d1[23];
    for(i=0;i<32;i++)
        b[i]=0;
    for(i=0;i<64;i++)
        b1[i]=0;
    while(scanf("%lf",&a2)==1)
    {
        if(a2-(int)a2==0)
        {
            a1=(int)a2;
            if(a1<0)
                a0=-a1;
            else
                a0=a1;
            i=31;
            while(a0!=0)
            {
                t=a0%2;
                a0=a0/2;
                b[i]=t;
                i--;
            }
            if(a1<0)
            {
                for(j=0;j<32;j++)
                {
                    if(b[j]==1)
                        b[j]=0;
                    else
                        b[j]=1;
                }
                if(b[31]==1)
                {
                    for(j=31;j>=0;j--)
                    {
                        if(b[j-1]==0)
                        {
                            b[j]=0;b[j-1]=1;break;
                        }
                        else
                            b[j]=0;
                    }
                }
                else
                    b[31]=1;
            }
            j=24;
            for(i=0;i<32;i++)
            {
                c[i]=b[j];
                if(j==31)
                    j=16;
                else if(j==23)
                    j=8;
                else if(j==15)
                    j=0;
                else j++;
            }
            t=c[0]*2+c[1];
            for(i=2,j=0;i<32;i++)
            {
                t=2*t+c[i];
                if((i+1)%4==0)
                {
                    printf("%d\n",t);
                    if(t>9)
                        d[j]=t-10+'a';
                    else
                        d[j]=48+t;
                    j++;
                    if((j+1)%3==0&&j!=11)
                    {
                        d[j]=' ';
                        j++;
                    }
                    t=c[i+1]*2+c[i+2];
                    i=i+2;
                }
            }
            printf("%s",d);
        }
    }
    return 0;
}
