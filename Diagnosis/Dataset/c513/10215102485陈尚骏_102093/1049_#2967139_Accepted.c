#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    return strcmp(s1,s2);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char a[501];
        char b[200][20]={'\0'};
        char c[200][20]={'\0'};
        if(i==0)
            getchar();
        gets(a);
        int j,k,l=0;
        for(j=0;j<strlen(a);j++)
        {
            k=0;
            while(a[j]>='a'&&a[j]<='z')
            {
                b[l][k++]=a[j];
                j++;
            }
            if(k!=0) l++;
        }
        int nb=l,nc=0;
        for(j=0;j<nb;j++)
        {
            l=0;
            for(k=0;k<nc;k++)
            {
                if(!strcmp(b[j],c[k])) l++;
            }
            if(l==0) strcpy(c[nc++],b[j]);
        }
        qsort(c,nc,sizeof(c[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<nc-1;j++) printf("%s ",c[j]);
        printf("%s\n",c[j]);
    }
    return 0;
}
