#include<stdio.h>
#include<string.h>

#define N 1005
#define M 1000000007

int main()
{
    char word[N];
    int p[N];
    for(int i=0;i<N;++i)word[i]=p[i]=0;
    scanf("%s",word);
    unsigned long long int ret=1,n=strlen(word);

    if(n==1){
        printf("1\n");
        return 0;
    }

    p[0]=(word[0]==word[1])?1:2;
    p[n-1]=(word[n-1]==word[n-2])?1:2;

    for(int i=1;i<n-1;++i){
        if(word[i]!=word[i-1]&&word[i]!=word[i+1])p[i]=3;
        if(word[i]==word[i-1]&&word[i]!=word[i+1])p[i]=2;
        if(word[i]!=word[i-1]&&word[i]==word[i+1])p[i]=2;
        if(word[i]!=word[i-1]&&word[i-1]==word[i+1])p[i]=2;
        if(word[i]==word[i-1]&&word[i]==word[i+1])p[i]=1;
    }

    for(int i=0;i<n;++i)
    {
        ret*=p[i];
        ret%=M;
    }
    ret%=M;
    printf("%d\n",ret);
    return 0;
}
