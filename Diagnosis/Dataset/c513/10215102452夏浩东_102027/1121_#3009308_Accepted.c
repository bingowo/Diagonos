#include <stdio.h>
int add(int*L,int len){
    int left = 1;
    for(int i=len-1;i>=0;i--){
        int temp = L[i]+left;
        L[i] = temp%3;
        left = temp/3;
        if(left==0) break;
    }
    if(left==0) return 0;
    else return 1;
}
int fun(int*L,int len,int*ch){
    int res=0;
    for(int i=0;i<len;i++){
        if(ch[i]==1) res+=L[i];
        else if(ch[i]==2) res-=L[i];
    }
    return res;
}
int main()
{
    int num=0,max=0;
    int L[10],ch[10],RES[1000];
    scanf("%d",&num);
    for(int i=0;i<num;i++) {scanf("%d",&L[i]);max+=L[i];}
    for(int i=0;i<1000;i++) RES[i]=0;
    for(int i=0;i<num;i++) ch[i]=0;
    do{
    	if(fun(L,num,ch)>=1) RES[fun(L,num,ch)-1]=1;
    }while(add(ch,num)==0);
    for(int i=0;i<max;i++) printf("%d",RES[i]);
    return 0;
}