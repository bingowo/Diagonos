#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,j,l,k,m,x,n,a[60];
    scanf("%d",&t);
    char s[t][60];
    for (i=0;i<t;i++) scanf("%s",&s[i]);
    for(i=0;i<t;i++){
        a[0]=1;
        k=m=1;
        x=0;
        for(j=1;j<strlen(s[i]);j++){
            for(l=0;l<j;l++){
                if(s[i][j]==s[i][l]) {
                    a[j]=a[l];
                    break;}
            }
            if(l==j) {
                if(k==1) a[j]=k=0;
                else if(k==0) a[j]=k=2;
                else a[j]=(++k);
            }
        }
        if(k==0) k=2;
        else k++;
        for(j=strlen(s[i])-1;j>=0;j--){
            x=x+m*a[j];
            m=m*k;
        }
        printf("case #%d:\n%d\n",i,x);
    }
    return 0;
}