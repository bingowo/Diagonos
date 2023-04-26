#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{   int n;
    scanf("%d",&n);
    int i,j,t;
    char s[38]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i=0;i<n;i++){
       int m,r,y,j=0,l=0;
       char ans[200];
       scanf("%d %d",&m,&r);
       if(m<0){
        printf('-');
        m=-m;
        j++;l=1;
       }
       while(m>0){
        y=m%r;
       ans[j++]=s[y];
       m/=r;
       }
       ans[j]='\0';
       for(int t=j-1;t>=l;t--){
        printf("%c",ans[t]);
       }
       printf('\n');
    }
    return 0;
}