#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
void func(char s[],int len)
{
    int *a=(int *)malloc(sizeof(int)*26);
    memset(a,0,26*4);
    char *b=(char *)malloc(sizeof(char)*len);
    memset(b,0,len);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            a[s[i]-'A']+=1;
    }

    int x=0,y=0,z=0;
    while(x<len)
    {
        if(s[x]>='A'&&s[x]<='Z')
        {
            while(a[y]==0) y++;
            b[z++]=y+'A';
            a[y]--;
            x++;
        }
        else b[z++]=s[x++];
    }
    printf("%s\n",b);
    free(a);
    free(b);
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[210];
        int len=0;
        char c=getchar();
        while((c!='\n'&&c!=EOF))
        {
            s[len++]=c;
            c=getchar();
        }
        printf("case #%d:\n",i);
        func(s,len);
    }
    return 0;
}
