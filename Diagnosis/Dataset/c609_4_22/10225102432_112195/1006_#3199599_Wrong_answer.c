#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{   int t;
    scanf("%d",&t);
    int i,j;
    for(i=0;i<t;i++){
        int a[118],tot=0,ans=0;
        for (j=0;j<118;j++)
            a[j]=-1;
        char r[65];
        scanf("%s",r);
        int l;
        l=strlen(r);
        for(j=0;j<l;j++)
            if (a[r[j]]==-1){
                if(j==0) {a[r[i]]=1;tot++;}
                else if(j==1){
                    tot++;
                    a[r[j]]=0;
                }
                else{
                    tot++;
                    a[r[j]]=j;
                }
            }

        for(j=0;j<l;j++){
            ans=ans*tot+a[r[j]];
        }

        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
