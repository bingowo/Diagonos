#include<stdio.h>
#include<stdlib.h>
int main(){
    const char *s1="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int r1,r2;
    int temp=0,count=0;
    long long sum=0;
    char s[33];
    char ans[33];
    scanf("%d %s %d",&r1,&s,&r2);
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='a'&&s[i]<='z')temp=(int)s[i]-87;
        else if(s[i]>='A'&&s[i]<='Z') temp=(int)s[i]-55;
        else temp=(int)s[i]-48;
        sum=sum*r1+temp;
    }
    while(sum!=0){
        ans[count++]=s1[sum%r2];
        sum/=r2;
    }
    if(count==0) printf("%d",0);
    for(int i=0;i<count;i++){
        printf("%c",ans[count-i-1]);
    }
    return 0;
}
