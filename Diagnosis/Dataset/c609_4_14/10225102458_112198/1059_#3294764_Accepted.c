#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    char a1[240];
    char b1[240];
    int nega1=0,nega2=0;
    if(aa[0]=='-'){nega1=-1;}
    if(bb[0]=='-'){nega2=-1;}
    int len1=strlen(aa);
    int index1=len1;
    int len2=strlen(bb);
    int index2=len2;
    for(int i=0;i<239;i++)a1[i]='0';
    for(int i=0;i<239;i++)b1[i]='0';
    a1[239]='\0';b1[239]='\0';
    a1[120]='.';b1[120]='.';
    for(int i=0;i<len1;i++){if(aa[i]=='.')index1=i;}
    for(int i=0;i<len2;i++){if(bb[i]=='.')index2=i;}
    for(int i=0;i<len1;i++){if(aa[i]!='-' && aa[i]!='+') a1[120+i-index1]=aa[i];}
    for(int i=0;i<len2;i++){if(bb[i]!='-' && bb[i]!='+')b1[120+i-index2]=bb[i];}
    if(nega1==nega2){
        if(nega1==-1)return -strcmp(a1,b1);
        else return strcmp(a1,b1);
    }
    else return nega1-nega2;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[n][120];
    for(int k=0;k<n;k++){
        scanf("%s",s[k]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)printf("%s\n",s[i]);
}
