#include<stdio.h>
void main()
{
    int a=0;
    scanf("%d",&a);
    int i=0;
    while(i<a){
        int m,n=0;
        scanf("%d %d",&m,&n);
        char M[1000];
        int t=0;
        int c=0;
        while (m!=0){
            c=m%n;
            if(c>=10)
              M[-t]=c-10+"A";
            else
              M[-t]=c+"0";
            m=m/n;
        }
        printf("%c",M[]);
        printf("\n");
        i=i+1;
    }
}