#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[107];
int i;

void pop(char c)
{
    a[i] = c;
    i++;
}//将这个字符读入栈

void push()
{
    a[i-1] = 0;
    i--;
}//吃掉（去掉）这两个符号，因为配对了；

int main()
{
    int n,j,l;
    char s[107];
    scanf("%d",&n);
    while(n)
    {
        scanf("%s",s);
        i = 0;
        int flag = 1;
        l = 0;
        while(l < (int)strlen(s))
        {
            if(i == 0)pop(s[l]);
            else
            {
                switch(a[i-1])
                {
                    case '(':{if(s[l] == '{')pop(s[l]);else if(s[l] == ')')push();else flag = 0;}break;
                    case '[':{if(s[l] == '(')pop(s[l]);else if(s[l] == ']')push();else flag = 0;}break;
                    case '{':{if(s[l] == '[')pop(s[l]);else if(s[l] == '}')push();else flag = 0;}break;
                    case ')':flag = 0;break;
                    case ']':flag = 0;break;
                    case '}':flag = 0;break;
                }//只需要读入左边的符号，右边的一旦读入就是错误的括号序列
            }
            if(!flag)break;
            l++;
        }
        if(i == 0)printf("Yes\n");//只能用i判断，判断栈是否为空；
        else printf("No\n");
        for(j = 0; j < (int)strlen(a); j++)a[j] = 0;
        n--;
    }
    return 0;
}
