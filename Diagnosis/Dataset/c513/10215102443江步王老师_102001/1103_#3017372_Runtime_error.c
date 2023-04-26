#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* o[7]={"IN","MOV","ADD","SUB","MUL","DIV","OUT"};
char* r[4]={"AX","BX","CX","DX"};
int regi[4]={0};


void run(int order,char* s);

int main()
{
    char or[4];
    char s[6];
    int i;

    while (scanf("%s %s",or,s)==2)
    {
        int pos;
        for (i=0;i<sizeof(o)/sizeof(o[0]);++i)
        {
            if (strcmp(o[i],or)==0)
            {
                pos=i;break;
            }
        }

        run(pos,s);
    }
    return 0;
}

void run(int order,char* s)
{
    char* p=NULL;
    char* q=NULL;
    if (!order)//指令为“IN”
    {
        int i=0;
        while (s[i]!=',') i++;
        s[i]=0;
        p=s;q=s+i+1;

        int pos,num;
        for (i=0;i<4;++i)
        {
            if (strcmp(r[i],p)==0)
            {
                pos=i;break;
            }
        }
        num=atoi(q);
        regi[pos]=num;
    }
    else if (order==6)//out
    {
        int i;
        for (i=0;i<4;++i)
        {
            if (strcmp(s,r[i])==0)
            {
                break;
            }
        }
        printf("%d\n",regi[i]);
    }
    else
    {
        int i=0;
        while (s[i]!=',') i++;
        s[i]=0;
        p=s;q=s+i+1;

        int pos1,pos2;
        for (i=0;i<4;++i)
        {
            if (strcmp(r[i],p)==0)
            {
                pos1=i;break;
            }
        }
        for (i=0;i<4;++i)
        {
            if (strcmp(r[i],q)==0)
            {
                pos2=i;break;
            }
        }

        switch (order)
        {
            case 1://mov
                regi[pos1]=regi[pos2];break;
            case 2://add
                regi[pos1]+=regi[pos2];break;
            case 3://sub
                regi[pos1]-=regi[pos2];break;
            case 4://mul
                regi[pos1]*=regi[pos2];break;
            case 5://div
                regi[pos1]/=regi[pos2];break;

        }
    }
    return;
}
