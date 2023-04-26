#include<stdio.h>
#include<string.h>
int main(){
    int t;
    char m[][4]={"a","the","and","an","of","for"};
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        char s[100];
        int num=0;
        int k=0;
        while(scanf("%s",s)!=EOF){

            for(k=0;k<6;k++){
                if(strcmp(s,m[k])==0)break;
            }
            if(k==6)num++;
        }
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}