#include <stdio.h>
char t[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void g(char r[100],int c,int b,char u[100]){
    int j=0,d=0,m=0;
    while(r[j]!='\0'){

        if(c<10){
            m=r[j]-48;
        }
        else{
            if(r[j]<58){
                m=r[j]-48;
            }
            else if(r[j]<97){
                m=r[j]-(65-10);
            }
            else{
                m=r[j]-(65+32-10);
            }
        }
        d=d*c+m;
        j++;
    }
    int i=0;
    char s[100];
    while(d/b>0){
        s[i]=t[d%b];
        d=d/b;
        i++;
    }
    if(d/b==0) {
        s[i]=t[d%b];

    }
    int k,h;
    for(k=i,h=0;k>=0;k=k-1,h=h+1){
        u[h]=s[k];

    }


}
int main(){
    int l,n;
    char v[100];
    char w[100];
    scanf("%d %s %d",&l,v,&n);
    g(v,l,n,w);
    printf("%s",w);
    return 0;

}

