#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int len;
    char word[15];
}zidian;

int cmp (const void*a,const void*b)
{
    zidian aa=*((zidian*)a);
    zidian bb=*((zidian*)b);

    if(aa.len>bb.len)return -1;
    else if(aa.len<bb.len) return 1;
    else
    {
        return strcmp(aa.word,bb.word);
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    zidian *ku;
    ku=(zidian*)malloc(sizeof(zidian)*4010);
    for(i=0;i<n;i++)
    {
        scanf("%s",ku[i].word);
        ku[i].len=strlen(ku[i].word);
    }
    char *s,*xin[5000];
    s=(char*)malloc(sizeof(char)*5010);
    for(i=0;i<5000;i++)
    {
        xin[i]=(char*)malloc(sizeof(char)*15);
    }
    scanf("%s",s);
    int ls=strlen(s),co=0;
    qsort(ku,n,sizeof(zidian),cmp);
    /*for(i=0;i<n;i++)
    {
        printf("test:ku[%d].word=%s\n",i,ku[i].word);
    }*/

    for(i=0;i<ls;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strncmp(ku[j].word,s+i,ku[j].len)==0)
            {
                strcpy(xin[co++],ku[j].word);
                i+=(ku[j].len-1);
                break;
            }
        }
        if(j==n) {strncpy(xin[co],s+i,1);xin[co++][1]=0;}
        //printf("test:i=%d,co=%d  xin[%d]=%s\n",i,co,co-1,xin[co-1]);
    }
    for(i=0;i<co-1;i++)
    {
        printf("%s ",xin[i]);
    }
    printf("%s",xin[i]);
    for(i=0;i<5000;i++)
    {
        free(xin[i]);
    }
    free(ku);
    free(s);
    return 0;

}
