#include<stdio.h>
#include<string.h>
#define L 500

int bigger(int *a,int*b){
    int i=0;
    while (i<L && a[i]==b[i]) i++;
    if(a[i]>b[i]) return 1;
    else if(a[i]<b[i]) return 0;
    else if(i==L) return 1;
}

void minus(int a[],int b[]){
    for(int i=L;i>0;i--){
        if(a[i]>=b[i]) a[i] -= b[i];
        else{
            a[i] = a[i]+10-b[i];
            a[i-1]--;
        }
    }
}

void output(int *a){
    int i=0;
    while (i<L && a[i]==0) i++;
    while (i<=L) printf("%d",a[i++]);
    printf("\n");
}

int main(){
    char a[L+1],b[L+1];
    while (scanf("%s %s",a,b)!=EOF){
        int a1[L+1]={0},b1[L+1]={0};
        int alen,blen;
        alen = strlen(a); blen = strlen(b);
        for(int i=alen-1,m=L;i>=0;i--,m--) a1[m]=a[i]-'0';
        for(int i=blen-1,m=L;i>=0;i--,m--) b1[m]=b[i]-'0';
        if(bigger(a1,b1)){
            minus(a1,b1);
            output(a1);
        } else{
            minus( b1,a1);
            printf("-");
            output(b1);
        }
    }
    return 0;
}