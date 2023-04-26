#include<stdio.h>
int main(){
    int n,m,a,b,c,wa,wb,la,lb;
    scanf("%d %d",&n,&m);
    int s[m+1],n[m+1];
    for(int i=0;i<m+1;i++)n[i]=i;
    for(int i=0;i<m+1;i++)s[i]=0;
    while(m>1){
        scanf("%d %d %d",&a,&b,&c);
        if(c==1){s[a]+=3;s[b]--;wa++;lb++}
        if(c==-1){s[b]+=3;s[a]--;wb++;la++}
        if(c==0){s[a]++;s[b]++;}
    }
    
}