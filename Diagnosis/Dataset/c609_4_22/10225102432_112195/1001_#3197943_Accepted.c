#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   int n;
    scanf("%d",&n);
    int i;
    char s[38]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int m,r,y,j,l,t;
    char ans[200];
    for(i=0;i<n;i++){
       j=0;l=0;
       scanf("%d %d",&m,&r);
       if(m<0){
        printf("-");
        m=-m;
        j++;l=1;
       }
       while(m>0){
        y=m%r;
       ans[j++]=s[y];
       m/=r;
       }
       ans[j]='\0';
       for(t=j-1;t>=l;t--){
        printf("%c",ans[t]);
       }
       printf("\n");
    }
    return 0;
}
