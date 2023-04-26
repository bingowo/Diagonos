#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[120];
        scanf("%s",s);
        int len=strlen(s),num=0;
        for(int j=0;j<len;j++){
            int m=s[j]-'0';
            int count[len],sum=0;
            while(m){
                if((m&1)==1) count[j]++;
                m>>=1;
                sum++;
            }
        num+=count[j];
        }
        int g=((len*8)/num);
        printf("%d/%d\n",1,g);
    }
}