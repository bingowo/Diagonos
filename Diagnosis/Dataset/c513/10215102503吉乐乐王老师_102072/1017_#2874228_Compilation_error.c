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
    int flag=0;
    if(n%2==1){flag=1;n=n-1;}
    int ret=0;
    for(int i=0,j=1;j<n;i++,j++){
        ret+=cal(trans(t[i]),trans(t[j]));
    }
    if(flag)ret+=trans(t[n]);
    print("%d",ret);
}
