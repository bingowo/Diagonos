#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[30];
    scanf("%s",s);
    int len=strlen(s);
    int dot=0,r=0;
    for(int i=0;i<len;i++){
        if(isdigit(s[i])) continue;
        else{
            dot+=i;
            int t=len-1-i;
            for(int j=len-1;j=len-1-i;j--,t--){
                if(s[j]==1) r+=pow(3,-t);
                else if(s[j]==0) r=r;
                else r+=(-1)*pow(3,-t);
            }
            for(int j=i,k=0;j>=0,k<i+1;j--,k++){
                if(s[j]==1) r+=pow(3,k);
                else if(s[j]==0) r=r;
                else r+=(-1)*pow(3,k);
            }
        }
    }
    return 0;
}