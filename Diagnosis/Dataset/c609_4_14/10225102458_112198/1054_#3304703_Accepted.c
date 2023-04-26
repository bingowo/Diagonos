#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int* a,int b)
{
    for(int i=0;i<349;i++){
        if(i==0)a[i]+=b;
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }

}
void mul(int* a)
{
    for(int i=0;i<350;i++){a[i]*=2;}
    for(int i=0;i<349;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
}
int main()
{
    char m[110];
    int dec[350],bin[350];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    scanf("%s",m);
    int len=strlen(m);
    int num[len];
    memset(num,0,sizeof(num));
    memset(bin,0,sizeof(bin));
    for(int i=0;i<len;i++)num[i]=m[i]-'0';
    int p,bet,flag=1,cnt=0;
    while(flag){
        flag=0,p=0;
        for(int i=0;i<len;i++){
        bet=p*10+num[i];
        num[i]=bet/2;
        p=bet%2;
    }
    for(int i=0;i<len;i++){if(num[i]){flag=1;break;}}
    dec[cnt++]=p;}
    int ddec[cnt];
    for(int i=0;i<cnt;i++)ddec[cnt-1-i]=dec[i];
    for(int i=cnt-1;i>=0;i--){
        mul(bin);
        add(bin,ddec[i]);
    }
    int begin=349;
    while(bin[begin]==0&&begin>0){begin--;}
    printf("case #%d:\n",i);
    for(int i=begin;i>=0;i--)printf("%d",bin[i]);
    printf("\n");}
    return 0;
}
