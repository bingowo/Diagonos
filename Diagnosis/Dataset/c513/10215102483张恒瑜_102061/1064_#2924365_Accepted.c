#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double stack[100]={0};
int idx=-1;

double pop()
{
    double tmp=stack[idx];
    stack[idx]=0;
    idx--;
    return tmp;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int t=0;t<T;t++)
    {
        char polan[110][110]={{'\0'}};
        int len=0;
        double res=0;
        char c=0;
        while(c!='\n')
        {
            scanf("%s",polan[len++]);
            c=getchar();
        }
        for(int i=len-1;i>=0;i--)
        {
            if(polan[i][0]=='+')
            {
                res=pop()+pop();
                stack[++idx]=res;
            }
            else if(polan[i][0]=='-')
            {
                res=pop()-pop();
                stack[++idx]=res;
            }
            else if(polan[i][0]=='*')
            {
                res=pop()*pop();
                stack[++idx]=res;
            }
            else if(polan[i][0]=='/')
            {
                res=pop()/pop();
                stack[++idx]=res;
            }
            else
            {
                stack[++idx]=atof(polan[i]);
            }
        }
        printf("case #%d:\n%lf\n",t,stack[0]);
        idx--;
    }
}