#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{   char s[2005];
    int n;
    scanf("%d\n",&n);
    for(int z=0;z<n;z++)
    {
        int len;
        scanf("%d\n",&len);
        gets(s);
        int llen=strlen(s);
        printf("case #%d:\n",z);
        int i=0;
        while(i<llen)
        {
            for(;s[i]==' ';i++);
                int line=i;
            int word_len=0;
            int word_num=0;
            for(;word_len+word_num<=len&&i<llen;)
            {
                int j=0,k=i;
                while(s[k]!=' '&&k<llen)
                {
                    j++;k++;
                }
                if(j+word_len+word_num<=len)
                {
                    word_len+=j;
                    word_num++;
                    for(i=k;s[i]==' ';i++);

                }
                else
                    break;
            }
            int emp=len-word_len;
            word_num--;
            while(line<i)
            {
                while(s[line]!=' '&&line<llen)
                    printf("%c",s[line++]);
                while(s[line]==' '&&line<llen)
                    line++;
                if(i==llen&&word_num)
                    printf(" ");
                else
                {
                    int j=0;
                    for(;word_num&&j<emp/word_num;j++)
                    {
                        printf(" ");

                    }
                    emp-=j;
                }
                word_num--;
            }
            printf("\n");
        }
    }
    return 0;
}
