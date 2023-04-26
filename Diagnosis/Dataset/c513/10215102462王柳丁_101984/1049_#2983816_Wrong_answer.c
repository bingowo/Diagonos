#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char *a1=*(char**)a;
    char *b1=*(char**)b;
    /*while((*a1)&&(*b1)
    {
        if((*a1)!=(*b1))return ((*a1)>(*b1))?1:-1;
        else {a1++;b1++;}
    }*/
    return strcmp(a1,b1);
}
int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char a[500];
        char mid;
        char res[100][100]={'\0'};
        int line=0,k;
        do
        {
            scanf("%s",a);
            int list=0;
            for(k=0;k<strlen(a);k++)
            {
                if(a[k]!=','&&a[k]!='.'&&a[k]!='!'&&a[k]!='?')
                {
                    res[line][list++]=a[k];
                }
                else{line++;list=0;}
            }
            line++;
        }while(mid=getchar()!='\n');
        for(k=0;k<line;k++){printf("%s\n",res[k]);}
        //qsort(res,strlen(res),sizeof(res[0]),cmp);
       // for(k=0;k<line;k++){printf("%s ",res[k]);}
        printf("\n");
    }
    return 0;
}

