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
    int cnt=0,ct=0;
    for(int i=0;i<t;i++)
    {
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
                cnt++;
                ct=0;
            }
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        printf("%s ",a[0]);
        for(int p=1;p<cnt;p++)
        {
            if(strcmp(a[p],a[p-1])!=0)
                printf("%s%c",a[p],p==cnt-1?'\n':' ');
        }
        printf("\n");
    }
    return 0;
}