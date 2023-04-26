#include<stdio.h>
#include<string.h>
const char*getbin(int num,int len){
    static char temp[11];
    for(int i=len-1;i>=0;i--){
        temp[i]=num%2+'0';
        num/=2;
    }
    temp[len]='\0';
    return temp;
}
int main(){
    char input[501];
    scanf("%s",input);
    int n=strlen(input);
    char output[2005]={"\0"};
    strcat(output,"0001");
    strcat(output,getbin(n,10));
    int yushu=n%3;
    for(int i=0,j=1,k=2;k<n-yushu;i+=3,j+=3,k+=3){
        int num=0;
        num=(input[i]-'0')*100+(input[j]-'0')*10+(input[k]-'0');
        strcat(output,getbin(num,10));
    }
    if(yushu==1)strcat(output,getbin(input[n-1]-'0',4));
    if(yushu==2)strcat(output,getbin((input[n-2]-'0')*10+input[n-1]-'0',7));
    printf("%s",output);
}