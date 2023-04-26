#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    int k1=0,k2=0;
    char*s1,*s2;
    s1=(char*)a;s2=(char*)b;
    if(strlen(s1)>strlen(s2))return -1;
    else return 1;
}
void read(char s1[20],char s2[20])
{
    int i=0,j=strlen(s2);
    for(i=0;i<j;i++)s1[i]=s2[i];
    s1[i]='\0';
}
int main()
{
    char s[4400][20]={0};char re[4400][20]={0};
    char str[6000]={0};
    int n=0,i=0,j=0,m=0,k=0,r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    scanf("%s",str);
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;str[i];i=i)
    {
        char t[20]={0};
        for(k=0;k<n;k=k)
        { j=strlen(s[k]);
        if(j>1)
        {
        if(strlen(t)!=j){if(str[i+j-1]){for(m=0;m<j && str[m+i];m++)t[m]=str[m+i];t[m]='\0';}else k++;}
        else {if(strcmp(t,s[k])==0){read(re[r],t);r++;i=i+j;break;}else k++;}
        }
        else {re[r][0]=str[i];re[r][1]='\0';r++;i++;break;}
        }
    }
    for(i=0;i<r;i++)printf("%s ",re[i]);
    return 0;
}
