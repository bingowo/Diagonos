#include<stdio.h>
#include<stdlib.h>

int num(char *s)
{
    int f=0,i,sum;
    int l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*10+(s[i]-'0');
            f=1;
        }
        else f=0;
    }
    if(f==0) sum=-1;
    return sum;
}

int cmp(const void*a,const void*b)
{
    char *s1=(char*)a;
    char *s2=(char*)b;
    int d1=num(s1);
    int d2=num(s2);
    if(d1==d2) return strcmp(s1,s2);
    else
    {
        if(d1>d2) return 1;
        else return -1;
    }
}

int main()
{
    char s[100][50];
    int i=0,j;
    while(scanf("%s",s[i])!=EOF)  i++;
    qsort(s,i,sizeof(s[0]),cmp);
    for(j=0;j<i-1;j++)
        printf("%s ",s[j]);
    printf("%s\n",s[i-1]);
    return 0;
}
