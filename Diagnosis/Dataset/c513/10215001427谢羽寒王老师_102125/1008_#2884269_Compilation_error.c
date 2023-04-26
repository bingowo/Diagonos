#include<stdio.h>
#include<string.h>

int main()
{
    int n,N=100;
    int i,j,x,y,result,k,l,c,d,z;
    int a[N],b[N];
    scanf("%d",&n);
    for(d=0;d<n;d++){
        scanf("%d %d",&x,&y);
        result=0;
        if(x==0){a[0]=0;i=1;}
        else{ for(i=0;x>0;i++){
            a[i]=x%2;
            x=x/2;
        }}

        if(y==0) {b[0]=0;j=1;}
       else{
            for(j=0;y>0;j++){
            b[j]=y%2;
            y=y/2;
        }}
        if(i>j) {
                for(l=j;l<i;l++){
                    a[l]=0;
                }
            z=i
        }
        else { 
                for(l=i;l<j;l++){
                    a[l]=0;
                }
            z=j
        }

        for(c=0,k=0;k<z;k++){
            if(a[k]==b[k]) c++;


        }
        result=z-c;

        printf("%d\n",result);
    }






   return 0;
}
