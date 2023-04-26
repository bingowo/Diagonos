#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    long long int a=0;
    char s[51]={0};
    scanf("%s",s);
    int s1[51],s2[51];
    int j=0,i=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='I')s1[i]=1;
        else if(s[i]=='V')s1[i]=5;
        else if(s[i]=='X')s1[i]=10;
        else if(s[i]=='L')s1[i]=50;
        else if(s[i]=='C')s1[i]=100;
        else if(s[i]=='D')s1[i]=500;
        else if(s[i]=='M')s1[i]=1000;
        else s1[i]=-1;
    }
    int len=i;
    for(i=0;i<len;i++){
        if(s1[i]==-1)s2[j++]=-1;
        else{
            int num=0;
            while(s1[i]!=-1&&i<len){
                if(s1[i+1]>s1[i]&&i!=len-1)num-=s1[i];
                else num+=s1[i];
                i++;
            }
            s2[j++]=num;
            i--;
        }
    }
    long long int n=1;
    for(int k=0;k<j;k++){
        if(s2[k]!=-1&&s2[k+1]==-1&&n==1)s2[k]*=(-1);
        if(s2[k]==-1&&n==1){
            while(s2[k++]==-1)n*=1000;
            k--;
        }else if(s2[k]==-1){
            n/=1000;
            continue;
        }
        a+=s2[k]*n;
        
    }
    printf("%lld\n",a);
    return 0;
}
