#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100000];
    scanf("%s",s);
    unsigned int ans[10001]={0};
    int num=0;
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='0'&&s[i+1]=='x'){
            i+=2;
            int n=0,sum=0;
            while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')){
                n=1;
                if(s[i]>='0'&&s[i]<='9') sum=sum*16+s[i++]-'0';
                if(s[i]>='a'&&s[i]<='f') sum=sum*16+s[i++]-'a'+10;
            }
            if(n==1) ans[num++]=sum;
        }
    }
    if(num==0) printf("-1");
    else for(int i=0;i<num;i++) printf("%u ",ans[i]);

	return 0;
}