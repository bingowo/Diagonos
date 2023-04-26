#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int xi;
    int mi;
}yixiang;

int numof(int st,int en,char *s)
{
    int i,j,len=strlen(s);
    int re=0;
    if(st>en) return 1;
    for(i=st;i<=en;i++)
    {
        if(s[i]=='x') return 0;
        re*=10;
        re+=s[i]-'0';
    }
    /*for(i=st;i<=en;i++)
    {
        printf("s[%d]=%c  ",i,s[i]);
    }
    printf("\n");*/
    return re;
}

int xishu(char *s,yixiang *c)
{
    int len=strlen(s);
    int i,k=0,j;
    for(i=5;i<len;i++)
    {
        if(s[i]=='x')
        {
            if(s[i+1]=='^')
            {
                c[k].mi=s[i+2]-'0';
                for(j=i-1;j>=5;j--)
                {
                    if(s[j]=='+') {c[k].xi=numof(j+1,i-1,s);break;}
                    else if(s[j]=='-') {c[k].xi=-numof(j+1,i-1,s);break;}
                }
                if(j==4) c[k].xi=numof(5,i-1,s);
                k++;
            }
            else
            {
                c[k].mi=1;
                for(j=i-1;j>=5;j--)
                {
                    if(s[j]=='+') {c[k].xi=numof(j+1,i-1,s);break;}
                    else if(s[j]=='-') {c[k].xi=-numof(j+1,i-1,s);break;}
                }
                if(j==4) c[k].xi=numof(5,i-1,s);
                k++;
            }
        }

        if(i==len-1)
        {
            c[k].mi=0;
            for(j=i;j>=5;j--)
            {
                if(s[j]=='+') {c[k].xi=numof(j+1,i,s);break;}
                else if(s[j]=='-') {c[k].xi=-numof(j+1,i,s);break;}
            }
            if(j==4) c[k].xi=numof(5,i,s);
            if(c[k].xi!=0) k++;
        }
    }
    if(k==0) k++;
    return k;
}

void miaodian(yixiang *c,char re[][50],int co)
{
    int x=-20,y;
    int i,j;
    while(x<=20)
    {
        y=0;
        for(i=0;i<co;i++)
        {
            y+=c[i].xi*pow(x,c[i].mi);
        }
        //printf("(%d,%d)\n",x,y);
        if((y<=20)&&(y>=-20)) re[20-y][x+20]='*';
        x++;
    }
}

int main()
{
    int flag=0;
    while(1)
    {
        char s[50];
        if(scanf("%s",s)==EOF) break;
        yixiang c[5];
        memset(c,0,sizeof(yixiang)*5);
        int co;
        co=xishu(s,c);
        int i,j;
        /*for(i=0;i<co;i++)
        {
            printf("%d x^ %d (c[%d])\n",c[i].xi,c[i].mi,i);
        }*/
        char re[50][50];
        for(i=0;i<41;i++)
        {
            for(j=0;j<41;j++)
            {
                re[i][j]='.';
            }
            re[i][j]=0;
        }
        re[0][20]='^';
        for(i=1;i<41;i++)
        {
            re[i][20]='|';
        }
        for(j=0;j<41;j++)
        {
            re[20][j]='-';
        }
        re[20][40]='>';
        re[20][20]='+';

        miaodian(c,re,co);
        //if(flag) printf("\n");
        for(i=0;i<41;i++)
        {
            for(j=0;j<41;j++)
            {
                printf("%c",re[i][j]);
            }
            printf("\n");
        }
        flag=1;

    }
    return 0;
}
