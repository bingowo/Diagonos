#include<stdio.h>
#include<string.h>

int main(){
    char s[81];
    memset(s,0,sizeof(s));
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        char c=' ',e='\n';
        int n[160][160],l=0,w=80;
        for(int i=0;i<160;i++)
            for(int j=0;j<160;j++)n[i][j]=(int)c;
        n[w][l++]=(int)s[0];
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]){
                n[w][l++]=(int)s[i];
            }
            else if(s[i]<s[i-1]){
                //n[w][l]=(int)e;
                w--;n[w][l++]=(int)s[i];
            }
            else if(s[i]>s[i-1]){
                //n[w][l]=(int)e;
                w++;n[w][l++]=(int)s[i];
            }
        }
        for(int i=w;i>=0;i--){
            for(int j=0;j<l;j++){
                printf("%c",n[i][j]);
                if(n[i][j]==(int)e)break;
            }
        }
        memset(s,0,sizeof(s));
    }
}