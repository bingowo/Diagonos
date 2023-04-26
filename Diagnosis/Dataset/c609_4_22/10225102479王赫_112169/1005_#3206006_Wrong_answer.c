#include<stdio.h>
#include<stddef.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char a[50];
        scanf("%s\n",a);
        int len=sizeof(a)/sizeof(a[0]),r[T],t=0;
        for(len=len-1;len>=0;len--){
            for(t=0;t<len;t++){
               if(a[len]=='-') r[i]+=(-1)*pow(3,t);
               else if(a[len]=='1') r[i]+=pow(3,t);
               else r[i]=r[i];}
            }
        printf("case #%d:\n%d\n",i,r[i]);
    }
    return 0;
}