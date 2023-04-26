#include <stdio.h>

int main()
{
    int a[100],b[100];
    int t,i,j,f,l,r,n,x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&x,&y);
        f=0;
        n=0;
        x=x*10;
        for(j=0;j<100;j++)
            b[j]=-1;
        while(f==0&&x!=0){
            a[n]=x/y;
            n++;
            x=x%y;
            if(x!=0){
                if(b[x]==-1)
                    b[x]=n;
                else{
                    f=1;
                    l=b[x];
                    r=n;
                }
                x=x*10;
            }
        }
        printf("case #%d:\n",i);
        printf("0.");
        for(j=0;j<n;j++)
            printf("%d",a[j]);
        printf("\n");
        if(f==1)
            printf("%d-%d\n",l,r);
    }
    return 0;
}
