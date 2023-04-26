#include<stdio.h>
#include<string.h>
#include<malloc.h>

int judge(int x)
{
    char *s = (char*)malloc(sizeof(char)*11);
    int p = 0;
    while(x != 0)
    {
        s[p++] = x % 10 + '0';
        x /= 10;
    }
    int l = strlen(s);
    for(int i=0;i<l/2;i++)
        if(s[i] != s[l-1-i]) return 0;
    
    return 1;
}

int reverse(int x)
{
    int tmp = 0;
    while(x != 0)
    {
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return tmp;
}

int main()
{
    int n,m,i=0;scanf("%d",&n);
    while(1)
    {
        if(judge(n))
        {
            printf("%d %d",i,n);
            break;
        }
        else
        {
            i++;
            m = reverse(n);
            n += m;
        }
    }

    return 0;
}