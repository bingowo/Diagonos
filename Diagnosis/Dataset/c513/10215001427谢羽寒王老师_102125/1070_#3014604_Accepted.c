#include <stdio.h>

int main()
{
    int c,i,r;

    while(scanf("%d",&c)!=EOF && c!=-1){

   if(c==1){r=2;}
   if(c==2){r=4;}
   if(c==3){r=7;}
   if(c>3){ r=count(c);}
printf("%d\n",r);
    }


}

int count (int n)
{
    int a=2,b=4,c=7,i,t=0;
    for(i=0;i<n-3;i++){
        t=a-b+2*c;
        a=b;
        b=c;
        c=t;

    }
    return t;
}
