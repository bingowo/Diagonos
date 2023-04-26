#include <stdio.h>
#include <string.h>

char s[100000];

int main() {
    scanf("%s",s);
    int flag=0,num=0;
    unsigned long long sum=0;
    unsigned len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='0' && (flag==0 || flag==1) ){
            flag=1;
            continue;
        } else if(s[i]=='x' && flag==1){
            flag=2;
            continue;
        } else if(s[i]>='g' && s[i]<='z' && flag==2 && s[i-1]!='x'){
            printf("%llu ",sum);
            flag=0;
            num++;
            sum=0;
            continue;
        } else if(s[i]>='0' && s[i]<='9' && flag==2){
            sum=sum*16+s[i]-'0';
            continue;
        } else if(s[i]>='a' && s[i]<='f' && flag==2){
            sum=sum*16+s[i]-'a'+10;
            continue;
        } else{
            flag=0;
            continue;
        }
    }
    if(sum!=0)
        printf("%llu",sum);
    if(sum==0 && num==0)
        printf("-1\n");
    return 0;
}
