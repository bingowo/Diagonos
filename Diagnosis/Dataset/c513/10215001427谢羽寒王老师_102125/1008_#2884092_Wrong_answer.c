#include<stdio.h>
#include<string.h>

int main()
{
    int n,N=100;
    int i,j,x,y,result,k,l,c;
    int a[N],b[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        result=0;
        if(x==0){a[0]=0;}
        else{ for(i=0;x>0;i++){
            a[i]=x%2;
            x=x/2;
        }}

        if(y==0) b[0]=0;
       else{
            for(j=0;y>0;j++){
            b[j]=y%2;
            y=y/2;
        }}

        for(c=0,k=0;k<i && k<j;k++){
            if(a[k]!=b[k]) c++;
        }



















        printf("%d\n",c);
    }






   return 0;
}
