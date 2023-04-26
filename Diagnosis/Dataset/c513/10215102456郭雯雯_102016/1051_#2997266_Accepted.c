#include<stdio.h>
#include<string.h>

struct group{
    int b[8],l;
};
struct group g[128];

int main(){
    int t,a=0;
    char r[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    scanf("%d",&t);
    for(int i=0;i<128;i++)g[i].l=-1;
    while(a<t){
        char s[101];
        scanf("%s",s);
        int l=strlen(s);
        int to2[8*l+10],to10[8*l+10],n=0;
        for(int i=l-1;i>=0;i--){
            int num=s[i];
            if(g[num].l==-1){
                int num0=num;
                for(int j=0;j<8;j++){
                    g[num].b[j]=(num0%2);
                    num0/=2;
                }
                g[num].l=1;
            }
            for(int j=0;j<8;j++)to2[n++]=g[num].b[j];
        }
        for(int i=n-1,j=0;i>=0;i--,j++)to10[j]=to2[i];
        while(n%6!=0)to10[n++]=0;
        int m=n/6,to[m];
        for(int i=0;i<m;i++){
            int k=0;
            for(int j=i*6;j<(i+1)*6;j++){
                k*=2;
                k+=to10[j];
            }
            to[i]=k;
        }
        char ans[m+4];
        for(int i=0;i<m;i++)ans[i]=r[to[i]];
        while(m%4!=0)ans[m++]='=';
        ans[m]='\0';
        printf("case #%d:\n%s\n",a,ans);
        a++;
    }
}