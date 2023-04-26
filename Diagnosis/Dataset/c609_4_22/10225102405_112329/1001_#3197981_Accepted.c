#include<stdio.h>
int main()
{
    int T,N[100],R[100],i,j,a,b,k[100];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d%d",&N[i],&R[i]);
    }
    char Num[10000]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[T][32];
    for(i=0;i<T;i++){
        a=N[i];
        j=0;
        k[i]=0;
        if (a<0) {
            a*=(-1);
        }
        while (a!=0){
            b=a%R[i];
            a/=R[i];
            output[i][j]=Num[b];
            j++;
            k[i]+=1;
        }
    }
    for (i=0;i<T;i++){
        if(N[i]<0){printf("-");}
        j=k[i];
        j--;
        while(j>=0){
            printf("%c",output[i][j]);
            j--;
        }
        printf("\n");
    }
}
