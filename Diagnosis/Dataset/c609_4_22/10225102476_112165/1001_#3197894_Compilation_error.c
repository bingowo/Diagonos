#include<stdio.h>
int main()
{
    int a=0;
    scanf("%d",&a);
    int i=0;
    while(i<a){
        int m,n=0;
        scanf("%d %d",&m,&n);
        char M[1000];
        int t=0;
        int c1=0;
        char c2;
        while (m!=0){
            c1=m%n;
            if(c1>=10)
              c2=c1-"10"+"A";
            else
              c2=c1+"0";
            M[-t]=c2;
            m=m/n;
        }
        printf("%s",M[]);
        printf("\n");
        i+=1;
    return 0;
}