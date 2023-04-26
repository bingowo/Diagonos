#include<stdio.h>
int main(){
    int m,n,a[200][200],line=0,row=0,p=0;
    char s[400];
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++)scanf("%d",&a[i][k]);
    }
    long long int sum=a[0][0];
    while(line!=m-1&&row!=n-1){
        if(a[line+1][row]>a[line][row+1]){sum+=a[line][row+1];row++;s[p++]='R';}
        else{sum+=a[line+1][row];line++;s[p++]='D';}
    }
    while(row==n-1&&line!=m-1){
        sum+=a[++line][n-1];
        s[p++]='D';
    }
    while(line==m-1&&row!=n-1){
        sum+=a[m-1][++row];
        s[p++]='R';
    }
    s[p]=0;
    printf("%lld\n%s",sum,s);
    return 0;
}