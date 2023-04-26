#include<stdio.h>
#include<string.h>
char stack[100];
int head=0;
int main()
{
    int T,n;
    char c;
    scanf("%d",&T);
    scanf("%c",&c);
    for(n=0;n<T;n++)
    {
        int tof=1;
        char k=0;
        scanf("%c",&c);
        while(c!='\n'&&tof==1)
        {
            if(c=='(')
            {
                if(head==0||k=='[')
                {
                    stack[head]=c;
                    head++;
                    k=c;
                }
                else tof=0;
            }
            else if(c=='[')
            {
                if(head==0||k=='{')
                {
                    stack[head]=c;
                    head++;
                    k=c;
                }
                else tof=0;
            }
            else if(c=='{')
            {
                if(head==0||k=='(')
                {
                    stack[head]=c;
                    head++;
                    k=c;
                }
                else tof=0;
            }
            else if(c==')')
            {
                if(head==0||stack[head-1]!='(')
                {
                    tof=0;
                }
                else
                {
                    head--;
                    if(head!=0)k=stack[head-1];
                }
            }
            else if(c==']')
            {
                if(head==0||stack[head-1]!='[')
                {
                    tof=0;
                }
                else
                {
                    head--;
                    if(head!=0)k=stack[head-1];
                }
            }
            else if(c=='}')
            {
                if(head==0||stack[head-1]!='{')
                {
                    tof=0;
                }
                else
                {
                    head--;
                    if(head!=0)k=stack[head-1];
                }
            }
            scanf("%c",&c);
        }
        while(c!='\n')
        {
            scanf("%c",&c);
        }
        if(tof==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}