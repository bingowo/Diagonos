#include<stdio.h>
#include<string.h>
#define N 2000
void get(char s[],int a[],int b[]){
    char *p=s;
    int idx=0;
    while(*p!='.'&&*p){
        a[idx]=*p-'0';p++;idx++;
    }
    if(idx)a[idx]=-1;
    if(*p=='\0')return;
    p++;idx=1;
    while(*p){
        b[idx]=*p-'0';p++;idx++;
    }
}
void adjust(int a[]){
    int idx=0;
    while(a[idx]!=-1&&idx<N)idx++;
    if(idx==N)return ;
    a[idx]=0;
    int end1=idx-1,end2=N-1;
    for(;end1>=0;end1--,end2--){
        a[end2]=a[end1];
        a[end1]=0;
    }
}
void add(int a[],int c[]){
    for(int i=N-1;i>0;i--){
        a[i]+=c[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}
int main(){
    int a[N]={0},b[N]={0},c[N]={0},d[N]={0};
    char s[N];
    scanf("%s",s);getchar();
    get(s,a,b);
    scanf("%s",s);getchar();
    get(s,c,d);
    adjust(a),adjust(c);
    add(b,d);
    int n;
    scanf("%d",&n);
    if(b[n+1]>4){
        b[n]+=1;
        for(int i=n;i>0;i--){
            b[i-1]+=b[i]/10;
            b[i]%=10;
        }
    }
    c[N-1]+=b[0];
    add(a,c);
    int idx=0;
    while(a[idx]==0&&idx<N)idx++;
    if(idx==N)printf("0");
    else{
        while(idx<N)printf("%d",a[idx++]);
    }
    putchar('.');
    for(int i=1;i<=n;i++){
        printf("%d",b[i]);
    }
    putchar('\n');
}