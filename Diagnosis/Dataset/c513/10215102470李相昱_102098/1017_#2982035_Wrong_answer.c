#include <stdio.h>
#include <string.h>
int main() {
    char s[51];
    int s2[128]={0};
    int s3[50]={0};
    s2['I']=1;
    s2['V']=5;
    s2['X']=10;
    s2['L']=50;
    s2['C']=100;
    s2['D']=500;
    s2['M']=1000;
    scanf("%s",s);
    int len= strlen(s),flag=1;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            flag=1000*flag;
        }else if(s[i]==')'){
            flag=flag/1000;
        }else{
            s3[i]= s2[s[i]]*flag;
        }
    }
    long long int ret=0,j=0;
    for(;j<len-1;j++){
        if(s3[j]<s3[j+1]){
            ret = ret-s3[j];
        }else{
            ret = ret+s3[j];
        }
    }
    ret= ret+s3[j];
    printf("%lld",ret);
    return 0;
}
