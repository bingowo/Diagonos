#include <stdio.h>
int main()
{
        int a,b;
        scanf("%d%d",&a,&b);
        int s[1000];
        int i=0;
        if(a%b<0){
            s[i]=a-(a/b+1)*b;
        }
        else{
            s[i]=a%b;
        }
        while(a){
            if(a%b<0)a=a/b+1;s[i++]=a-(a/b+1)*b
            else a/=b;s[i++]=a%b;
          }
          for(i;i>=0;i--)printf("%X",s[i]);
          return 0;
}