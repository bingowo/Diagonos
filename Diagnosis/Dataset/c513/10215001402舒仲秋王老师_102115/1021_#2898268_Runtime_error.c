#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    char word[101];
    char base[27];
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    int ret,i;
    d1=*((struct data*)a),d2=*((struct data*)b);
    for(i=0;;i++)
    {
         int t1=strchr(d1.base,d1.word[i])-d1.base;
         int t2=strchr(d2.base,d2.word[i])-d2.base;
         if(t1!=t2) {ret=t1-t2; break;}
    }
    return ret;
}

int main()
{
    for(;;)
    {
        char b[27];int i,j,flag;
        struct data ret[101];
        scanf("%s",b);
        for(i=0;i<101;i++) strcpy(ret[i].base,b);
        for(i=0;;i++)
        {
            for(j=0;(ret[i].word[j]=getchar())!=' ';j++)
            if(ret[i].word[j]=='\n'||ret[i].word[j]==EOF) break;
            ret[i].word[j]='\0';
        }
        ret[i].word[j]='\0';
        qsort(ret,i,sizeof(ret[0]),cmp);
        flag=i;
        for(i=0;i<flag;i++) printf("%s ",ret[i].word);
        printf("%s\n",ret[i].word);
    }
    return 0;
}
