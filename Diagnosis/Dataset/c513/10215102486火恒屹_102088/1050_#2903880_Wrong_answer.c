#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char word1[81]={'\0'};
        char word2[81]={'\0'};
        char s[81]={'\0'};
        scanf("%s",&word1);
        scanf("%s",&word2);
        scanf("%s",&s);
        int firstfind1=100;
        int lastfind1=-1;
        int firstfind2=100;
        int lastfind2=-1;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==word1[0])
            {
                int k=1;
                while((s[i+k]==word1[k])&&(word1[k]!=0))
                    k++;
                if(k==strlen(word1))
                {
                    if(firstfind1==100)
                        firstfind1=i+k-1;
                    lastfind1=i;
                }
            }
            if(s[i]==word2[0])
            {
                int k=1;
                while((s[i+k]==word2[k])&&(word2[k]!=0))
                    k++;
                if(k==strlen(word2))
                {
                    if(firstfind2==100)
                        firstfind2=i+k-1;
                    lastfind2=i;
                }
            }
        }
        printf("%d %d\n",firstfind1,lastfind1);
        printf("%d %d\n",firstfind2,lastfind2);
        if((firstfind1==100)||(firstfind2==100))
            printf("0");
        else
        {
            int res=(lastfind1-firstfind2)>(lastfind2-firstfind1)? (lastfind1-firstfind2-1):(lastfind2-firstfind1-1);
            if(res<0)
                res=0;
            printf("%d",res);
        }

        printf("%c",10);
    }
    return 0;
}
