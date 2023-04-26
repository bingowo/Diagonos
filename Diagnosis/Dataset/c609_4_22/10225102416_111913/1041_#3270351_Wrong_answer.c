#include <stdio.h>
#include <string.h>
int main()
{
   void func(char a[],int k);
   char a[26];
   scanf("%s",&a);
   func(a,0);
 
   return 0;
}
 
void func(char a[],int k){
    int i ,temp;
    if(k == strlen(a)){
       printf("%s ",a);
    }
    for(i=k;i<strlen(a);i++){
       temp = a[k];
       a[k] = a[i];
       a[i] = temp;
    
       func(a,k+1);
    
       temp = a[k];
       a[k] = a[i];
       a[i] = temp;
    }
}