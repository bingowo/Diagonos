#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char s[100];
    int l;
    int flag;
}NODE;

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    char c;
    for(int i=0;i<t;i++)
    {
        NODE a[205];
        int k=0,len=0;
        int p[26]={0};
        while(1)
        {
            c=getchar();
            if(c=='\n'||c==EOF)
                break;
            if(c!=' ')
            {
                a[k].s[len]=c;
                len++;
                p[c-'A']++;
                a[k].flag=0;
                if(c<'A'||c>'Z')
                {
                    a[k].flag=1;
                }

            }
            if(c==' ')
            {
                 a[k].s[len]='\0';
                 a[k].l=len;
                 k++;
                 len=0;
            }
        }
        a[k].l=len;
        char ans[205];
        int len2=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<p[i];j++)
            {
                ans[len2++]='A'+i;
            }
        }
       /* printf("%s\n",ans);
       for(int i=0;i<k+1;i++)
            printf("%s ",a[i].s);
        printf("\n");*/
        int m=0;
        printf("case #%d:\n",i);
        for(int i=0;i<k+1;i++)
        {
            if(a[i].flag==1)
                printf("%s ",a[i].s);
            else
            {
                for(int j=0;j<a[i].l;j++)
                {
                    printf("%c",ans[m++]);
                }
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
