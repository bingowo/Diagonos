#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(char *ss){
    int x=strlen(ss);
    int y=0;
    int z=1;
    for(int i=0;i<x;i++){
        if(ss[i]=='1')y=y+z*1;
        if(ss[i]=='-')y=y+z*(-1);
        if(ss[i]=='0')y=y+z*0;
        z=z*3;
    }
    printf("%d\n",y);
}
int main(){
    int T;
    scanf("%d",&T);
    char s[100];
    for(int i=0;i<T;i++){
        scanf("%s",&s);
        printf("case #%d:\n",i);
        trans(s);
    }
    return 0;
}

