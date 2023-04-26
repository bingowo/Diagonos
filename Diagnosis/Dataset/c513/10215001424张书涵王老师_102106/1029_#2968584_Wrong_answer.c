#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *ap=(char*)a;
    char *bp=(char*)b;
    if(((*ap<=90)&&(*ap>=65))&&((*bp<=90)&&(*bp>=65)))
    {
        if(*ap>*bp)
            return 1;
        return -1;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int l;
        char a[200]={0};
        char b[201]={0};
        int lenth[100]={0};
        int k,j=0,p,q;
        gets(b);
        for(p=0,q=0;b[j]!='\n'&&b[j]!='\0';q++)
        {
            for(k=0;b[j]!=' '&&b[j]!=0;j++,p++,k++)
                a[p]=b[j];
            lenth[q]=k;
            if(b[j]==' ')
                j++;
        }
        l=strlen(a);
        qsort(a,l,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(j=0,p=0;lenth[j]!=0;j++)
        {
            for(q=0;q<lenth[j];p++,q++)
                printf("%c",a[p]);
            printf(" ");
        }
        printf("\n");
    }
}
