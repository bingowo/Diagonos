#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readnumber(char x[],int y[]){
    int index = 0;
    for(int i=0;i<=strlen(x);i++){
        if(x[i]>='0' && x[i]<='9'){
            y[index] = y[index]*10+(x[i]-'0');
        }else{
            index++;
        }
    }
    y[index] = -1;
}
void ADD(int a[],int b[],int c[]){
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    long long sum = 0,n=1;
    int index = 25;
    int i = 25;
    while(a[i]!=-1){
        i--;
    }
    i--;
    for(;i>=0;i--){
        sum += n*a[i];
        n*=prime[index--];
    }
    index = 25;
    i = 25;
    n=1;
    while(b[i]!=-1){
        i--;
    }
    i--;
    for(;i>=0;i--){
        sum += n*b[i];
        n*=prime[index--];
    }
    index = 25;
    i = 0;
    while(sum>0){
        c[i++]=sum%prime[index];
        sum /= prime[index--];
    }
    c[i]=-1;
}
void output(int a[]){
    int i = 25;
    while(a[i]!=-1){
        i--;
    }
    i--;
    for(;i>=0;i--){
        if(i == 0)printf("%d\n",a[i]);
        else printf("%d,",a[i]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;

}
