#include<stdio.h>
int main()
{
    int a=0;
    scanf("%d",&a);
    int i=0;
    while(i<a){
        int m,n=0;
        scanf("%d %d",&m,&n);
        char s[];
        int t=0;
        char c=0;
        while (m!=0){
            c=m%n;
            if(c>=10)
              c=c-"10"+"A";
            s[-t]=c;
            m=m/n;
        }
        printf("%s",s\n);
        i+=1;
    }
}