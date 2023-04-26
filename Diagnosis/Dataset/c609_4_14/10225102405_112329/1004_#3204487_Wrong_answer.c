#include<stdio.h>
int main()
{
    int A,B,output=0,i,x,k=0;
    char n[100],num[100]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",out[100];
    scanf("%d%s%d",&A,&n,&B);
    for(i=0;i<strlen(n);i++){
        output*=A;
        if (n[i]>=97){output+=n[i]-87;}
        else if(n[i]>=65){output+=n[i]-55;}
        else {output+=n[i]-48;}
    }
    while(output!=0){
        x=output%B;
        output/=B;
        out[k]=num[x];
        k++;
    }
    for (i=k-1;i>=0;i--){
        printf("%c",out[i]);
    }
    return 0;

}


