#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char *s1,char *s2,char *ans1) //加法函数
{
    int len1=strlen(s1),len2=strlen(s2);
    int a=len1<len2 ? len1 : len2;
    int b=len1>len2 ? len1 : len2;
    int i=0,next=0,sum=0;
    for(;i<a;i++){
        sum=next+s1[i]-'0'+s2[i]-'0';
        if(sum>=10){
            next=1;
            ans1[i]='0'+sum-10;
        }
        else {
            next=0;
            ans1[i]='0'+sum;
        }
    }
    for(;i<b;i++){
        if(len1>len2) sum=next+s1[i]-'0';
        else sum=next+s2[i]-'0';
        if(sum>=10){
            next=1;
            ans1[i]='0'+sum-10;
        }
        else {
            next=0;
            ans1[i]='0'+sum;
        }
    }
    if(next==1){
        next=0;
        ans1[i]='1';
        i++;
    }
    ans1[i]=0;
}

void mult(char* s,int x,char *ans)  //乘法函数
{
    int i=0,len=strlen(s),next=0,current=0;
    int j=0,k=0,one=x%10,ten=x/10;
    char a1[50],a2[50];
    a2[0]='0';
    if(x<10){
        for (;i<len;i++){
            current=(x*(s[i]-'0')+next)%10;
            next=(x*(s[i]-'0')+next)/10;
            ans[i]=current+'0';
        }
        if(next>0) {ans[i]='0'+next;i++;}
        ans[i]=0;
    }
    else {
        for(;j<len;j++){
            current=(one*(s[j]-'0')+next)%10;
            next=(one*(s[j]-'0')+next)/10;
            a1[j]=current+'0';
        }
        if(next>0) {a1[j]='0'+next;j++;}
        a1[j]=0;
        for(;k<len;k++){
            current=(one*(s[k]-'0')+next)%10;
            next=(one*(s[k]-'0')+next)/10;
            a2[k+1]=current+'0';
        }
        if(next>0) {a2[k+1]='0'+next;k++;}
        a2[k+1]=0;
        add(a1,a2,ans);
    }
}

int main()
{
    char s0[100];
    scanf("%s",s0);
    int arr0[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int len=strlen(s0);
    int arr1[25];
    int len1=0;
    int x=1,sum=0;
    for(int j=len-1;j>=0;j--){
        if(s0[j]-'0'<=9&&s0[j]-'0'>=0){
            sum+=x*(s0[j]-'0');
            x*=10;
        }
        else{
            arr1[len1]=sum;
            len1++;
            sum=0;
            x=1;
        }
    }
    arr1[len1]=sum;
    len1++;
    char an[50];
    char z[50];
    char an1[50];
    z[0]='1';
    z[1]=0;
    an[0]='0';
    an[1]=0;
    for (int i=0;i<len1;i++){
        mult(z,arr1[i],an1);
        add(an1,an,an);
        mult(z,arr0[i],z);
    }
    int e=strlen(an)-1;
    if(strlen(an)==1&&an[e]=='0') printf("0");
    while(an[e]=='0') e--;
    for(;e>=0;e--) printf("%c",an[e]);
    return 0;
}
