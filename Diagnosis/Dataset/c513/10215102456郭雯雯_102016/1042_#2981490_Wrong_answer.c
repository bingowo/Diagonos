#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpc(const void *a,const void *b){
    return strcmp(&a,&b);
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
        qsort(c,strlen(c),sizeof(char),cmpc);
        printf("case #%d:\n",a);
        printf("%s\n",c);
        a++;
    }
}