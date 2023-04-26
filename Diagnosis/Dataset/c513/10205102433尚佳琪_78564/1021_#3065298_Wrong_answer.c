#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p[128]={0};
typedef struct
{
    char word[25];
    int ans;
}node;
int cmp1(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    int len1=strlen(s1.word),len2=strlen(s2.word);
    int min=len1>len2?len2:len1;
    for(int i=0;i<min;i++)
    {
        if(s1.word[i]!=s2.word[i])
            return p[s1.word[i]]-p[s2.word[i]];
    }
    if(len1>min)
        return 1;
    else if(len2>min)
        return 0;
    //return s1.ans-s2.ans;
}

int main()
{
    char s[30];
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            p[s[i]]=i;
            p[s[i]-'A'+'a']=i;
        }
        char c;
        getchar();
        node a[105];
        //for(int i=0;i<100;i++)
        //    a[i].ans=0;
        int k=0;
        int i=0;
        while(1)
        {
            c=getchar();
            if(c!=' '&&c!='\n')
            {
                a[k].word[i++]=c;
              //  a[k].ans=a[k].ans*26+p[c]-'0';
            }
            else if(c==' '||c=='\n')
            {
                a[k].word[i]='\0';
                i=0;
                k++;
                if(c=='\n')
                    break;
            }
        }
        qsort(a,k,sizeof(a[0]),cmp1);
        for(int i=0;i<k;i++)
            printf("%s ",a[i].word);
        printf("\n");
    }

    return 0;
}
