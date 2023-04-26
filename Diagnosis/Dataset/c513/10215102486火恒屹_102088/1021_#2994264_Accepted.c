#include <stdio.h>
#include <stdlib.h>
char order[28]={'\0'};
int lookup(char c)
{
    int res=-1;
    if(c>='a'&&c<='z')
        c=c-'a'+'A';
    for(int k=0;k<26;k++)
    {
        if(order[k]==c)
            {res=k;break;}
    }
    return res;
}
int cmp(const void*a,const void*b)
{
    char *x=(char*)a;
    char *y=(char*)b;
    int i=0;
    while(lookup(x[i])==lookup(y[i])) i++;
    return lookup(x[i])-lookup(y[i]);

}
int main()
{
    char c;
    char word[101][21]={'\0'};
    while((c=getchar())!=EOF)
    {
        ungetc(c,stdin);
        scanf("%s\n",&order);
        int i=0;
        while((c=getchar())!=10) {ungetc(c,stdin);scanf("%s",&word[i++]);}
        qsort(word,i,sizeof(word[0]),cmp);
        for(int j=0;j<i;j++)
            printf("%s ",word[j]);
        printf("%c",10);
    }
    return 0;
}
