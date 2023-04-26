#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jian(char* s1,char* s2,char* ans)
{
    int len1=strlen(s1),len2=strlen(s2),jieguo=0,num=0;
    for(int i=len2-1,j=len1-1;i>=0;i--,j--){
        if((s1[j]-s2[i])>=0){
            jieguo=s1[j]-s2[i];
            ans[num]=jieguo+'0';
            num++;
        }
        else {
            jieguo=10+s1[j]-s2[i];
            ans[num]=jieguo+'0';
            num++;
            if(s1[j-1]=='0') {
                int k=j-2;
                s1[j-1]='9';
                while(s1[k]=='0'){
                    s1[k]='9';
                    k--;
                }
                s1[k]-=1;
            }
            else s1[j-1]-=1;
        }
    }
    for(int z=len1-len2-1;z>=0;z--) {
        ans[num]=s1[z];
        num++;
    }
    ans[num]=0;
}

int main()
{
    char s1[501],s2[501];
    while(scanf("%s %s",s1,s2)!=EOF){
        char ans[501];
        int len1=strlen(s1),len2=strlen(s2);
        if(len1<len2) {jian(s2,s1,ans);printf("-");}
        else if(len1>len2) jian(s1,s2,ans);
        else {
            int i=0;
            for(;i<len1;i++){
                if (s1[i]>s2[i]) {jian(s1,s2,ans);break;}
                else if(s1[i]<s2[i]) {jian(s2,s1,ans);printf("-");break;}
            }
            if(i==len1) {ans[0]='0';ans[1]=0;}
        }
        int keyi=0;
        for(int j=strlen(ans)-1;j>=0;j--) {
            if(ans[j]>'0') keyi=1;
            if(keyi) printf("%c",ans[j]);
            if(keyi==0&&j==0) printf("0\n");
        }
        printf("\n");
    }
    return 0;
}
