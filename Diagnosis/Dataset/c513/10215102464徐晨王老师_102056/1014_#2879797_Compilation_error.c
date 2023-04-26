#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(){
    int A,B;
    scanf("%d",&A,&B);
    char a[100];
    for(int i;A;i++){
        a[i]=A%3-1;
        if(a[i]==-1)a[i]=2;
        A=A/3;
    }
    
    int j;
    for(j=0;B;j++){
        B=B/3;
    }
    
    int c=strlen(a);
    char d[100];
    int m=0;
    for(m=0;a[m]==0;m++);
    int n=b-m;
    for(int i=0;m<b;m++,i++){
        d[i]=a[b-1-i];
    }
    
    char b[100];
    int m1=0;
    for(m1=0;d[m1]==0;m1++);
    for(int i=0;m1<n;m1++,i++){
        b[i]=d[n-1-i];
    }
    
    /*if(j!=0){
    int k;
    for(k=0;k<(b-j);k++){
        b[k]=a[b-k-1];
    }
    b[k+1]='.';
    for(;k<b+1;k++){
        b[k]=a[b-k];
    }
    }*/
    
}