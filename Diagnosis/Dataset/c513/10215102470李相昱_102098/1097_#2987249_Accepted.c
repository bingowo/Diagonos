#include <stdio.h>
#include <string.h>
int main() {
    char s[8001];
    while(scanf("%s",s)!=EOF){
        char ret[201][80]={0};
        int len=strlen(s);
        int line=100;
        int loc[201]={0};
        ret[100][0]=s[0];
        for(int i=1;i<len;i++){
            if(s[i]>s[i-1]){
                line--;
            }
            if(s[i]<s[i-1]){
                line++;
            }
            ret[line][i]=s[i];
            if(loc[line]<i){
                loc[line]=i;
            }
        }
        for(int p=0;p<201;p++){
            if(loc[p]){
                for(int j=0;j<=loc[p];j++){
                    if(ret[p][j]==0){
                        printf(" ");
                    }else{
                        printf("%c",ret[p][j]);
                    }
                }
                printf("\n");
            }else if(ret[p][0]!=0){
                printf("%c\n",ret[p][0]);
            }
        }
    }
    return 0;
}
