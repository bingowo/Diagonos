#include<stdio.h>
#include<stdlib.h>

int p[26];
int cmp(const void*a,const void*b)
{
    char *s1=(char*)a;
    char *s2=(char*)b;//将a，b转化为指针
    char ch1,ch2;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
        else {s1++,s2++;}
    }
    if(*s1==0) return 0;
    else return 1;
}

int main()
{
    int i,j,k,num,len;
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(i=0;i<26;i++) p[s[i]-'A']=i;
        char t[10000],str[101][21];
        for(i=0;i<101;i++)
        {
            for(j=0;j<21;j++)
                str[i][j]='\0';
        }
        gets(t);
        num=0;len=0;
        for(j=0;t[j]!='\0';j++)
        {
            str[num][len]=t[j];
            if(isspace(t[j+1]))
            {
                str[num][len+1]='\0';
                j++;num++;
                len=0;
            }
            else len++;
        }
        num++;
        qsort(str,num,sizeof(str[0]),cmp);
        for(k=0;k<num;k++)
            printf("%s%c",str[k],k==num-1?'\n':isspace());
    }
    return 0;
}
