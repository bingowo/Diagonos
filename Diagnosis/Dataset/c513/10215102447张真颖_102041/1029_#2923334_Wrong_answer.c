#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void*b)
{
    char aa=*(char*)a,bb=*(char*)b;
    if(aa<'A'||aa>'Z'||bb<'A'||bb>'Z') return -1;
    return aa-bb;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[201]={0};
        int t[201]={0},count=0;
        do
        {
            char st[201]={0};
            scanf("%s",st);
            t[count++]=strlen(st);
            strcat(s,st);
        }while(getchar()!='\n');
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0,j=0;i<strlen(s);j++)
        {
            for(int x=0;x<t[j];x++)
                printf("%c",s[i]),i++;
            if(i==strlen(s)) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
