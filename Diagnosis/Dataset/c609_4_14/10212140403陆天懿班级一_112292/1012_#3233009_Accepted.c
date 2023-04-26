#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

int n=200;
char str[200];
int num[200]={};
int add[200]={1,2,5};

void Init(){
    for(int i=0;i<n;i++)
        num[i]=add[i]=0;
    add[0]=1;
    add[1]=2;
    add[2]=5;
}

void Div8(){
    for(int i=0,t=0;i<n;i++){
        add[i]+=t*10;
        t=add[i]%8;
        add[i]/=8;
    }
}

void Add(){
    for(int i=n-1,t=0;i>=0;i--){
        num[i]+=add[i]+t;
        t=num[i]/10;
        num[i]%=10;
    }
}

void Print(int cnt){
    printf("case #%d:\n0.", cnt);
    int len=n-1;
    while(num[len]==0) len--;
    for(int i=0;i<=len;i++)
        printf("%d",num[i]);
    printf("\n");
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        Init();
        scanf("%s",str);
        for(int i=2;str[i]!='\0';i++){
            for(int j=0;j<str[i]-'0';j++)
                Add();
            Div8();
        }
        Print(cnt);
    }

    return 0;
}
