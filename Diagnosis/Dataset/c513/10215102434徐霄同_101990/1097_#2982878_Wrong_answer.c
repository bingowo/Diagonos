#include <stdio.h>
#include <string.h>

int main()
{
    char s[81];
    int ls[80],ln[80];
    int l,i,j,n;
    while(scanf("%s",s)!=EOF){
        l=strlen(s);
        ls[0]=1;
        for(i=1;i<l;i++){
            if(s[i]>s[i-1]){
                if(ls[i-1]>1)
                    ls[i]=ls[i-1]-1;
                else{
                    for(j=0;j<i;j++)
                        ls[j]++;
                    ls[i]=1;
                }
            }
            else if(s[i]<s[i-1])
                ls[i]=ls[i-1]+1;
            else
                ls[i]=ls[i-1];
        }
        memset(ln,0,sizeof(ln));
        n=1;
        for(i=0;i<l;i++){
            if(ln[ls[i]]==0)
                n++;
            ln[ls[i]]++;
        }
        for(i=1;i<=n;i++)
            for(j=0;j<l;j++){
                if(ls[j]==i){
                    printf("%c",s[j]);
                    ln[i]--;
                    if(ln[i]==0){
                        printf("\n");
                        break;
                    }
                }
                else
                    printf(" ");
            }
    }
    return 0;
}
