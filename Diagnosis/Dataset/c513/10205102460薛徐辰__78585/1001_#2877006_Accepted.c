#include<stdio.h>
char ex(int a){
    char c;
    if(a<10)c='0'+a;
    else if(a>=10)c='A'+a-10;
    return c;
}

int main(){
    int n,N,R;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&N,&R);
        int i=0,a=abs(N);
        char c[100],str[100]={};
        while(a>0){
            int m=a%R;
            char s=ex(m);
            a=a/R;
            c[i]=s;
            i++;
        }
        for(int j=0;j<i;j++)str[j]=c[i-j-1];
        if(N>=0)printf("%s\n",str);
        else printf("-%s\n",str);
    }
 return 0;
}