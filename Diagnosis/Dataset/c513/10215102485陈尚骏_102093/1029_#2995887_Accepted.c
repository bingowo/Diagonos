#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
    char a1=*(char*)a;
    char b1=*(char*)b;
    return a1-b1;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        char s[251];
        int x,y=0;
        gets(s);
        int len=strlen(s);
        char ans[251];
        for(int j=0;j<200;j++)
        {
            ans[j]='a';
        }
        char a[200];
        int cnt=0;
        for(x=0;x<len;x++)
        {
            if(s[x]>='A'&&s[x]<='Z')
            {
                a[y]=s[x];
                y++;
                cnt++;
            }
            else ans[x]=s[x];
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        x=0;
        y=0;
        for(int k=0;k<len;k++)
        {
            if(ans[k]=='a') {ans[k]=a[y];y++;}
        }
        printf("case #%d:\n",i);
        for(int k=0;k<len;k++)
            printf("%c",ans[k]);
        printf("\n");
    }
    return 0;
}
