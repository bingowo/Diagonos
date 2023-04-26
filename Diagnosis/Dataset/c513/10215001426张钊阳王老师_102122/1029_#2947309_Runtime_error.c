#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cmp(const void *a1,const void *b1);
    int m;
    scanf("%d\n",&m);
    for(int z=0;z<m;z++)
    {
        char s[200];
        int i,j=0;
        gets(s);
        int l=strlen(s);
        char ans[200];
        for(int g=0;g<200;g++)
        {
            ans[g]='a';
        }
        char a[200];
        int count=0;
        for(i=0;i<l;i++)
        {
            if(s[i]<='Z'&&s[i]>='A')
            {
                a[j]=s[i];
                j++;
                count++;
            }
            else
            {
                ans[i]=s[i];
            }
        }
        qsort(a,count,sizeof(a[0]),cmp);
        i=0;
        j=0;//标志点位置归零
        for(int z=0;z<l;z++)
        {
            if(ans[z]=='a') {ans[z]=a[j];j++;}
        }
        printf("case #%d:\n",z);
        for(int g=0;g<l;g++)
            printf("%c",ans[g]);
        printf("\n");
    }
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    char a=*(char *)a1;
    char b=*(char *)b1;
    return a-b;
}