#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
typedef struct
{
    char word[100];
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return strcmp(s1.word,s2.word);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        gets(s);
        int len=strlen(s);
        node a[500];
        int k=0,t=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=' '&&s[i]!=','&&s[i]!='.'&&s[i]!='!'&&s[i]!='?')
                a[k].word[t++]=s[i];
            else
            {
                if(t!=0)
                {
                    a[k].word[t]='\0';
                   // printf("%s ",a[k].word);
                    t=0;
                    k++;
                }
            }
        }
        if(s[len-1]!=' '&&s[len-1]!=','&&s[len-1]!='.'&&s[len-1]!='!'&&s[len-1]!='?')
        {
            a[k].word[t]='\0';
          //  printf("%s\n",a[k].word);
            t=0;
            k++;
        }
        qsort(a,k,sizeof(a[0]),cmp);
      //  printf("%d",k);
        printf("case #%d:\n",i);
        printf("%s ",a[0].word);
        for(int i=1;i<k;i++)
        {
            if(strcmp(a[i].word,a[i-1].word)!=0)
                printf("%s ",a[i].word);
        }
      // if(strcmp(a[k-2].word,a[k-1].word)!=0)
        //    printf("%s %s",a[k-2].word,a[k-1].word);
            //printf("%s ",a[i].word);
        printf("\n");
    }
}
