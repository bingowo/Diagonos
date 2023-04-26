#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    int begin1=0,begin2=0;
    char a1[240];
    char b1[240];
    int nega1=0,nega2=0;
    if(aa[0]=='-'){nega1=1;begin1++;}
    else if(aa[0]=='+'){begin1++;}
    if(bb[0]=='-'){nega2=1;begin2++;}
    else if(bb[0]=='+'){begin2++;}
    int len1=strlen(aa);
    int index1=strlen(aa);
    for(int i=begin1;aa[i]!='\0';i++){if(aa[i]=='.')index1=i;break;}
        for(int i=begin1;i<=len1;i++){a1[120+i-index1]=aa[i];}
        for(int i=0;i<120+begin1-index1;i++)a1[i]='0';
    int len2=strlen(bb);
    int index2=strlen(bb);
    for(int i=begin2;bb[i]!='\0';i++){if(bb[i]=='.')index2=i;break;}
        for(int i=begin2;i<=len2;i++){b1[120+i-index2]=bb[i];}
        for(int i=0;i<120+begin2-index2;i++)b1[i]='0';
    if(nega1==nega2){
        if(nega1)return -strcmp(a1,b1);
        else return strcmp(a1,b1);
    }
    else return nega2-nega1;
}
int main(void)
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
