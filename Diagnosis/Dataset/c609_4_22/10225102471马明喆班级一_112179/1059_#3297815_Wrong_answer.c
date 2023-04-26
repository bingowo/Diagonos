#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *s1,*s2;
    s1=*(char (*)[106])a;
    s2=*(char (*)[106])b;
    int sign1=1,sign2=1;
    int len1=0,len2=0;
    if(*s1=='-') sign1=-1,s1++;
    else if(*s1=='+') s1++;
    if(*s2=='-') sign2=-1,s2++;
    else if(*s2=='+') s2++;
    if(sign1*sign2==-1) return sign1-sign2;
    for(;*(s1+len1)&&*(s1+len1)!='.';len1++);
    for(;*(s2+len2)&&*(s2+len2)!='.';len2++);
    if(len1!=len2) return sign1*(len1-len2);
    else return sign1*strcmp(s1,s2);
}

int main(){
    int n;
    scanf("%d\n",&n);
    char s[101][106];
    for(int i=0;i<n;i++)
        scanf("%s\n",&s[i]);
    qsort(s,n,sizeof(s[0][106]),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",s[i]);
    return 0;
}