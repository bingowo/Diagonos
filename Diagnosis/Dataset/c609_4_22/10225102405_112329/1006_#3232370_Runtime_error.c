#include<stdio.h>
int main()
{
    int T,i,j,k,P,ans,jishu,a;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        ans=1;
        char s[100];
        scanf("%s",&s[100]);
        P=1;
        for(j=0;j<strlen(s);j++){
            a=0;
            for(k=0;k<j;k++){
                if(s[k]==s[j]) {
                    break;
                }
                a=1;
            }
            if(a==1){P++;}
        }
        jishu=1;
        for(j=1;j<strlen(s);j++){
            ans*=P;
            if(j==1 &&s[1]!=s[0]){jishu++;}
            else if(j==1){ans++;}

        }
    }
}
