#include<stdio.h>
int main(){
    int r[128]={0};
    r['I']=1,r['V']=5,r['X']=10,r['L']=50,r['C']=100,r['D']=500,r['M']=1000;
    char s[100];
    scanf("%s",s);
    long long flag=1;
    long long data[100];
    int cut=0;
    for(int i=0;s[i];i++){
        switch(s[i]){
            case '(':flag=flag*1000;break;
            case ')':flag=flag/1000;break;
            default:data[cut++]=r[s[i]]*flag;break;
        }
    }
    long long ans=0;
    for(int i=0;i<cut-1;i++){
        if(data[i]<data[i+1]){
            ans-=data[i];
        }
        else{
            ans+=data[i];
        }
    }
    ans+=data[cut-1];
    printf("%lld\n",ans);
    return 0;
}