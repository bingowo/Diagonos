#include <stdio.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i = 0; i < T; i++)
    {
        char *str = (char*)malloc(sizeof(char)*205);
        int tb[260] = {0};//字母表
        char ch;
        int cnt = 0;
        while((ch=getchar())!='\n')
        {
            tb[ch]++;
            str[cnt++] = ch;
        }
        printf("case #%d:\n",i);
        for(int j = 0; j < cnt; j++)
        {
            if(isalpha(str[j]))//isalpha判断字符是否为英文字母
            {
                for(char k = 'A'; k <= 'Z'; k++)
                {
                    if(tb[k])
                    {
                        printf("%c",k);
                        tb[k]--;
                        break;
                    }
                }
            }
            else
            {
                printf("%c",str[j]);
            }
        }
        printf("\n");
        free(str);
    }
    return 0;
}