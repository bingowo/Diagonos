#include <stdio.h>
#include <string.h>

void insert(char* s,char c,int index){
    
}
int del(char* s){
    
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s1[100],s2[100];
        scanf("%s",s1);
        int dele=0;
        int len=strlen(s);
        int sum;
        for(int i=0;i<len+1;i++{
            strcpy(s2,s1);
            insert(s2,'A',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'B',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'C',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
        }
        printf("case #%d:\n%d\n",t,sum);
    }
    return 0;
}