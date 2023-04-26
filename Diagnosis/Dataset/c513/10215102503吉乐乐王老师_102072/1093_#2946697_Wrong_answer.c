#include<stdio.h>
#include<string.h>
#define N 1001
int stoi(char s[],int a[]){
    char *p=s;int i=0;
    while(*p!='\0'){
        a[i]=*p-'0';
        i++;p++;
    }
}
int main(){
    char s[N];
    scanf("%s",s);
    int n=strlen(s);
    if(n==1&&s[0]!='8'){printf("%d",(s[0]-'0')+1);return 0;}
    int a[N]={0};
    int carry=0;
    stoi(s,a);
    a[n-1]+=1;
    for(int j=n-1;j>0;j--){
        a[j-1]+=a[j]/10;
        a[j]%=10;
    }
    carry+=a[0]/10;a[0]%=10;
    int ret=0;
    int i=0;
    while(i<n){
        if(a[i]==9){
            a[i]+=1;
            for(int j=i;j>0;j--){
                a[j-1]+=a[j]/10;
                a[j]%=10;
            }
            carry+=a[0]/10;a[0]%=10;
            for(int j=i+1;j<n;j++)a[j]=0;
            i=0;continue;
        }
        else {ret+=a[i];i++;}
        if(i==n){
            if(ret%9==0&&ret!=0){
                a[n-1]+=1;
                for(int j=n-1;j>0;j--){
                    a[j-1]+=a[j]/10;
                    a[j]%=10;
                }
                carry+=a[0]/10;a[0]%=10;
                ret=0;
                i=0;continue;
            }
        }
    }
    if(carry)printf("%d",carry);
    for(int i=0;i<n;i++)printf("%d",a[i]);
}