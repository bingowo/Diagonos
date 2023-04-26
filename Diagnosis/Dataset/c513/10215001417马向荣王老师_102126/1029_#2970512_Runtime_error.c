#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        char str[201];
        int tb[260]={0};
        char ch;
        int s=0;
        while((ch=getchar())!='\n')
        {
            tb[ch]++;
            str[s++]=ch;
        }
        printf("case #%d:\n",i);
        for(int j=0;j<s;j++)
        {
            if(isalpha(str[j]))
            {
                for(char k='A';k<='Z';k++)
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
                printf("%s ",str[j]);
            }
        }
        printf("\n");
        free(str);
    }
    return 0;
}