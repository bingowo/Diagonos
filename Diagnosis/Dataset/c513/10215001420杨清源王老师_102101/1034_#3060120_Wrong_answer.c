#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double flu[26];

//编写cmp函数
int cmp(const void *a, const void *b)
{
    char m, n;
    m=*((char *)a);
    n=*((char *)b);
    //比较两者在频率表中的相对位置
    int num1, num2;
    if(m>='a')
        num1=m-'a';
    else
        num1=m-'A';
    if(n>='a')
        num2=n-'a';
    else
        num2=n-'A';
    if(num1!=num2)
        return flu[num2]-flu[num1];
    else
        return n-m;
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
        for(int i=0; i<26; i++)
            scanf("%lf",&flu[i]);
        //输入字符串
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
}

