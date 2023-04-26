#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 30

void reverse(char* s){
    int len=strlen(s);char temp;
    for(int i=0,j=len-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int main(){
    char temp[N]={'\0'};
    long long n,R;
    scanf("%lld %lld",&n,&R);
    int left=0;
    if(n==0)printf("%d",left);
    else{
        while(n){
        if(n>0){
            temp[left++]=(abs(n%R)>9)?n%R-10+'A':n%R+'0';
            n/=R;
        }
        else{
            if(n%R==0){temp[left++]='0';n=n/R;}
            else{
                long long yu=abs((n/R+1)*R-n);
                temp[left++]=abs(yu)>9?yu-10+'A':yu+'0';
                n=n/R+1;}
            }
        }
        reverse(temp);
        printf("%s",temp);
        
    }
    return 0;
}