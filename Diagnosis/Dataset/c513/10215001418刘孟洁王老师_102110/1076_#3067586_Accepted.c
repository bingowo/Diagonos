#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//栈的使用

char a[108];
int i;

void pop(char c)
{
    a[i]=c;
    i++;
}//将这个字读入栈

void push()
{
    a[i-1]=0;
    i--;
}//吃掉这两个符号，因为配对了

int main()
{
    int n,j,l;
    char s[107];
    scanf("%d",&n);
    while(n)
    {
        scanf("%s",s);
        i=0;
        int flag=1;
        l=0;
        while(l<strlen(s))
        {
            if(i==0) pop(s[l]);
            else
            {
                switch(a[i-1])
                {
                    case '(':{if(s[l]=='{') pop(s[l]);else if(s[l]==')')push();else flag=0;}break;
                    case '[':{if(s[l]=='(') pop(s[l]);else if(s[l]==']')push();else flag=0;}break;
                    case '{':{if(s[l]=='[') pop(s[l]);else if(s[l]=='}')push();else flag=0;}break;
                    case ')':flag=1;break;
                    case ']':flag=1;break;
                    case '}':flag=1;break;
                }//只需要读入左边的符号，右边的一旦读入就是错误的括号序列
            }
            if(!flag)break;
            l++;
        }
        if(i==0) printf("Yes\n");
        else printf("No\n");
        for(j=0;j<strlen(a);j++)
            a[j]=0;
        n--;
    }
    return 0;
}

