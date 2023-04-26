#include <stdio.h>
#include <stdlib.h>

int check(int x){
    if (x==2) return 1;
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return 0;
    }
    return 1;
}

int ans[120]={0};
int cnt=0;

void multi(int x){
    for (int i=0;i<cnt;i++){
        ans[i]*=x;
    }
    for (int i=0;i<cnt;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    while (ans[cnt]!=0){
        ans[cnt+1]+=ans[cnt]/10;
        ans[cnt]=ans[cnt]%10;
        cnt++;
    }
}

void plus(int x){
    ans[0]+=x;
    for (int i=0;i<cnt;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    while (ans[cnt]!=0){
        ans[cnt+1]+=ans[cnt]/10;
        ans[cnt]=ans[cnt]%10;
        cnt++;
    }
}

int main()
{
    int prime[30];
    int num=1;
    for (int i=2;i<=100;i++){
        if (check(i)){
            prime[num++]=i;
        }
    }
    prime[0]=1;
    char st[123];
    int read[123];
    scanf("%s",st);
    num=0;
    for (int i=0;i<strlen(st);i++){
        if (st[i+1]!=',' && st[i+1]!='\0'){
            read[num++]=(st[i]-'0')*10+st[i+1]-'0';
            i+=1;
        }
        else read[num++]=st[i]-'0';
        i++;
    }
    for (int i=0;i<num;i++){
        multi(prime[num-i]);
        plus(read[i]);
    }
    for (int j=cnt-1;j>=0;j--){
        printf("%d",ans[j]);
    }
    printf("\n");
    return 0;
}
