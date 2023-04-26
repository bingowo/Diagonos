#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 2000
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
void judge(char *s1,char *s2){
    while(*s1=='0')s1++;
    while(*s2=='0')s2++;
    int p1=0,p2=0;
    while(s1[p1]!='.'&&s1[p1])p1++;
    while(s2[p2]!='.'&&s2[p2])p2++;
    if(p2>p1){
        sign=-1;return;}
    if(p1==p2){
        for(int i=0;i<p1;i++){
            if(s1[i]>s2[i])return;
            if(s2[i]>s1[i]){sign=-1;return;}
        }
    }
    p1++;p2++;
    while(s1[p1]&&s2[p2]){
        if(s1[p1]>s2[p2])return;
        if(s2[p2]>s1[p1]){sign=-1;return;}
        p1++;p2++;
    }
}
void adjust(int a[]){
    int idx=N-1;
    while(a[idx]!=-1&&idx>0)idx--;
    if(idx==0)return ;
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
    judge(s1,s2);
    adjust(a),adjust(c);
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
