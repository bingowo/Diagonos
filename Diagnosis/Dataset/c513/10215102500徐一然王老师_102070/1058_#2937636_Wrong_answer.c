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
                     printf("%c",c);
                     break;
                 }

             }

         }

         else if(c=='/')
         {
             c=getchar();
             if(c=='/')
             {
                 while(c!='\n'&&((c=getchar())!=EOF))
                 {
                    ;
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
                             //c=getchar();
                             break;
                         }
                         else
                         {
                             ;
                         }
                     }
                 }

             }
         }

        else
            printf("%c",c);

    }


    return 0;
}
