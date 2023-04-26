#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i =0;i<T;i++)
    {
        int count = 0;
        char s[100]={'\0'};
        char word[100] = {'\0'};
        char*check[] = {"the","a","an","of","for","and",};
        int flag = 0;
        gets(s);
        char*p = s;
        char*p_end = p;

        while(*p!= 0)
        {
            do{
                p_end++;
            }
            while(*p_end != ' '&&*p_end != '\0');
            int word_count = 0;
            for(char*i = p;i<p_end;i++)
            {
                word[word_count] = (char)tolower(*i);
                word_count++;
            }

            for(int i = 0;i<6;i++)
            {
                if(strcmp(check[i],word)==0)
                {
                    flag = 1;
                }
                else{continue;}
            }

            if(flag == 0)
            {
                count++;
            }
            else{flag = 0;}
            for(int i =0;i<100;i++)
            {
                word[i] = '\0';
            }
            p = p_end+1;

        }
        printf("case #%d:\n%d\n",i,count);
    }
    return 0;
}
