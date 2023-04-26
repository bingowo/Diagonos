#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a1,const void *b1)
{
    char a=*(char *)a1;
    char b=*(char *)b1;
    return a-b;
}
int main()
{
    int m;
    scanf("%d\n",&m);
    for(int z=0;z<m;z++)
    {
        char s[250];
        int i,j=0;
        gets(s);//输入字符串s 
        int l=strlen(s);
        char ans[250];
        for(int g=0;g<200;g++)
        {
            ans[g]='a';
        }
        char a[200];
        int count=0;
        for(i=0;i<l;i++)
        {
            if(s[i]<='Z'&&s[i]>='A')//如果是s[i]是英文字符 
            {
                a[j]=s[i];//数组a存储英文字符 
                j++;
                count++;// 英文字符数加一 
            }
            else
            {
                ans[i]=s[i];
            }
        }
        qsort(a,count,sizeof(a[0]),cmp);//对英文字符排序 
        i=0;
        j=0;
        for(int t=0;t<l;t++)
        {
            if(ans[t]=='a') {ans[t]=a[j];j++;}//插入排序后的英文字符 
        }
        printf("case #%d:\n",z);
        for(int g=0;g<l;g++)
            printf("%c",ans[g]);
        printf("\n");
    }
    return 0;
}
