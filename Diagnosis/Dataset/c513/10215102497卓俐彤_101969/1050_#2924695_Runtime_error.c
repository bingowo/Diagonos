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
        int maxlen=0,t1=0,t2=0;
        t1=findleft(str,s1);
        t2=findright(str,s2);
        if(t1!=-1&&t2!=-1)maxlen=t2-t1-1;
        printf("case #%d:\n%d\n",t,maxlen);
    }
    
    return 0;
}
