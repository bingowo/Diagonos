#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   char s[17];
   while(scanf("%s",s)==1)
    {
       int i;
       double f;
       char *p;
        if(strchr(s,'.'))
        {
          f = atof(s);
          p = (char*)&f;
         for(int k=0;k<sizeof(int);k++)
            printf("%02x ",*(p+k));
        printf("\n");
        }
        else
        {
            i = atoi(s);
            p = (char*)&i;
            for(int k=0;k<sizeof(int);k++)
                printf("%02x ",*(p+k));
            printf("\n");
        }
   }
   return 0;
}
