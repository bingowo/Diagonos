#include <stdio.h>
#include <string.h>
int main(){
    char p[100][100];
    int i=0;
    while(scanf("%[^\n]",p[i])!=EOF){
        i=i+1;
    }
    int flag;
    for(int j=0;j<i+1;j++){
        int len=strlen(p[j]);
        int r=-1,s=-1,k;
        for(k=0;k<len;k++){
            if(p[j][k]=='/')r=k;
            if(p[j][k]=='*')s=k;
        }
        if(r==-1&&s==-1&&flag==0){
            puts(p[j]);
        }
        if(r==-1&&s==-1&&flag==1){
            continue;
        }
        if(r!=-1&&s==-1){
            for(int m=0;m<k;m++){
                printf("%c",p[j][m]);
            }
            printf("\n");
        }
        if(r==s+1){
            for(int m=r+1;m<len;m++){
                printf("%c",p[j][m]);
            }
            printf("\n");
            flag=0;
        }
        if(r==s-1){
            for(int m=0;m<r;m++){
                printf("%c",p[j][m]);
            }
            printf("\n");
            flag=1;
        }
    }
    return 0;
}