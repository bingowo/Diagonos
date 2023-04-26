//第二种方法：递归的第一种思路
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
int cmp_out(const void*s1,const void*s2)
{
    return strcmp(*(char**)s1,*(char**)s2);
}
void comb(char*s,char*char_comb)
{
    if(*s)
    {
        char left[17] = {0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,char_comb);
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
        char t[] = "";
        printf("case #%d:\n",i);
        comb(s,t);

    }
    return 0;
}