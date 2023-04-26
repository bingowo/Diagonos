#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[1000];
        scanf("%s",s);
        int idx=0;
        int R=0,B=0,Y=0,G=0;
        while(idx<strlen(s)){
            if(s[idx]=='!'){
                int r=0,b=0,y=0,g=0;
                for(int i=idx+1;i<=idx+3&&i<strlen(s);i++){
                    if(s[i]=='R')r++;
                    else if(s[i]=='B')b++;
                    else if(s[i]=='Y')y++;
                    else if(s[i]=='G')g++;
                }
                for(int i=idx-1;i>=idx-3&&i>=0;i--){
                    if(s[i]=='R')r++;
                    else if(s[i]=='B')b++;
                    else if(s[i]=='Y')y++;
                    else if(s[i]=='G')g++;
                }
                if(!(r==0&&b&&y&&g)&&!(r&&b==0&&y&&g)&&!(r&&b&&y==0&&g)&&!(r&&b&&y&&g==0)){idx++;continue;}
                else{
                    if(r==0){s[idx]='R';R++;}
                    if(b==0){s[idx]='B';B++;}
                    if(y==0){s[idx]='Y';Y++;}
                    if(g==0){s[idx]='G';G++;}
                    idx++;continue;
                }
            }
            else {idx++;continue;}
        }
        idx=strlen(s)-1;
        while(idx>=0){
            if(s[idx]=='!'){
                int r=0,b=0,y=0,g=0;
                for(int i=idx+1;i<=idx+3&&i<strlen(s);i++){
                    if(s[i]=='R')r++;
                    else if(s[i]=='B')b++;
                    else if(s[i]=='Y')y++;
                    else if(s[i]=='G')g++;
                }
                for(int i=idx-1;i>=idx-3&&i>=0;i--){
                    if(s[i]=='R')r++;
                    else if(s[i]=='B')b++;
                    else if(s[i]=='Y')y++;
                    else if(s[i]=='G')g++;
                }
            if(!(r==0&&b&&y&&g)&&!(r&&b==0&&y&&g)&&!(r&&b&&y==0&&g)&&!(r&&b&&y&&g==0)){idx++;continue;}
                else{
                    if(r==0){s[idx]='R';R++;}
                    if(b==0){s[idx]='B';B++;}
                    if(y==0){s[idx]='Y';Y++;}
                    if(g==0){s[idx]='G';G++;}
                    idx--;continue;
                }
            }
            else {idx--;continue;}
        }
        printf("case #%d:\n%d %d %d %d\n",cas++,R,B,Y,G);
    }
}
