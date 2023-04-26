#include<stdio.h>
int main(){
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
     int M;
     scanf("%d",&M);
     int w,x,y,z,sum=0;
     
  for(int w=0;w<=M/4;w++)
            for(int x=0;x<=M/3;x++)
                for(int y=0;y<=M/2;y++)

        {
            if(4*w+3*x+2*y<=M)
                sum++;
        }
  printf("%d\n",sum);
 }
return 0;
}