#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len(int x[])
{
    int le=0;
    while(x[le]!=0)
    {
        le++;
    }
    return le;
}
void push(int x[],int y)
{
    int le=len(x);

    x[le]=y;
    x[le+1]=0;
}
int pop(int x[])
{
    int le=len(x);
    int y=x[le-1];
    x[le-1]=0;
    return y;
}
int main()
{
    char a[51];
    int le=0,b[51];
    memset(b,0,51);
    int x,y;

    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        le=0;
        if(a[i]=='(')
        {
            push(b,-1);
        }
        else if(a[i]==')')
        {
            x=pop(b);
            if(x==-1)
            {
                if(len(b)==0)
                {
                    push(b,1);
                }
                else
                {
                    if(b[len(b)-1]==-1)
                    {
                        push(b,1);
                    }
                    else
                    {
                        b[len(b)-1]++;
                    }
                }
            }
            else
            {
                x=x*2;
                y=pop(b);
                if(len(b)!=0)
                {
                    y=pop(b);
                    if(y!=-1)
                    {
                        x=x+y;
                    }
                }
                push(b,x);
            }
        }
    }
    printf("%d",b[0]);

    return 0;
}
