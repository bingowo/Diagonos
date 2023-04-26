#include<stdio.h>
#include<string.h>

struct group{
    int b[8],l;
};

int main(){
    int t,a=0;
    char r[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    scanf("%d",&t);
    struct group g[128];
    for(int i=0;i<128;i++)g[i].l=-1;
    while(a<t){
        char s[101];
        scanf("%s",s);
        int l=strlen(s);
        int to2[8*l+10],to10[8*l+10],n=0;
        for(int i=l-1;i>=0;i++){
            int num=s[i];
            if(g[num].l==-1){
                for(int j=0;j<8;j++){
                    g[num].b[j]=num%2;
                    num/=2;
                }
                g[num].l=1;
            }
            for(int j=0;j<8;j++)to2[n++]=g[num].b[j];
        }
        for(int i=n-1,j=0;i>=0;i--,j++)to10[j]=to2[i];
        while(n%6!=0)to10[n++]=0;
        for(int i=0;i<n;i++)printf("%d",to10[i]);
        printf("case #%d:\n",a);
        a++;
    }
}