#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int jian(char* s1,char* s2)
{
    int len1=strlen(s1),len2=strlen(s2),jieguo=0,num=0;
    int ans[501];
    long long int daan=0;
    for(int i=len2-1,j=len1-1;i>=0;i--,j--){
        if((s1[j]-s2[i])>=0){
            jieguo=s1[j]-s2[i];
            ans[num]=jieguo;
            num++;
        }
        else {
            jieguo=10+s1[j]-s2[i];
            ans[num]=jieguo;
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
        ans[num]=s1[z]-'0';
        num++;
    }
    for(int n=num-1;n>=0;n--) daan=daan*10+ans[n];
    return daan;
}

int main()
{
    char s1[501],s2[501];
    while(scanf("%s %s",s1,s2)!=EOF){
        long long int ans=0;
        int len1=strlen(s1),len2=strlen(s2);
        if(len1<len2) ans=(-1)*jian(s2,s1);
        else if(len1>len2) ans=jian(s1,s2);
        else {
            int i=0;
            for(;i<len1;i++){
                if (s1[i]>s2[i]) {ans=jian(s1,s2);break;}
                else if(s1[i]<s2[i]) {ans=(-1)*jian(s2,s1);break;}
            }
            if(i==len1) ans=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
