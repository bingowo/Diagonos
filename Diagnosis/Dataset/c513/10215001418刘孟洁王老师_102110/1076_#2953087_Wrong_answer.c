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
        int s1 = 0,ss1 = 0,s2 = 0,ss2 = 0,s3 = 0,ss3 = 0;
        scanf("%s",s);
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '(')s1++;
            if(s[i] == '[')s2++;
            if(s[i] == '{')s3++;
            if(s[i] == ')')ss1++;
            if(s[i] == ']')ss2++;
            if(s[i] == '}')ss3++;
        }
        if(s1 != ss1||s2 != ss2||s3 != ss3){printf("No\n");return 0;}
        else{
        int m = strlen(s) - 1;
        judge(m);
        n--;
      }
    }
    return 0;
}
