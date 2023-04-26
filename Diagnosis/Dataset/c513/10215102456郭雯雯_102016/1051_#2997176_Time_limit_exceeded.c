#include<stdio.h>
#include<string.h>

char* t02(char* s){
    
}

int* to10(char* s){
    
}

int main(){
    int t,a=0;
    char r[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    scanf("%d",&t);
    while(a<t){
        char s[101];
        scanf("%s",s);
        int l=strlen(s);
        int to2[8*l+10],to10[8*l+10],n=0;
        for(int i=l-1;i>=0;i++){
            int num=s[i];
            while(num>0){
                to2[n]=num%2;
                num/=2;
                n++;
            }
            while(n%8!=0)to2[n++]=0;
        }
        for(int i=n-1,j=0;i>=0;i--,j++)to10[j]=to2[i];
        while(n%6!=0)to10[n++]=0;
        for(int i=0;i<n;i++)printf("%d",to10[i]);
        printf("case #%d:\n",a);
        a++;
    }
}