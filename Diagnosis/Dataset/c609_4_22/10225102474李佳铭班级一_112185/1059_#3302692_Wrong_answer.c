#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int sign(char*s)
{
    int i = 1;
    if(s[0] == '-')
        i = -1;
    return i;
}

int count(char* s)
{
    int i = 0;
    int sum;
    if(s[0] == '-' || s[0] == '+')
    {
        i++;
    }
    while(s[i++] != '.')
        sum++;
    return sum;
}



int cmp(const void*a,const void*b)
{
    char* A = *(char(*)[101])a;
    char* B = *(char(*)[101])b;
    if(sign(A) != sign(B))
    {
        return sign(A) > sign(B);
    }
    else
    {
        if(count(A) != count(B))
        {
            return sign(A) > 0 ? count(A) > count(B) : count(A) < count(B);
        }
        else
        {
            if(A[0] == '+'|| A[0] == '-')
            {
                A += 1;
            }
            if(B[0] == '+'|| B[0] == '-')
            {
                B += 1;
            }
            return sign(A) > 0 ? strcmp(B,A) : strcmp(A,B);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[101][101];
    for(int i = 0; i < T;i++)
    {
        scanf("%s",s[i]);
    }
    qsort(s,T,sizeof(s[0]),cmp);

    for(int i = 0; i < T;i++)
    {
        printf("%s\n",s[i]);
    }

    return 0;
}
