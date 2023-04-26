#include <stdio.h>
#include <math.h>
char key[]="0123456789ABCDEFG";

void f(int n,int r)
{
    if(n>0){
        f(n/r,r);
        printf("%c",key[n%r]);
    }
}

int main()
{
        int r;
        scanf("%d",&r);
        getchar();
        char c;
        int ans=0,temp;
        while((c=getchar())!=' '){
              temp=c-'0';
              if(c>='a'&&c<='g')temp=temp-17-32+10;
              else if(c>='A'&&c<='G')temp=temp-17+10;
              ans=ans*r+temp;
        }
        scanf("%d",&r);
        f(ans,r);
    return 0;
}
