#include <stdio.h>
#include <stdlib.h>

int p[26];

char up(char x)
{
    if (x<='z'&&x>='a')
        return x+'A'-'a';
    return x;
}
int cmp(const void *p1,const void *p2)
{
    char *a=(char*)p1;char *b=(char*)p2;
    while((*a)!='\0'&&(*b)!='\0')
    {
        if(p[up(*a)-'A']<p[up(*b)-'A'])
            return -1;
        if(p[up(*a)-'A']>p[up(*b)-'A'])
            return 1;
        a++;b++;
    }
    if((*a)=='\0')
        return -1;
    if((*b)=='\0')
        return 1;
    return 0;
}
int main()
{
    char seq[27];
    while(scanf("%s",seq)!=EOF){
    for(int i=0;i<26;i++)
    {
        p[seq[i]-'A']=i;
    }
    /*for(int i=0;i<26;i++)
    {
        printf("%d",p[i]);
    }*/
    char strings[102][22];
    int nums=0;
    char c;
    c=getchar();
    do{
        c=getchar();
        if(c=='\n')
            break;
        else
        {
            ungetc(c,stdin);
            scanf("%s",strings[nums]);
            nums++;
        }
    }while(1);
    /*for(int i=0;i<nums;i++)
    {
        printf("%s ",strings[i]);
    }*/
    qsort(strings,nums,sizeof(strings[0]),cmp);
    for(int i=0;i<nums;i++)
    {
        printf("%s ",strings[i]);
    }
    //printf("\n");
    }
    return 0;
}