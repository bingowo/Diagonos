#include <stdio.h>
#include <stdlib.h>

int alpha[27];
char s[27];

int cmp(const void *a,const void *b)
{
    char *s1,*s2,ch1,ch2;
    s1=*((char(*)[21])a);
    s2=*((char(*)[21])b);
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;   //转换为大写字母
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(alpha[ch1-'A']>alpha[ch2-'A'])return 1;
        else if(alpha[ch1-'A']<alpha[ch2-'A'])return -1;
        else {s1++;s2++;}
    }
    if(*s1==0)return -1;
    else return 1;
}

void solve()
{
    for(int i=0;i<26;i++)
    {
        alpha[s[i]-'A']=i;
    }
    getchar();
    char a[101][21];
    char c;
    int i=0,j=0;
    do{
        c=getchar();
        if(c!=' '&&c!='\n')
        {
            a[i][j]=c;
            j++;
        }
        else
        {
            a[i][j]='\0';
            i++;
            j=0;
        }
    }while(c!='\n');
    qsort(a,i,sizeof(a[0]),cmp);
    for(j=0;j<i-1;j++)
    {
        printf("%s ",a[j]);
    }
    printf("%s\n",a[j]);
}

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        solve();
    }
    return 0;
}
