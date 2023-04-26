#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int p[26];

int cmp(const void *aa, const void *bb)
{
    char *a, *b;
    a=(char *)aa;
    b=(char *)bb;
    while(*a&&*b)
    {
        char ch1,ch2;
        ch1=(*a)>='a'?(*a)-32:(*a);
        ch2=(*b)>='a'?(*b)-32:(*b);
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
        else
        {
            a++;
            b++;
        }
    }
    //若此时仍没有输出，即直到a或b结束均相同
    if(*a==0)
        return -1;
    else return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        printf("case #%d:\n",cas);
        char s[27];
        scanf("%s",s);//获取字母顺序表
        for(int i=0; i<26; i++)
            p[s[i]-'A']=i;
        char str[2001];
        gets(str);
        char a[101][21];
        int cnt=0;//用于统计需要排列的总数
        int j=0;
        while(1)
        {
            int k=0;
            if(str[j]!=' '&&str[j])
                a[cnt][k++]=str[j++];
            a[cnt][k]='\0';
            cnt++;
            if(!str[j])
                break;
            else
                j++;
        }//将字符串归入二维数组
        qsort(a,cnt,sizeof(a[0]),cmp);
        for(int i=0; i<cnt-1; i++)
            printf("%s ",a[i]);
        printf("%s\n",a[cnt-1]);
    }
}
