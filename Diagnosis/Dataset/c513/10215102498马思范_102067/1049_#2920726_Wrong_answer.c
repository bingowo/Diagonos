#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    char *x = (char *) a;
    char *y = (char *) b;
    return strcmp(x, y);
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    char s[501];
    char a[501][100];
    for(int i=0;i<t;i++)
    {
        int cnt=0,ct=0;
        gets(s);
        int len= strlen(s);
        printf("case #%d:\n",i);
        for(int j=0;j<len;j++)
        {
            if(s[j]>='a'&&s[j]<='z')
            {
                a[cnt][ct]=s[j];
                ct++;
            }
            else
            {
                a[cnt][ct++]='\0';
                cnt++;
                ct=0;
            }
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        printf("%s",a[0]);
        for(int p=1;p<cnt;p++)
        {
            if (strcmp(a[p],a[p-1]) != 0)
            {
                printf(" %s",a[p]);
            }
        }
        printf("\n");
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
    }
    return 0;
}