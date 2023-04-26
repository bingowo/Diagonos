#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30

void reverse(char* s){
    int l=strlen(s);
    for(int i=0,j=l;i<j;++i,--j){
        char temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127};
int main(){
    int T,x=0;
    scanf("%d\n",&T);
    //素数表
    
    while(x<T){
        char input1[N]={'\0'};char input2[N]={'\0'};
        int ans[N];for(int i=0;i<N;++i)ans[i]=0;
        scanf("%s %s",input1,input2);
        reverse(input1);reverse(input2);
        int temp1[N],temp2[N];
        for(int i=0;i<N;++i)temp1[i]=temp2[i]=0;
        for(int i=0,j=0;i<strlen(input1);i+=2,j++)temp1[j]=input1[i]-'0';
        for(int i=0,j=0;i<strlen(input2);i+=2,j++)temp2[j]=input2[i]-'0';
        int jin[N*2];for(int i=0;i<N*2;++i)jin[i]=0;
        for(int i=0;i<N-1;++i){
            if(temp1[i]+temp2[i]+jin[i]>=prime[i]){
                ans[i]=temp1[i]+temp2[i]-prime[i];
                jin[i+1]=(temp1[i]+temp2[i]+jin[i])/prime[i];
            }
            else{
                ans[i]=temp1[i]+temp2[i]+jin[i];
            }
        }
        int sign;
        for(int k=N-1;k>=0;--k){
            if(ans[k]!=0){
                sign=k;break;
            }
        }
        printf("case #%d:\n",x++);
        for(int k=sign;k>-1;--k)printf("%d%c",ans[k],k=0?'\n':',');
    }
    return 0;

}