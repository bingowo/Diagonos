#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef unsigned long long ull;
int  getnum(char *a){
    int ans=0,flag=0;
    for(int i=0;i<strlen(a);i++){
        if(isalnum(a[i])){
            ans=ans*10+(a[i]-'0');
            flag=1;}
    }
    if(flag==0)ans=-1;
    return ans;
}
int cmp(const void* a,const void* b){
    char*s1=(char*)a;char *s2=(char*)b;
    if(getnum(s1)==getnum(s2))return strcmp(s1,s2);
    return getnum(s1)>getnum(s2)?1:-1;
}
int main(){
    char s[110][40];int i=0;
    while(scanf("%s",s[i])!=EOF)i++;
    qsort(s,i,sizeof(s[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%s",s[j]);
        if(j!=i-1)putchar(' ');
    }
    putchar('\n');
}