#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
int main()
{
   char c;
   int state=0;
   while((c=getchar())!=EOF)
   {
       switch(state)
       {
           case 0:if(c=='/')state=1;
                    else {printf("%c",c);if(c=='"')state=5;if(c=='\'')state=6;}
                    break;
           case 1:if(c=='*')state=2;
                   else if(c=='/')state=4;
                   else {printf("/%c",c);state=0;}
                   break;
           case 2:if(c=='*')state=3;
                    break;
           case 3:if(c=='/')state=0;
                    else if(c!='*')state=2;
                    break;
           case 4:if(c=='\n'){printf("%c",c);state=0;}
                    break;
           case 5:if(c=='\\'){printf("%c",c);c=getchar();printf("%c",c);break;}
                   else if(c=='"')state=0;
                    printf("%c",c);
                    break;
           case 6:if(c=='\\'){printf("%c",c);c=getchar();printf("%c",c);break;}
                    else if(c=='\'')state=0;
                    printf("%c",c);
                    break;
       }
   }
   return 0;
}
