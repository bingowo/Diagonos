#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    char op;
    double num;
    int which;//判断是操作数还是操作符，如果是操作数则为1
};

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        struct Stack s[100],s1[100];
        int top,j;
        top=-1;
        char c[100];
        while(scanf("%s",c)!=EOF)
        {
            if(strlen(c)==1&&!isdigit(c[0]))
            {
                s[top++].op=c[0];
                s[top].which=0;
            }
            else
            {
                if(!isdigit(c[0]))
                {
                    double total=0;
                    for(j=1;c[j]&&c[j]!='.';j++)
                    {
                        total=total*10+c[j]-'0';
                        if(c[j]=='.')
                        {
                            int k=j;
                            for(j=j+1;c[j];j++)
                                total=total+(c[j]-'0')*pow(0.1,j-k);
                        }
                    }
                    total=(-1)*total;
                    s[top++].num=total;
                    s[top].which=1;
                }
                else
                {
                    double total=0;
                    for(j=0;c[j]&&c[j]!='.';j++)
                    {
                        total=total*10+c[j]-'0';
                        if(c[j]=='.')
                        {
                            int k=j;
                            for(j=j+1;c[j];j++)
                                total=total+(c[j]-'0')*pow(0.1,j-k);
                        }
                    }
                    s[top++].num=total;
                    s[top].which=1;
                }
        }}
        int top1=0;
        while(top--)
        {
            if(s[top].which==1)
                s1[top1++].num=s[top].num;
            if(s[top].which==0)
            {
                double a=s1[top1--].num;
                double b=s1[top1--].num;
                char c1=s[top].op;
                switch(c1)
                {
                    case '+':s1[++top1].num=a+b;break;
                    case '-':s1[++top1].num=a-b;break;
                    case '*':s1[++top1].num=a*b;break;
                    case '/':s1[++top1].num=a/b;break;
                }
            }
        }
        printf("case #%d:\n%.6lf\n",i,s1[top1].num);
    }
}