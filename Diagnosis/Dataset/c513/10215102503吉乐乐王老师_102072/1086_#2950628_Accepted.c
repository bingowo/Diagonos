#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
int sign=1;
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
void judge(int a[],int b[],int c[],int d[]){
    int i=0,j=0;
    while(a[i]==0&&i<N)i++;
    while(c[j]==0&&j<N)j++;
    if(i==N&&j==N)return ;
    if(i<j)return ;
    if(j<i){sign=-1;return;}
    if(i==j){
        for(;i<N;i++,j++){
            if(a[i]>c[j])return ;
            if(a[i]<c[j]){sign=-1;return;}
        }
    }
    i=1,j=1;
    for(;i<N;i++,j++){
        if(b[i]>d[j])return ;
        if(b[i]<d[j]){sign=-1;return;}
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
void minus(int a[],int c[]){
    for(int i=N-1;i>0;i--){
        if(a[i]<c[i]){
            a[i]+=10;
            a[i-1]-=1;
        }
        a[i]-=c[i];
    }
}
int main(){
    int a[N]={0},b[N]={0},c[N]={0},d[N]={0};
    char *s1=(char*)malloc(sizeof(char)*N),*s2=(char*)malloc(sizeof(char)*N);
    scanf("%s",s1);getchar();
    get(s1,a,b);
    scanf("%s",s2);getchar();
    get(s2,c,d);
    int n;
    scanf("%d",&n);
    adjust(a),adjust(c);
    judge(a,b,c,d);
    if(sign==-1){
        d[0]+=1;c[N-1]-=1;
        minus(d,b);
        if(d[n+1]>4){
            d[n]+=1;
            for(int i=n;i>0;i--){
                d[i-1]+=d[i]/10;
                d[i]%=10;
            }
        }
        c[N-1]+=d[0];
        minus(c,a);
        int flag=0;
        putchar('-');
        for(int i=0;i<N;i++){
            if(c[i]!=0){
                while(i<N){
                    flag=1;
                    printf("%d",c[i++]);}
            }
        }
        if(flag==0) printf("0");
        putchar('.');
        for(int i=1;i<=n;i++)printf("%d",d[i]);
    }
    else{
        b[0]+=1;a[N-1]-=1;
        minus(b,d);
        if(b[n+1]>4){
            b[n]+=1;
            for(int i=n;i>0;i--){
                b[i-1]+=b[i]/10;
                b[i]%=10;
            }
        }
        a[N-1]+=b[0];
        minus(a,c);
        int flag=0;
        for(int i=0;i<N;i++){
            if(a[i]!=0){
                while(i<N){
                    flag=1;
                    printf("%d",a[i++]);}
            }
        }
        if(flag==0)printf("0");
        putchar('.');
        for(int i=1;i<=n;i++)printf("%d",b[i]);
    }
}
