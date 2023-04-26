#include <stdio.h>
#include <string.h>
 
int main()
{
     char a[1000] = "$GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50",*p;
     int hour, min, sec;
     int check, value;
     do {
         
         gets(a);
         p = a;
 
         if ( strncmp(a,"$GPRMC",6) == 0 && strncmp(strchr(a+6,','),",A",2) ) {    //这里一定要注意A定位
             check = *(++p);
             for ( p = p + 1; *p != '*'; p++ ) {
                 check = check ^ *p;
             }
             check = check%65536;
 
             value = 0;
             for ( p = p + 1; *p != '\0'; p++ )    //十六进制-->十进制
             {
                 if ( 'A' <= *p && *p <= 'F' )
                     value = value * 16 + *p - 'A' + 10;
                 else
                     value = value * 16 + *p - '0';
             }
 
             if ( (check) == value )
             {
                 hour = (a[7]-'0')*10+(a[8]-'0')+8;
                 if (hour > 24)
                     hour -= 24;
                 min = (a[9]-'0')*10+(a[10]-'0');
                 sec = (a[11]-'0')*10+(a[12]-'0');
             }
         }
 
     } while ( strcmp(a,"END") != 0 );
     
     printf("%02d:%02d:%02d\n", hour, min, sec);
 
     return 0;
 }