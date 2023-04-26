#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int key[16];

long long f(char n[],int k)
{
    long long ans=0;
    for(int i=0;i<k;i++){
        int temp=n[i];
        if(n[i]<97)ans=ans*16+temp-'0';
        else ans=ans*16+key[temp-'a'];
    }
    return ans;
}

int main()
{
    char s[100009];
    char aim[100009];
    int cnt=0;
    scanf("%s",s);
    for(int i=0;i<6;i++){
        key[i]=i+10;
    }
    for(int i=0;s[i]!=0;i++){
        if(s[i]=='0'&&s[i+1]=='x'&&s[i+2]<='f'&&s[i+2]!=0){
            int k=0;
            int j;
            for(j=i+2;s[j]!=0;j++){
                if(s[j]>'f')break;
                else aim[k++]=s[j];
            }
            aim[k]=0;
            long long ans=f(aim,k);
            printf("%lld ",ans);
            i=j;
            cnt++;
        }
    }
    if(cnt==0)printf("-1");
    return 0;
}