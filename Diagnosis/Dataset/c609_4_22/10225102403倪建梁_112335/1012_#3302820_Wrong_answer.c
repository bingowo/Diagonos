#include <stdio.h>
#include<string.h>
int main(){
    char a[105]={0},b[305]={0};
    int t,len,m,tmp,i,j,k;
    scanf("%d\n",&t);
    for(i=0;i<t;i++){
        gets(a);
        len=strlen(a);
        m=0;
        for(j=len-1;j>=2;j--){
            int n=a[j]-'0';
            for(k=0;k<m||n;k++){
                tmp=10*n + (k<m ? b[k]-'0' : 0);
                b[k]=tmp/8 + '0';
                n=tmp%8;
            }
            m = k;       
        }
        printf("case #%d:\n0.%s\n",i,b);
    }
    return 0;
}
