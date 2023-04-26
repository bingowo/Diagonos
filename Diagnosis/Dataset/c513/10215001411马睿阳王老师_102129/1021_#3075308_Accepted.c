#include<stdio.h>
#include<stdlib.h>
int p[26];

int cmp(const void*a,const void*b)
{
    char *s1=(char *)a;
    char *s2=(char *)b;
    char ch1,ch2;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}

int main()
{
    char s[27];
    while(scanf("%s",s)!=EOF)
    {
        int i=0,j=0;
        for(i=0;i<26;i++)
            p[s[i]-'A']=i;
        char t[2200];
        gets(t);
        gets(t);
        char str[101][22];
        for(i=0;i<101;i++)//数组要归零
        {
            for(j=0;j<22;j++)
                str[i][j]='\0';
        }
        int num=0,len=0;
        for(j=0;t[j]!='\0';j++)//存储中间有空格的字符串
        {
            str[num][len]=t[j];
            if(isspace(t[j+1]))
            {
                str[num][len+1]='\0';
                num++;
                len=0;
                j++;
            }
            else len++;
        }
        num++;
        qsort(str,num,sizeof(str[0]),cmp);
        for(i=0;i<num-1;i++)
            printf("%s ",str[i]);
        printf("%s\n",str[num-1]);
     }
     return 0;
}
