#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void*a,const void *b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;
    if(*p1<*p2)
    {
            return -1;
    }
    else return 1;

}

int main()
{
    int count,count1,len;
    scanf("%d",&count);
    getchar();
    count1=count;
    char S[201];

    while(count--)
    {
        char s[201];
        char *p1=S;
        char *p2=s;
        gets(S);
        while(*p1)
        {
            if(isalpha(*p1)&&*p1>='A'&&*p1<='Z')
            {
                *p2=*p1;
                p2++;
                p1++;
            }
            else
            {
                p1++;
            }
        }
        *p2='\0';
        p1=S;
        p2=s;
        len=strlen(S);
        qsort(p2,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        while(*p1)
        {
            if((p1-S)==len-1)
            {
                if(isalpha(*p1)&&*p1>='A'&&*p1<='Z')
            {
                printf("%c\n",*p2);
                p1++;
                p2++;
            }
            else
            {
                printf("%c\n",*p1);
                p1++;

            }
            }
            else if(isalpha(*p1)&&*p1>='A'&&*p1<='Z')
            {
                printf("%c",*p2);
                p1++;
                p2++;
            }
            else
            {
                printf("%c",*p1);
                p1++;

            }
        }
    }
}
