#include<stdio.h>
#include<string.h>
int trans(char a){
    if(a=='I')return 1;
    if(a=='V')return 5;
    if(a=='X')return 10;
    if(a=='L')return 50;
    if(a=='C')return 100;
    if(a=='D')return 500;
    if(a=='M')return 1000;
}
int cal(char x,char y){
if(x>=y){
        return x+y;
}
if(x<y){
    if(x==1||x==10||x==100)return y-x;
}
return 0;
}
int main(){
char t[100];
scanf("%s",t);
int n=strlen(t);
    int ret=0;
    int i;
    for(i=1;i<n;){
        int flag=0;
        while(t[i]&&t[i]==t[i-1]){flag++;i++;}
        if(flag){ret+=(flag+1)*trans(t[i-1]);continue;}
        ret+=cal(trans(t[i]),trans(t[i-1]));
        i+=2;
    }
    if(i==n+1)ret+=trans(t[n-1]);
    printf("%d",ret);
}

