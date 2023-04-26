#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char*aa=*(char(*)[501])a,*bb=*(char(*)[501])b;
    return strcmp(aa,bb);
}

int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char s[501][501]={0};
        int cnt=0,j=0;
        char ch=getchar();
        do
        {
            if(ch>='a'&&ch<='z') s[cnt][j]=ch,j++;
            else
            {
                cnt++;
                j=0;
            }
        }while((ch=getchar())!='\n');
        qsort(s,cnt,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<cnt;i++)
        {
            if(i+1==cnt) printf("%s\n",s[i]);
            else if(strcmp(s[i],s[i+1])!=0)
            {
                printf("%s ",s[i]);
            }

        }
    }
    return 0;
}
