#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef unsigned long long ull;
ull getnum(char *a){
    ull ans=0;int i=0;
    while(*(a+i)!='\0'){
        if('0'<=a[i]&&a[i]<='9')ans=ans*10+(a[i]-'0');
        i++;
    }
    return ans;
}
int cmp(const void* a,const void* b){
    if(getnum((char*)a)==getnum((char*)b))return strcmp((char*)a,(char*)b);
    else return getnum((char*)b)-getnum((char*)a);
}
int mystrcmp(const void*a,const void*b){
    return strcmp((char*)a,(char*)b);
}
int main(){
    char *s[100];int si=0;
    char *n[100];int ni=0;
    char t[1000];
    while(scanf("%s",t)==1){
        int flag=0;
        for(int i=0;i<strlen(t);i++){
            if(isdigit(t[i])){flag=1;break;}
        }
        if(flag){
            n[ni]=(char*)malloc(sizeof(char)*(strlen(t)+1));
            strcpy(n[ni],t);ni++;
        }
        else{
            s[si]=(char*)malloc(sizeof(char)*(strlen(t)+1));
            strcpy(s[si],t);si++;}
        char ch=getchar();
        if(ch==' ')continue;
        if(ch=='\n')break;
    }
    qsort(s,si,sizeof(s[0]),mystrcmp);
    for(int i=0;i<si;i++){
        printf("%s",s[i]);
        if(i!=si-1)putchar(' ');
    }
    if(si!=0){
        if(ni==0)putchar('\n');
        else putchar(' ');}
    qsort(n,ni,sizeof(n[0]),cmp);
    for(int i=0;i<ni;i++){
        printf("%s",n[i]);
        if(i!=ni-1)putchar(' ');
    }
    putchar('\n');
}