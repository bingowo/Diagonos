#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[107];
int i = 0;

void pop(char c)
{
    a[i] = c;
    i++;
}

void push()
{
    a[i-1] = 0;
    i--;
}

int main()
{
    int n,j,l;
    char s[107];
    scanf("%d",&n);
    while(n)
    {
        scanf("%s",s);
        int flag = 1;
        l = 0;
        while(l < (int)strlen(s))
        {
            if(l == 0)pop(s[l]);
            else
            {
                switch(s[l-1])
                {
                    case '(':{if(s[l] == '{')pop(s[l]);else if(s[l] == ')')push();else flag = 0;}break;
                    case '[':{if(s[l] == '(')pop(s[l]);else if(s[l] == ']')push();else flag = 0;}break;
                    case '{':{if(s[l] == '[')pop(s[l]);else if(s[l] == '}')push();else flag = 0;}break;
                }
            }
            if(!flag)break;
            l++;
        }
        if((int)strlen(a) == 0)printf("Yes\n");
        else printf("No\n");
        for(j = 0; j < (int)strlen(a); j++)a[j] = 0;
        n--;
    }
    return 0;
}