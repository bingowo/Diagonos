#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return(strcmp((char*)a,(char*)b));
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    char s[511];
    char a[511][100];
    for(int i=0;i<t;i++)
    {   int flag=0;
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
                flag=1;
            }
            else
            {
                if(flag==1) {
                    a[cnt][ct++] = '\0';
                    cnt++;
                    ct = 0;
                }
            }
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        printf("%s",a[0]);
        for(int p=1;p<cnt;p++)
        {
            if (strcmp(a[p],a[p-1])!= 0)
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