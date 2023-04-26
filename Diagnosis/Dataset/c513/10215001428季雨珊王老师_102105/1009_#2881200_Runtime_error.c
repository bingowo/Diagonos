#include<stdio.h>
#include<string.h>
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int k=0;k<n;k++){
        char s[120];
        gets(s);
        int b=strlen(s)*8;
        int count=0;
        for(int i=0;i<b/8;i++){
            while(s[i]){
                s[i]&=(s[i]-1);
                count++;
            }
        }
        int a=gcd(count,b);
        count/=a;
        b/=a;
        printf("%d/%d\n",count,b);
    }
    return 0;
}
