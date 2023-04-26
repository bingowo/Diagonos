#include <stdio.h>
#include <stdlib.h>
int main()
{
    int p[26];
    char alpha[27];
    while(scanf("%s",alpha)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alpha[i]-'A']=i;
        getchar();
    }
    char a[101][21];
    int count=0,k=0,status=0;
    char c;
    do
    {
        c=getchar( );
        if(c!=' '&&c!='\n') {a[count][k++]=c;status=1;}
        else if(status)
            {a[count][k]='\0';count=count+1;k=0;status=0;}
    } while (c!='\n');
    int cmp(const void *a,const void *b)
{
    char *s1,*s2;char ch1,ch2;
    s1=*(char (*)[21])a;s2=*(char (*)[21])b;
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
    qsort(a,count,sizeof(a[0]),cmp);
    char (*a11)[21]=a;
    for (int i=0;i<count-1;i++)
        printf("%s ",a11++);
    return 0;
}
