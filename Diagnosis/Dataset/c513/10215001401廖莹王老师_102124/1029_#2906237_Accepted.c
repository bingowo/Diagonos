#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    return strcmp(s1,s2);
}
void zf(int h)
{
    char str[210]={0},t[210][210]={0},m[210]={0};

     int i=0,j=0,r=0,k=0;
       gets(str);
        while(str[i])
        {
            j=0;
            while(str[i]!=' '&& str[i]){t[r][j]=str[i];j++;i++;}
            t[r][j]='\0';
            if(str[i]==' ')r++,i++;
        }
    for(i=0;i<r+1;i++)
    {
        for(j=0;t[i][j];j++)
        if(t[i][j]>='A' && t[i][j]<='Z'){m[k]=t[i][j];k++;}
    }
    m[k]='\0';
    qsort(m,k,sizeof(m[0]),cmp);
    k=0;
    for(i=0;i<r+1;i++)
    {
        for(j=0;t[i][j];j++)
        if(t[i][j]>='A' && t[i][j]<='Z'){t[i][j]=m[k];k++;}
    }
    printf("case #%d:\n",h);
    for(i=0;i<r+1;i++)printf("%s ",t[i]);
    printf("\n");
}
int main()
{
    int n=0,h=0;
    scanf("%d",&n);
     getchar();
    for(h=0;h<n;h++)
        zf(h);
}
