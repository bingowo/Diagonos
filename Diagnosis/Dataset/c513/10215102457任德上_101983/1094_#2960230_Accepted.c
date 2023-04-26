#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct{
    int cnt,v[500],flag;
}BigInt;
BigInt Int2Big(int a){
    BigInt r={0,{0}};
    do{
        r.v[r.cnt++]=a%10;
        a/=10;
    }while(a>0);
    return r;
}
BigInt sub(BigInt a,BigInt b){    //默认a大b小
    int i=0;
    while(i<a.cnt||i<b.cnt){
        if(a.v[i]>=b.v[i])a.v[i]-=b.v[i];
        else{
            a.v[i+1]--;
            a.v[i]=a.v[i]+10-b.v[i];
        }
        i++;
    }
    while(a.v[a.cnt-1]==0&&a.cnt>1)a.cnt--;
    return a;
}
BigInt add(BigInt a,BigInt b){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]+=b.v[i];
        a.v[i+1]+=a.v[i]/10;
        a.v[i]%=10;
        i++;
    }
    a.cnt=i+1;
    while(a.v[a.cnt-1]==0)a.cnt--;
    return a;
}
int compare(const void *a,const void *b){    //升序排列
    BigInt m,n;
    m=*(BigInt*)a;
    n=*(BigInt*)b;
    if(m.flag==1&&n.flag==-1)return 1;
    if(m.flag==-1&&n.flag==1)return -1;
    if(m.flag==1&&n.flag==1){
        if(m.cnt>n.cnt)return 1;
        else if(m.cnt<n.cnt)return -1;
        else{
            for(int i=m.cnt-1;i>=0;i--){
                if(m.v[i]>n.v[i])return 1;
                else if(m.v[i]<n.v[i])return -1;
            }
            return 0;
        }
    }
    if(m.cnt>n.cnt)return -1;
    else if(m.cnt<n.cnt)return 1;
    else{
        for(int i=m.cnt-1;i>=0;i--){
            if(m.v[i]>n.v[i])return -1;
            else if(m.v[i]<n.v[i])return 1;
        }
        return 0;
    }
}
BigInt transform(char *s){
    BigInt a;
    int len=strlen(s);
    if(*s=='-'){
        a.cnt=len-1;
        a.flag=-1;
        for(int i=len-1,k=0;i>0;i--,k++)a.v[k]=*(s+i)-'0';
    }
    else{
        a.cnt=len;
        a.flag=1;
        for(int i=len-1;i>=0;i--)a.v[len-i-1]=*(s+i)-'0';
    }
    return a;
}
int main(){
    int n;
    scanf("%d",&n);
    BigInt *a,c={0,{0}};
    a=(BigInt*)malloc(50*sizeof(BigInt));
    char s[150];
    for(int i=0;i<n;i++){
        scanf("%s",s);
        a[i]=transform(s);
    }
    qsort(a,n,sizeof(BigInt),compare);
    for(int i=a[0].cnt;i<=499;i++)a[0].v[i]=0;
    for(int i=a[n-1].cnt;i<=499;i++)a[n-1].v[i]=0;
    c.flag=1;
    if(a[0].flag==1&&a[n-1].flag==1)c=sub(a[n-1],a[0]);
    else if(a[0].flag==-1&&a[n-1].flag==-1)c=sub(a[0],a[n-1]);
    else c=add(a[n-1],a[0]);
    for(int k=c.cnt-1;k>=0;k--)printf("%d",c.v[k]);
    free(a);
    return 0;
}