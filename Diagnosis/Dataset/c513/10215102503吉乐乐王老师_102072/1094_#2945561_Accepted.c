#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 120
void stoi(char s[],int a[]){
    int n=strlen(s)-1;
    int m=N;
    while(n>=0){
        if(s[n]=='-'){a[m]=-1;break;}
        a[m]=s[n]-'0';
        m--;n--;
    }
}
void add(int a[],int b[]){
    for(int i=N;i>0;i--){
        b[i]+=a[i];
        b[i-1]+=b[i]/10;
        b[i]%=10;
    }
}
void minus(int a[],int b[]){//a小，b大
    int idx=0;
    while(a[idx]==0)idx++;
    if(a[idx]==-1){
        a[idx]=0;
        add(a,b);
        return;
    }
    for(int i=N;i>0;i--){
        if(b[i]<a[i]){
            b[i]+=10;
            b[i-1]-=1;
        }
        b[i]-=a[i];
    }
}
int cmp(const void *a,const void *b){
    int *x=(int*)a;
    int *y=(int*)b;
    int lena=0,lenb=0;
    while(*x==0){x++;lena++;}
    while(*y==0){y++;lenb++;}
    if(*x==-1&&*y>0)return -1;
    if(*x>0&&*y==-1)return 1;
    if(*x==-1&&*y==-1){
        if(lena>lenb)return 1;
        if(lena<lenb)return -1;
        for(int i=lena;i<=N;i++){
            if(*x==*y){x++;y++;continue;}
            return *x>*y?-1:1;
        }
    }
    else{
        if(lena>lenb)return -1;
        if(lena<lenb)return 1;
        for(int i=lena;i<=N;i++){
            if(*x==*y){x++;y++;continue;}
            return *x>*y?1:-1;
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char s[50][121];
    int a[50][121]={0};
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        stoi(s[i],a[i]);
        getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    minus(a[0],a[n-1]);
    int idx=0;
    while(a[n-1][idx]==0)idx++;
    while(idx<=N)printf("%d",a[n-1][idx++]);
}