#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int M,j,k,p; char s[2020]={0};
        scanf("%d",&M);
        getchar();
        gets(s);
        int str_len=strlen(s);
        int words_len,words_count,space;
        for (j=0;s[j]==' ';j++);
        while (j<str_len)
        {
            int start=j;
            words_len=0,words_count=0;
            for (;words_len+words_count<=M && j<str_len;)
            {
                for (k=0,p=j;s[p]!=' ' && p<str_len;p++,k++)
                    if (words_len+words_count+k<=M)
                    {
                        words_len+=k; words_count++;
                        for (j=p;s[j]==' ';j++);
                    }
                    else break;
            }
            int space=M-words_len;
            int m=start; words_count--;
            while (m<j)
            {
                while (s[m]!=' ' && m<str_len) putchar(s[m++]);
                while (s[m]==' ' && m<str_len) m++;
                if (j==str_len && words_count)
                    putchar(' ');
                else
                {
                    for (p=0;words_count && p<space/words_count;p++)
                        putchar(' ');
                    space-=p;
                }
                words_count--;
            }putchar("\n");
        }


    }
    return 0;
}
