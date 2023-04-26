#include<stdio.h>
#include<string.h>

int main(){
    char s[81];
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        char c=' ',e='\n';
        int n[80][80],l=0,w=0;
        for(int i=0;i<80;i++)
            for(int j=0;j<80;j++)n[i][j]=(int)c;
        n[w][l++]=(int)s[0];
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]){
                n[w][l++]=(int)s[i];
            }
            else if(s[i]<s[i-1]){
                n[w][l]=(int)e;
                w--;n[w][l++]=(int)s[i];
            }
            else if(s[i]>s[i-1]){
                n[w][l]=(int)e;
                w++;n[w][l++]=(int)s[i];
            }
        }
        for(int i=w;i>=0;i--){
            for(int j=0;j<l;j++){
                if(n[i][j]==(int)e){printf("\n");break;}
                else printf("%c",n[i][j]);
            }
        }
    }
}