#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    return strcmp(s1,s2);
}
void paixu(int h)
{
    char str[1000]={0};
    char t[1000][1000]={0};
    int i=0,r=0,j=0;
    gets(str);
    while(str[i])
        {
            j=0;
            while(str[i]!=' '&& str[i]!=',' && str[i]!='.' && str[i]!='?' && str[i]!='!' && str[i]){t[r][j]=str[i];j++;i++;}
            if(j!=0){t[r][j]='\0';r++;}
            if(str[i]!=' '|| str[i]!=',' || str[i]!='.' || str[i]!='?' || str[i]!='!' ){i++;}
        }
        qsort(t,r,sizeof(t[0]),cmp);
        printf("case #%d:\n",h);
        printf("%s ",t[0]);
    for(i=1;i<r;i++)
    {
        if(strcmp(t[i],t[i-1])!=0)printf("%s ",t[i]);
    }
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    getchar();
    for(h=0;h<N;h++)
        paixu(h);
}
