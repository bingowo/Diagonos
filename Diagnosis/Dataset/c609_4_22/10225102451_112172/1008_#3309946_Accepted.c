#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
    printf("%02x ", start[i]);
    printf("\n");
}
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}
/*void solveint(int n)
{
    int a=sizeof(n);
    unsigned char *p=(unsigned char *)&n;
    while(a--)
    {
        printf("%02x",*p++);
    }
    printf('\n');

}
void solvedouble(double n)
{
    int a=sizeof(n);
    unsigned char *p=(unsigned char *)&n;
    while(a--)
    {
        printf("%02x",*p++);
    }
    printf('\n');

}*/
int main()
{
   char s[33];

   while(scanf("%s",s)!=EOF)
   {
       if(strchr(s,'.')==NULL)
        show_int(atoi(s));
       else
        show_double(atof(s));
   }
   return 0;
}
