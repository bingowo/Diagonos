#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a1,a0,b[32],c[32],i,j,b1[53],b2[11],c1[64],e[64],t,count,count1,t1,ifd;
    double a3,t2,a2;
    char d[11],d1[23],in[20];
    while(scanf("%s",in)==1)
    {
        ifd=0;
        for(i=0;i<strlen(in)/sizeof(char);i++)
        {
            if(in[i]=='.')
                {ifd=1;
                break;}
        }
        a2=atof(in);
        for(i=0;i<32;i++)
            b[i]=0;
        for(i=0;i<52;i++)
            b1[i]=0;
        for(i=0;i<11;i++)
            b2[i]=0;
        if(ifd==0)
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
            for(i=2,j=0;i<32&&j<11;i++)
            {
                t=2*t+c[i];
                if((i+1)%4==0)
                {
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
            printf("%s\n",d);
        }
        else
        {
            if(a2<0)
                a3=-a2;
            else
                a3=a2;
            i=52;
            t=(int)a3;
            while(t!=0)
            {
                t1=t%2;
                t=t/2;
                b1[i]=t1;
                i--;
            }
            count=52-i;
            if(t==0)
                count=1;
            t2=a3-(int)a3;
            i=0;
            while((t2!=0)&&(i<53-count))
            {
                t1=(int)(t2*2);
                t2=t2*2-(int)(t2*2);
                b1[i]=t1;
                i++;
            }
            count1=count-1+1023;
            if(a3-0.0==0)
                count1=0;
            i=10;
            while(count1!=0)
            {
                t1=count1%2;
                count1=count1/2;
                b2[i]=t1;
                i--;
            }
            if(a2>=0)
                c1[0]=0;
            else c1[0]=1;
            j=0;
            for(i=1;i<12;i++)
            {
                c1[i]=b2[j];
                j++;
            }
            for(j=53-count+1;j<53;j++)
            {
                c1[i]=b1[j];
                i++;
            }
            for(j=0;i<=63;i++)
            {
                c1[i]=b1[j];
                j++;
            }
            j=56;
            for(i=0;i<64;i++)
            {
                e[i]=c1[j];
                if(j==31)
                    j=16;
                else if(j==23)
                    j=8;
                else if(j==15)
                    j=0;
                else if(j==39)
                    j=24;
                else if(j==47)
                    j=32;
                else if(j==55)
                    j=40;
                else if(j==63)
                    j=48;
                else j++;
            }
            t=e[0]*2+e[1];
            for(i=2,j=0;i<64;i++)
            {
                t=2*t+e[i];
                if((i+1)%4==0)
                {
                    if(t>9)
                        d1[j]=t-10+'a';
                    else
                        d1[j]=48+t;
                    j++;
                    if((j+1)%3==0&&j!=23)
                    {
                        d1[j]=' ';
                        j++;
                    }
                    t=e[i+1]*2+e[i+2];
                    i=i+2;
                }
            }
            printf("%s\n",d1);
        }
    }
    return 0;
}
