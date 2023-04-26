#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int N,R;
    scanf("%d%d",&N,&R);
    int n=N;
    int i=0;
    char s[100]={};
    if(n==0) printf("0");
    while(n!=0)

       {

           int r=n%R;
           int y=(r>=0)?r:(abs(R)+r);
           if(y<10) {s[i]=y+'0';i++;}
           else {s[i]=y-10+'A';i++;}
           n/=R;
           if(r<0) n++;
       }
       for(int k=i-1;k>=0;k--)
        printf("%c",s[k]);

    return 0;
}