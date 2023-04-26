#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strlwr(char *s)
{
    char *str;
    str = s;
    while(*str != '\0'){
        if(*str >= 'A' && *str <= 'Z')
            *str += 'a'-'A';
        str++;
    }
    return s;
}

int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        char str[110][110]={'\0'};
        int m=0,n=0,cnt=1;
        while(1)
        {
            char ch=getchar();
            if(ch=='\n'){m++;break;}//end input
            if(ch==' ')
            {
                cnt++;
                str[m][n]='\0';//end of the word
                m++;n=0;//jump to next word(line)
            }
            else str[m][n++]=ch;
        }
        for(int j=0;j<m;j++)//m==numbers of words
        {
            strlwr(str[j]);
            int len=strlen(str[j]);//printf("%s\n",str[j]);//length of each word
            int judge=(!strcmp("the",str[j]))||(!strcmp("a",str[j]))||
                       (!strcmp("an",str[j]))||(!strcmp("of",str[j]))||
                       (!strcmp("for",str[j]))||(!strcmp("and",str[j]));
            if(judge==1) cnt--;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);

    }
    return 0;
}