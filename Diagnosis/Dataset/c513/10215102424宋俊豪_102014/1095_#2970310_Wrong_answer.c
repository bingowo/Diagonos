#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define C 2000
void add(int a[],int b[])
{
    int i,t,carry=0;
    for(i=C-1; i>=0; i--)
    {
        t=a[i]+b[i]+carry;
        a[i]=t%10;
        carry=t/10;
    }
}
void time(int a[],int b[])
{
    int i,t;
    for(i=C-1; i>=0; i--)
    {
        t=a[i]-b[i];
        if(t<0)
        {
            a[i-1]--;
            a[i]=t+10;
        }
        else
            a[i]=t;
    }
}
int check(int a[],int b[])
{
    int i=0;
    while(a[i]==b[i])
        i++;
    if(a[i]>b[i])
        return 1;
    else
        return 0;
}
int main()
{
    char s[100];
    int q[405]= {0},a[C]= {0},b[C]= {0};
    int j,t,i=2,id=0,fa=1,fb=1;
    scanf("%s",s);
    while(s[i])
    {
        if(s[i]>=0&&s[i]<='9')
        {
            t=s[i]-'0';
            id+=4;
            for(j=id-1; j>=id-4; j--)
            {
                q[j]=t%2;
                t=t/2;
            }

        }
        else
        {
            t=s[i]-'A'+10;
            id+=4;
            for(j=id-1; j>=id-4; j--)
            {
                q[j]=t%2;
                t=t/2;
            }

        }
        i++;
    }
    for(j=0; j<id; j++)
        if (q[j]==1)
            break;
    a[C-1]=1;
    for(j=j+1; j<id; j++)
    {
        int c[C]= {0},d[C]= {0},e[C]= {0},f[C]={0},ff,fe,fc,fd;
        fc=-fa;
        fd=-fb;
        fe=-fb;
        ff=fa;
        memcpy(c,a,4*C);
        memcpy(d,b,4*C);
        memcpy(e,b,4*C);
        memcpy(f,a,4*C);
        if(fc*fd>0)
        {
            add(c,d);
            memcpy(a,c,4*C);
            fa=fc;
        }
        else
        {
            if(check(c,d)==1)
            {
                time(c,d);
                memcpy(a,c,4*C);
                fa=fc;
            }
            else
            {
                time(d,c);
                memcpy(a,d,4*C);
                fa=fd;
            }
        }
        if(ff*fe>0)
        {
            add(e,f);
            memcpy(b,e,4*C);
            fb=fe;
        }
        else
        {
            if(check(e,f)==1)
            {
                time(e,f);
                memcpy(b,e,4*C);
                fb=fe;
            }
            else
            {
                time(f,e);
                memcpy(b,f,4*C);
                fb=ff;
            }
        }
        if(q[j]==1&&fa==1)
        {
            t=0;
            a[C-1]++;
            while (a[C-1-t]>=10)
            {
                a[C-2-t]++;
                a[C-1-t]=a[C-1-t]%10;
                t++;
            }
        }
        else if(q[j]==1&&fa==-1)
        {
            t=0;
            a[C-1]--;
            while (a[C-1-t]<0)
            {
                a[C-2-t]--;
                a[C-1-t]=a[C-1-t]+10;
                t++;
            }
        }
    }
        int qq=0,f1=0;
        for(int i=0; i<C; i++)
        {
            if(a[i]==0&&f1==0)
                continue;
            else
                f1++;
            if(f1==1&&fa==-1)
                printf("-");
            printf("%d",a[i]);
            qq=1;
        }
        f1=0;
        for(int i=0; i<C; i++)
        {
            if(b[i]==0&&f1==0)
                continue;
            else
                f1++;
            if(f1==1&&fb==-1)
                printf("-");
            else if(f1==1&&fb==1&&qq==1)
                printf("+");
            if(f1==1&&i==C-1&&b[i]==1)
                ;
            else
                printf("%d",b[i]);
            if(i==C-1)
                printf("i");
        }
        printf("\n");

    return 0;
}

