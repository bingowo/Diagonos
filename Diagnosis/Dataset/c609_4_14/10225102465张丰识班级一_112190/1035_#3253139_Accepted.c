#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *delete(char *s)
{
    unsigned len = strlen(s);
    for(int i = 0;i < len-1;i++)
    {
        if(s[i] == s[i+1])
        {
            int j;
            char c = s[i];
            for(j = i;j < len;j++)
            {
                if(s[j] == c)
                {
                    s[j] = '0';
                }
                else
                {
                    break;
                }
            }
            i = j-1;
        }
        else
            continue;
    }
    char *r = (char*) malloc(len*sizeof(char));
    int cnt = 0;
    for(int i = 0;i < len;i++)
    {
        if(s[i] != '0')
            r[cnt++] = s[i];
    }
    r[cnt] = '\0';
    if(r[0] != '\0')
        return r;
    else
        return NULL;
}

char *insert(char *s,int n,char c)
{
    unsigned len = strlen(s);
    char *r = (char*)malloc((len+5)*sizeof(char));
    for(int i = 0;i < n;i++)
    {
        r[i] = s[i];
    }
    r[n] = c;
    for(int i = n+1;i < len+1;i++)
    {
        r[i] = s[i-1];
    }
    r[len+1] = '\0';
    return r;
}

unsigned count(char *s)
{
    if(s == NULL)
        return 0;
    int find = 0;
    int sig = 1;
    for(int i = 0;i < strlen(s)-1;i++)
    {
        if(s[i] == s[i+1])
        {
            sig = 0;    
            break;
        }
    }
    if(sig)
        return strlen(s);
    else
    {
        return count(delete(s));
    }
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        char s[101] = {0};
        scanf("%s",s);
        unsigned len = strlen(s)+1;
        unsigned min = len+1;
        for(int j = 0;j <= strlen(s);j++)
        {
            for(char p = 'A';p <= 'C';p++)
            {
                char *res = insert(s,j,p);
                unsigned ru = count(res);
                min = ru < min ? ru : min;
            }
        }
        printf("%u\n",len-min);
    }
    return 0;
}