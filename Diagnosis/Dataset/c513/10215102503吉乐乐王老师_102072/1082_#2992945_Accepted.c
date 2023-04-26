#include<stdio.h>
#include<string.h>
#define N 505
void input(int a[]){
    char s[501];
    scanf("%s",s);
    int sep=0;
    int i,j;
    for(int i=0;i<strlen(s);i++){if(s[i]=='.'){sep=i;break;}}
    if(strchr(s,'.')==NULL){
        for(i=strlen(s)-1,j=N-1;i>=0;i--,j--)a[j]=s[i]-'0';
        return;
    }
    for(i=sep+1,j=N;i<strlen(s);i++,j++)a[j]=s[i]-'0';
    for(i=sep-1,j=N-1;i>=0;i--,j--)a[j]=s[i]-'0';
}
int main(){
    int a[2*N+1]={0},b[2*N+1]={0};
    input(a);input(b);
    int n;
    scanf("%d",&n);
    for(int i=2*N;i>0;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[N+n]>4)a[N+n-1]+=1;
    for(int i=N+n-1;i>0;i--){
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    int idx=0;
    while(a[idx]==0&&idx<N)idx++;
    if(idx==N)printf("0");
    else for(int i=idx;i<N;i++)printf("%d",a[i]);
    putchar('.');
    idx=0;
    for(int i=N;i<2*N+1;i++){
        idx++;
        printf("%d",a[i]);
        if(idx==n)break;
    }
}