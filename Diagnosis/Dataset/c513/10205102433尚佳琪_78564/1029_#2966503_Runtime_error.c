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
    for(int i=0;i<t;i++)
    {
        NODE a[205];
        char b[205];
        int k=0,len=0;
        int p[26]={0};
        gets(b);
        int q=strlen(b);
        for(int i=0;i<q;i++)
       // while(1)
        {
            if(b[i]!=' ')
            {
                a[k].s[len]=b[i];
                len++;
                p[b[i]-'A']++;
                a[k].flag=0;
                if(b[i]<'A'||b[i]>'Z')
                {
                    a[k].flag=1;
                }

            }
            if(b[i]==' ')
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
