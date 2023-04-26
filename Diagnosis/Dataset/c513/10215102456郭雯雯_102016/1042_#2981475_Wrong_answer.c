#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(char a,char b){
    int t=a-b;
    return t;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[20],c[20];
        scanf("%s",s);
        memset(c,0,sizeof(c));
        int l=strlen(s),lc=strlen(c);
        for(int i=0;i<l;i++){
            int j=0;
            while(j<lc&&s[i]!=c[j])j++;
            if(j==lc){c[j]=s[i];lc++;}
        }
        qsort(c,lc,sizeof(char),cmp);
        printf("case #%d:\n",a);
        printf("%s",c);
        a++;
    }
}