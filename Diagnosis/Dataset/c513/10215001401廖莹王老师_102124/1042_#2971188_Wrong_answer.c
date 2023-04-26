#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    char word[20];
}single;
single p[1000];
int q=0;
void makeword(char t[25],int l,int k,char str[25])
{
    if(k>=l)
    {
        str[l]=0;
        strcpy(p[q].word,str);q++;
        return ;
    }
    int i=0,nl=l-k-1;
    for(i=0;i<strlen(t)-nl;i++)
    {
        str[k]=t[i];
        makeword(t+i+1,l,k+1,str);
    }
}
int cmp(const void*a,const void*b)
{
    char*s1,*s2;
    s1=*((char*)a);
    s2=*((char*)b);
    return s1-s2;
}

int cmp1(const void*a,const void*b)
{
    single*s1,*s2;
    s1=(single*)a;
    s2=(single*)b;
    int k=strcmp(s1->word,s2->word);
    if(k>=0)return 1;
    else return -1;
}
int number(int k,int h)
{
    int i=0,sum=1;
    for(i=0;i<h;i++)sum=sum*(k-i);
    for(i=0;i<h;i++)sum=sum/(i+1);
    return sum;
}
void jisuan(int h)
{
    char s[25]={0};
    char t[25]={0};
    char a[1000][25]={0};
    scanf("%s",s);
    int i=0,count=1,j=0,k=0;
    qsort(s,strlen(s),sizeof(s[0]),cmp);
    t[k]=s[0];k++;
    for(i=1;s[i];i++)
    {if(s[i]!=s[i-1]){t[k]=s[i];k++;}}t[k]='\0';
    qsort(t,k,sizeof(t[0]),cmp);
    for(i=0;i<k;i++)count=count*2;
    char str[25]={0};
    q=0;
    for(i=1;i<k;i++){makeword(t,i,0,str);}
    qsort(p,q,sizeof(p[0]),cmp1);
    printf("case #%d:\n",h);
    for(i=0;i<q;i++){printf("%s\n",p[i].word);}
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}

