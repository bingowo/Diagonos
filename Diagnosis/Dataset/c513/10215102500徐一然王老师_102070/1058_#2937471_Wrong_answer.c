#include <stdio.h>
#include <string.h>



int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
         if(c=='"')
         {
             printf("%c",c);
             while(1)
             {
                 c=getchar();
                 if(c!='"')
                 {
                     printf("%c",c);
                 }
                 else
                 {
                     break;
                 }

             }

         }

         if(c=='/')
         {
             c=getchar();
             if(c=='/')
             {
                 while(c!='\n')
                 {
                     c=getchar();
                 }
             }
             else if(c=='*')
             {
                 while(1)
                 {
                     c=getchar();

                     if(c=='*')
                     {
                         c=getchar();
                         if(c=='/')
                         {
                             c=getchar();
                             break;
                         }
                         else
                         {
                             printf("%c",c);
                         }
                     }
                 }

             }
         }

            printf("%c",c);
    }


    return 0;
}
