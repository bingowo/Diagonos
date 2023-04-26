#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int GCD(int x,int y){
    int z=y;
    while(x%y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return z;
}

int main()
{
   char s[100];
   int a,i,r;
   int T;
   scanf("%d",&T);
   char g=getchar();
   for(int j=0;j<T;j++){
       i=0;
       r=0;
       while((scanf("%c",&s[i]))&&s[i]!='\n'){
            i++;
       }
       for(a=0;a<i;a++){
            int n=1;
            int b=0;
            while(b<8){
                if((s[a]&n)!=0){
                    r++;
                }
                n=n<<1;
                b++;
            }
       }
       int c;
       c=GCD(r,i*8);
       r=r/c;
       i=i*8/c;
       printf("%d/%d\n",r,i);




   }
   return 0;





}
