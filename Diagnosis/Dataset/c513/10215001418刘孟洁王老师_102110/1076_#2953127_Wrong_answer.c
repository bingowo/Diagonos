#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[107];int k;

void judge(int n)
{
    if(n == 0){printf("Yes\n");return;}
    else{
    switch(s[n-1])
    {
      case ')':{
          if(s[n] == ']'||s[n] == '{'||s[n] == '('||s[n] == '[')k = 1;
          else k = 0;}break;
      case ']':{
          if(s[n] == '}'||s[n] == '{'||s[n] == '('||s[n] == '[')k = 1;
          else k = 0;}break;
      case '}':{
          if(s[n] == ')'||s[n] == '{'||s[n] == '('||s[n] == '[')k = 1;
          else k = 0;}break;
      case '(':{
          if(s[n] == '{'||s[n] == ')')k = 1;
          else k = 0;}break;
      case '[':{
          if(s[n] == '('||s[n] == ']')k = 1;
          else k = 0;}break;
      case '{':{
          if(s[n] == '}'||s[n] == '[')k = 1;
          else k = 0;}break;
   }
   if(k)judge(n-1);
   else {printf("No\n");return;}
   }
}


int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        scanf("%s",s);
        int m = strlen(s)-1;
        judge(m);
        n--;

    }
    return 0;
}
