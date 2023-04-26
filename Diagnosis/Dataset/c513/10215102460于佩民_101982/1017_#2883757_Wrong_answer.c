#include <stdio.h>
#include <string.h>

int main(){
    char str[51];
    int i,cnt=0;
    long long flag=1;
    scanf("%s",str);
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;Roma['C']=100;Roma['D']=500;Roma['M']=1000;
    long long data[100];
    long long ans=0;
    for(i=0;i<strlen(str);i++){
        switch(str[i])
        {
            case '(': flag=flag*1000;break;
            case ')': flag=flag/1000;break;
            default: data[cnt++]=Roma[str[i]]*flag; break;
        }
    }
    for(i=0;i<strlen(str)-1;i++){
        if(data[i]<data[i+1]) ans-=data[i];
        else ans+=data[i];
    }
    if(i==strlen(str)-1)  ans+=data[i];
    printf("%lld\n",ans);
    return 0;
}