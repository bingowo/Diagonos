#include<stdio.h>
#include<string.h>
#define N 2010

int main()
{
    char input[N];
    for(int i=0;i<N;++i)input[i]=0;
    scanf("%s",input);
    for(int i=0;i<strlen(input);++i){
        if(input[i]>='a')input[i]=input[i]-'a'+'A';
    }
    char temp[N];
    for(int i=0;i<N-1;++i)temp[i]='0';
    temp[N-1]='\0';
    int left=N/2;int right=left;
    temp[left]=input[0];
    for(int k=1;k<strlen(input);++k){
        if(input[k]>=temp[left]){
            temp[--left]=input[k];
        }
        else temp[++right]=input[k];
    }
    char ret[N];
    for(int i=0;i<N;++i)ret[i]='\0';
    int p=0;
    for(int i=left;i<=right;++i){
        ret[p++]=temp[i];
    }
    printf("%s",ret);
    return 0;
}
