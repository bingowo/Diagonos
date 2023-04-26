#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[100001];
    long long int j;
    scanf("%s",s);
    int len=strlen(s);
    long long int sum[100001]={0};
    for(int i=0;i<len;i++){
        if(i==0){
            while(s[i]!='x'){
                i++;
            }
            j=i+1;
            int t;
                while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f')){
                    if(s[j]>='0'&&s[j]<='9'){
                    t=s[j]-'0';}
                    else t=s[j]-'a'+10;
                    sum[i]=sum[i]*16+t;
                    j++;
                }
        }

        if(s[i-1]>'f'&&s[i]=='0'&&s[i+1]=='x'){
                j=i+2;
                int t;
                while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f')){
                    if(s[j]>='0'&&s[j]<='9'){
                    t=s[j]-'0';}
                    else t=s[j]-'a'+10;
                    sum[i]=sum[i]*16+t;
                    j++;
                }

        }
        if(s[i-2]>'f'&&s[i]=='0'&&s[i+1]=='x'){
                j=i+2;
                int t;
                while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='f')){
                    if(s[j]>='0'&&s[j]<='9'){
                    t=s[j]-'0';}
                    else t=s[j]-'a'+10;
                    sum[i]=sum[i]*16+t;
                    j++;
                }

        }
    }
    int tmp=0;
    for(int k=0;k<len;k++){
        if(sum[k]!=0){
            printf("%lld ",sum[k]);
        }
        if(sum[k]==0){
            tmp++;
        }
    }
    if(tmp==len){
        printf("-1");
    }

    return 0;
}
