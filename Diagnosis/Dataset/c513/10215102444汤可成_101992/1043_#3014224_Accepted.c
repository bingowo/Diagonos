#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char c, int j, char* aft, const char* bef)
{
    //²åÈë
    strcpy(aft, bef);
    for(int m = strlen(bef); m >= j; m--)
    {
        aft[m+1] = aft[m];
    }
    aft[j] = c;

    //Ïû³ý
    char* p = aft;
    char* q = aft+1;
    int flag = 2;
    while(strlen(p)>1)
    {
        if(*p != *q && flag != 1)
        {
            if(flag != 3) flag = 0;
            p++;
            q++;
        }
        else if(*p == *q)
        {
            q++;
            flag = 1;
        }
        else if(*p != *q && flag == 1)
        {
            if(*q == 0) *p = *q;
            else
            {
                int t = 0;
                while(q[t] != 0)
                {
                    p[t] = q[t];
                    t++;
                }
                p[t] = 0;
            }
            q = p+1;
            flag = 3;
        }
        if(*(p+1) == 0 || *p == 0)
        {
            if(flag == 0) break;
            flag = 2;
            p = aft;
            q = p+1;
        }
    }

}

int min(int a, int b, int c)
{
    int n = a>b?b:a;
    return n>c?c:n;
}


int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        char s[101] = {0};
        scanf("%s", s);
        int len = strlen(s);
        int mm = len;
        int del = 0;
        for(int j = 0; j<len; j++)
        {
            char a[101] = {0}, b[101] = {0}, c[101]= {0};
            insert('A', j, a, s);
            insert('B', j, b, s);
            insert('C', j, c, s);
            int m = min(strlen(a), strlen(b), strlen(c));
            del = del<mm-m+1 ? mm-m+1:del;
        }
        printf("case #%d:\n", i);
        printf("%d\n", del);
    }
    return 0;
}
