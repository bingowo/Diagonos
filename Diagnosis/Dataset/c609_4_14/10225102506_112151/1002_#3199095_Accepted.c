#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,temp,cnt,cn,s[10][100];
    int i,j,len;
    scanf("%d",&T);
    int n[T];
    for(i=0;i<T;i++){
        scanf("%d",&n[i]);
    }
    for(i=0;i<T;i++){
        len=0;
        while(n[i]){
            temp=n[i]%2;
            n[i]/=2;
            s[i][len++]=temp;
        }
        cnt=1;
        for(j=0;j<len-1;j++){
            cn=1;
            if(s[i][j]==s[i][j+1])
                cn=1;
            else{
                while(s[i][j+cn]!=s[i][j+cn-1]&&(j+cn<=len-1)){
                    cn++;
                }
            }
            if(cn>cnt)
                cnt=cn;
        }
        printf("case #%d:\n%d\n",i,cnt);
     }
    return 0;
}
