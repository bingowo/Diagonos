#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *s, *ans;
    int num1, flag=1;
    double num2;
    s = (char*)malloc(sizeof(char)*100);
    ans = (char*)malloc(sizeof(char)*100);
    while(scanf("%s" ,s)!=EOF){
        if(!strchr(s,'.'))  num1 = atoi(s); 
        else{
            num2 = atof(s);
            flag = 2;
        }
        if(flag==1) sprintf(ans,"%08x", num1);
        else sprintf(ans,"%016I64x", num2);
        for(int i=strlen(ans)-2; i>=0; i-=2)
            printf("%c%c ", ans[i], ans[i+1]);
        printf("%c", '\n');
    }
    free(s);
    free(ans);
    return 0;
}