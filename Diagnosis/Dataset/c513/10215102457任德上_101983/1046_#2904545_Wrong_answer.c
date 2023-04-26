#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int t;
    char m[][4]={"a","the","and","an","of","for"};
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        char s[100],c;
        int num=0;
        int k=0;
        while((c=getchar())!='\n'){
            ungetc(c,stdin);
            scanf("%s",s);
            
            for(k=0;k<6;k++){
                if(strcmp(s,m[k])==0)break;
            }
            if(k==6)num++;
        }
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}
