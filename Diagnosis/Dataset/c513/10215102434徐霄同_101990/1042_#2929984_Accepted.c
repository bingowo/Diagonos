#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    char s[17],s0[17];
    char ans[65536][17];
    int a[127];
    int t,i,j,k,k0,l,l0,x,j0;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        memset(a,0,sizeof(a));
        for(j=0;j<l;j++)
            a[s[j]]++;
        l0=0;
        for(j=0;j<128;j++)
            if(a[j]>0){
                s0[l0]=j;
                l0++;
            }
        x=1;
        for(j=0;j<l0;j++)
            x=x*2;
        for(j=1;j<x;j++){
            j0=j;
            k=0;
            k0=0;
            while(j0>0){
                if(j0%2==1){
                    ans[j-1][k]=s0[k0];
                    k++;
                }
                k0++;
                j0=j0/2;
            }
            ans[j-1][k]=0;
        }
        qsort(ans,x-1,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<x-1;j++)
            printf("%s\n",ans[j]);
    }
    return 0;
}
