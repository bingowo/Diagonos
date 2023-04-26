#include<stdio.h>
int main(){
    int a,n,m,x,t=0;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    if(x==1||x==2||x==3)printf("%d",a);
    int s[21],ch[21],xi[21];
    s[1]=a;
    xi[1]=0;
    ch[1]=a;
    ch[2]=a;
    for(;t<=m;t++){
        s[2]=t;
        xi[2]=t;
        for(int i=3;i<=n-1;i++){
            s[i]=s[i-1]+s[i-2];
            xi[i]=s[i-1];
            ch[i]=s[i]-xi[i]+ch[i-1];
        }
        if(ch[n-1]==m)break;
    }
    if(x>3)printf("%d",ch[x]);
    return 0;
}


