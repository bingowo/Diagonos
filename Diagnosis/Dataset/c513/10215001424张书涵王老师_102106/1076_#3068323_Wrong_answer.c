#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,question_num;
    scanf("%d ",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int i,p=0;;
        char s1[1000]={0};
        char s2[1000]={0};//作为堆栈来存储左括号
        gets(s1);
        for(i=0;s1[i];i++)
        {
            if(s1[i]=='{')
            {
                if(p>=1&&s2[p-1]!='(')
                {
                    printf("No\n");
                    break;
                }
                s2[p++]=s1[i];
            }
            if(s1[i]=='[')
            {
                if(p>=1&&s2[p-1]!='{')
                {
                    printf("No\n");
                    break;
                }
                s2[p++]=s1[i];
            }
            if(s1[i]=='(')
            {
                if(p>=1&&s2[p-1]!='[')
                {
                    printf("No\n");
                    break;
                }
                s2[p++]=s1[i];
            }
            if(s1[i]==')')
            {
                if(s2[p]!='(')
                {
                    printf("No\n");
                    break;
                }
                s2[p--]=0;
            }
            if(s1[i]==']')
            {
                if(s2[p]!='[')
                {
                    printf("No\n");
                    break;
                }
                s2[p--]=0;
            }
            if(s1[i]=='}')
            {
                if(s2[p]!='{')
                {
                    printf("No\n");
                    break;
                }
                s2[p--]=0;
            }
        }
        if(p==0)
            printf("Yes\n");
    }
}