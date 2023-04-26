#include <stdio.h>
#include <stdlib.h>

char stack[1000];
int m = 0;

void push(int n)
{
    stack[m++] = n;
}

char pop()
{
    return stack[--m];
}

main()
{
    int n;
    scanf("%d",&n);
    char s[1000] = {};
    int p = 0;
    int a, b, mid;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if (a<0)
        {
            a = -a;
            s[p++] = '-';
        }
        do
        {
            mid = a%b;
            if (mid>=0 && mid<=9) push(mid+'0');
            else push('A'+mid-10);
            a /= b;
        } while (a>0);
        while (m>0) s[p++] = pop();
        for (int j=0;s[j];j++) printf("%c",s[j]);
        printf("\n");
        for (int j=0;s[j];j++) s[j] = 0;
        p = 0;
    }
    system("pause");
    return 0;
}