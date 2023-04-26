#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//编写cmp函数
int cmp(const void *a, const void *b)
{
    char m, n;
    m=*((char *)a);
    n=*((char *)b);
    //比较两者在频率表中的相对位置
    int num1, num2;
    if(m>'a')
        num1=m-'a';
    else
        num1=m-'A';
    if(n>'a')
        num2=n-'a';
    else
        num2=n-'A';
    if(num1!=num2)
        return num2-num1;
    else
        return m-n;
}

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        printf("case #%d:\n",cas);

        //输入频率表
        double flu[26];
        for(int i=0; i<26; i++)
            scanf("%lld",&flu[i]);
        //输入字符串
        char s[100];
        scanf("%s",s);
        int len=strlen(s);

        qsort(s,len,sizeof(s[0]),cmp);
        for(int i=0; i<len; i++)
            printf("%c",s[i]);
        printf("\n");
    }
}

