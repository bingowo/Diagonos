#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*s1,const void*s2)
{
    if(*(char*)s1 + 32 == *(char*)s2)
        return -1;
    else if(*(char*)s1 == *(char*)s2 + 32)
        return 1;
    else
        return *(char*)s1 - *(char*)s2;
    
}
char t[17] = "";
void comb(char*s,int depth,int k)
{
    if(depth)
        printf("%s\n",t);
    for(int i = k;s[i];i++)
    {
        t[depth] = s[i];
        t[depth + 1] = '\0';
        comb(s,depth+1,k+1);
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        int count = 0;
        char ch;
        char s[17];
        int table[256];
        memset(table,1,sizeof(int)*256);
        while((ch = getchar()) != '\n')
        {
            if(table[ch])
            {
                table[ch] = 0;
                s[count++] = ch;
            }
        }
        s[count] = '\0';
        qsort(s,strlen(s),sizeof(char),cmp);
        printf("case #%d:\n",i);
        comb(s,0,0);
    }
}