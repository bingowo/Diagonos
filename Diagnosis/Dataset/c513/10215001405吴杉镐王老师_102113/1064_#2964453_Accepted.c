#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;
char s[10005];
double stk[10005];
int main()
{
    scanf("%d\n",&T);
    for(int c=0;c<T;c++)
    {
        gets(s);
        int top=0,l=strlen(s);
        for(int i=0;i<l;i++)
            if(s[i]==' ')
                s[i]=0;
        for(int i=l-1;i>=0;i--)
        {
            double res;
            if(s[i]=='+')
            {
                res=stk[top]+stk[top-1];
                stk[--top]=res;
            }
            else if(s[i]=='-')
            {
                res=stk[top]-stk[top-1];
                stk[--top]=res;
            }
            else if(s[i]=='*')
            {
                res=stk[top]*stk[top-1];
                stk[--top]=res;
            }
            else if(s[i]=='/')
            {
                res=stk[top]/stk[top-1];
                stk[--top]=res;
            }
            else if(s[i])
            {
                while(i>=0 && s[i])
                    i--;
                i++;
                stk[++top]=atof(s+i);
                //printf("%.6f\n",atof(s+i));
            }
        }
        
        printf("case #%d:\n%.6lf\n",c,stk[1]);
    }
    return 0;
}
