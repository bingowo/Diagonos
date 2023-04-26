#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100001];
    scanf("%s",s);
    long long sum[10000]={0};
    int flag[10000]={-1};
    int i,j,temp;
    for(i=0,j=0;i<strlen(s);i++){
        if(s[i]=='0'&&s[i+1]=='x'&&i+1<strlen(s)){
            i+=2;
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
                flag[j]=1;
            while(s[i]){
                if((s[i]>='g'&&s[i]<='z')||(s[i]=='0'&&s[i+1]=='x'&&s[i-1]>='g'))
                    break;
                if(s[i]>='0'&&s[i]<='9')
                    temp=s[i]-'0';
                if(s[i]>='a'&&s[i]<='f')
                    temp=s[i]-'a'+10;
                sum[j]*=16;
                sum[j]+=temp;
                i++;
            }
            j++;
        }
    }
    for(int k=0;k<j;k++){
        if(flag[k]!=-1)
            break;
        printf("-1");
    }
    for(int k=0;k<j;k++)
        if(flag[k]==1)
            printf("%lld ",sum[k]);
    return 0;
}
