#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char s1[81];
    char s2[81];
    char S[81];
    while(count--)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",S);
        char *p1=s1;
        char *p2=s2;
        char *p3=S;
        char *flag1=0;
        char *flag2=0;
        while(*p3)
        {
            if(*p3==*p1)
            {
                while(*p3==*p1&&*p1&&*p3)
                {
                    if(p1-s1==strlen(s1)-1)
                    {
                        flag1=p3;
                    }
                    p3++;
                    p1++;

                }
                p1=s1;
            }
            else p3++;
            if(flag1!=0)
            {
                break;
            }
        }


        p3=S+strlen(S)-1;
        p2=s2+strlen(s2)-1;
        while(*p3)
        {
            if(*p3==*p2)
            {
                while(*p3==*p2&&p2-s2>=0&&p3-S>=0)
                {
                    if(p2-s2==0)
                    {
                        flag2=p3;
                    }
                    p3--;
                    p2--;

                }
                p2=s2+strlen(s2)-1;
            }
            else p3--;
            if(flag2!=0)
            {
                break;
            }
        }
    printf("case #%d:\n",count1-count-1);
    if(flag1==0||flag2==0)
    {
        printf("0\n");
    }
    else if(flag2-flag1-1<0)
    {


        p1=s2;
        p2=s1;
        p3=S;
        flag1=0;
        flag2=0;
        while(*p3)
        {
            if(*p3==*p1)
            {
                while(*p3==*p1&&*p1&&*p3)
                {
                    if(p1-s2==strlen(s2)-1)
                    {
                        flag1=p3;
                    }
                    p3++;
                    p1++;

                }
                p1=s2;
            }
            else p3++;
            if(flag1!=0)
            {
                break;
            }
        }


        p3=S+strlen(S)-1;
        p2=s1+strlen(s1)-1;
        while(*p3)
        {
            if(*p3==*p2)
            {
                while(*p3==*p2&&p2-s1>=0&&p3-S>=0)
                {
                    if(p2-s1==0)
                    {
                        flag2=p3;
                    }
                    p3--;
                    p2--;

                }
                p2=s1+strlen(s1)-1;
            }
            else p3--;
            if(flag2!=0)
            {
                break;
            }
        }
        if(flag1==0||flag2==0)
    {
        printf("0\n");
    }
    else if(flag2-flag1-1<0)
    {
        printf("0\n");
    }
    else
        printf("%d\n",flag2-flag1-1);

    }
    else
        printf("%d\n",flag2-flag1-1);
    }
}
