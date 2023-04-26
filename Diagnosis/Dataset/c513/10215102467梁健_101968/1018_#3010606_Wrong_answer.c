#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int s[26],k=0;
    char c;
    do{
        scanf("%d",&s[k++]);
    }while(c=getchar()==',');
    int num[26],t=1;
    num[0]=2;
    for(int i=3;t<26;i+=2){
            int flag=0;
        for(int j=1;j<sqrt(i)+1;j++){
            if(i%j==0)flag++;
        }
        if(flag<2)num[t++]=i;
    }
    int cnt[26];
    for(int i=0;i<26;i++){
            cnt[i]=1;
        for(int j=0;j<i;j++){
            cnt[i]=cnt[i]*num[j];
        }
    }
    unsigned long long res=0;
    int j=0;
    for(int i=k-1;i>=0;i--){
        res+=s[i]*cnt[j++];
    }
    printf("%llu",res);
}
