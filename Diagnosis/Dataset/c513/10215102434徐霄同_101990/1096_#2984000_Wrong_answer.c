#include <stdio.h>

int main()
{
    int t,n,i,j,k,f,p;
    int a[100],b[100];
    int num[101];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=1;j<=100;j++)
            num[j]=0;
        for(j=0;j<n;j++){
            scanf("%d%d",&a[j],&b[j]);
            num[a[j]]++;
        }
        for(j=0;j<n;j++)
            for(k=0;k<n;k++){
                p=0;
                if(a[j]==a[k]&&b[j]==b[k]){
                    if(j<k)
                        p++;
                    else if(j>k+1)
                        p--;
                }
                num[a[j]]-=p;
            }
        f=0;
        for(j=1;j<=100;j++)
            if(num[j]>1)
                f=1;
        for(j=0;j<n;j++)
            if(num[b[j]]>0)
                f=1;
        if(f==0)
            printf("Lucky dxw!\n");
        else
            printf("Poor dxw!\n");
    }
    return 0;
}
