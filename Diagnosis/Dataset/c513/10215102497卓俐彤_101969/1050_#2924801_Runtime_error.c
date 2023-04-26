#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int findleft(char* str,char* s){
    int i,j=0,t=-1;
    for(i=0;i<strlen(str);i++){
        if(str[i]==s[j++]){
            if(j==strlen(s)){
                t=i;
                break;
            }else continue;
        }
        else j=0;
    }
    return t;
}

int findright(char* str,char* s){
    unsigned long int i,j=strlen(s)-1;
    int t=-1;
    for(i=strlen(str)-1;i>=0;i--){
        if(str[i]==s[j--]){
            if(j==-1){
            t=(int)i;
            break;
            }else continue;
        }
        else j=strlen(s)-1;
    }
    return t;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[81],s1[81],s2[81];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",str);
        int maxlen=0,l1=0,l2=0,r1=0,r2=0;
        l1=findleft(str,s1);
        l2=findleft(str,s2);
        r1=findright(str,s1);
        r2=findright(str,s2);
        if(l1!=-1&&l2!=-1){
            if(r2>l1)maxlen=r2-l1-1;
            else if(r1>l2)maxlen=r1-l2-1;
        }
        printf("case #%d:\n%d\n",t,maxlen);
    }
    
    return 0;
}
