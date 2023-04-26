#include <stdio.h>
#include <string.h>

int main()
{
    int t,x,i,j,l,k;
    scanf("%d",&t);
    char s[t][50];
    for(i=0;i<t;i++) scanf("%s",&s[i]);
    for(i=0;i<t;i++){
        x=0;
        k=1;
        l=strlen(s[i]);
        for(j=l-1;j>=0;j--){
            if(s[i][j]=='1') x=x+k;
            else if(s[i][j]=='-') x=x-k;
            k=k*3;
        }
        printf("case #%d:\n%d\n",i,x);
    }
    return 0;
}
