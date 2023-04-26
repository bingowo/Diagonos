#include<stdio.h>
#include<stdlib.h>

int main()
{ int n,i,size_; char s[120];int a[120];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%s",s);
   unsigned char* p =(unsigned char*)s;
   size_=sizeof(s); int b=size_-1;
   while(b)
   {;
    printf("%02x ",*p++)
    b--; 
    
   }

  }
    
 return 0;   
}