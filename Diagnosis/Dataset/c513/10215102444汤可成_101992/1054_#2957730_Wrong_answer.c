#include <stdio.h>
#include <string.h>

struct word
{
    char w[36];
    int sp_num;
};

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    getchar();
    for(i =0; i<T; i++)
    {
        struct word word_list[70];
        char t[36] = {0};
        int m = 0;
        scanf("%d", &m);
        getchar();
        int word_num = 0;
        int line_len = 0;
        int len = 0;
        char ch = 0;
        printf("case #%d:\n", i);
        int flag = 0;
        while((ch = getchar()) == ' ') flag = 1;
        while(flag == 1 || (ch = getchar())!='\n')
        {
            flag = 0;
            len = 0;
            t[len] = ch;
            len++;
            while((ch = getchar())!=' ' && ch != '\n')
            {
                t[len] = ch;
                len++;
            }
            t[len] = 0;
            if(ch != '\n')
            {
                if(line_len+len<=m)
                {
                    for(int j = 0; j<len; j++)
                    {
                        word_list[word_num].w[j] = t[j];
                    }
                    word_list[word_num].w[len] = 0;
                    word_num++;
                    line_len += len + 1;
                    len = 0;
                }
                else
                {
                    int b = m;
                    for(int j = 0; j<word_num; j++)
                    {
                        b -= strlen(word_list[j].w);
                    }
                    int a = word_num-1;
                    for(int j = 0; j<word_num; j++)
                    {
                        if(j == word_num-1) word_list[j].sp_num = 0;
                        else
                        {
                            word_list[j].sp_num = b/a;
                            b = b - b/a;
                            a--;
                        }
                    }
                    for(int j = 0; j<word_num; j++)
                    {
                        printf("%s", word_list[j].w);
                        for(int p = 0; p<word_list[j].sp_num; p++)
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                    word_num = 0;
                    line_len = 0;
                    for(int j = 0; j<len; j++)
                    {
                        word_list[word_num].w[j] = t[j];
                    }
                    word_list[word_num].w[len] = 0;
                    word_num++;
                    line_len += len + 1;
                }
            }
            else
            {
                for(int j = 0;j < word_num; j++)
                {
                    printf("%s ", word_list[j].w);
                }
                printf("%s\n", t);
                break;
            }
        }
    }
    return 0;
}
