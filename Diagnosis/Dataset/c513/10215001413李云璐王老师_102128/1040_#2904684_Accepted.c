#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[20],b[20],c[20];
    scanf("%s %s %s",a,b,c);
    char d[20];
    if(c[0]=='?') 
    {
        int lena=strlen(a),lenb=strlen(b);
        if(lena==1&&lenb==1) 
        {
            if(a[0]=='A'&&b[0]=='A') {char d[]="{A,O}";printf("%s %s %s",a,b,d);}
            if((a[0]=='A'&&b[0]=='B')||(b[0]=='A'&&a[0]=='B')) {char d[]="{A,AB,B,O}";printf("%s %s %s",a,b,d);}
            if(a[0]=='B'&&b[0]=='B') {char d[]="{B,O}";printf("%s %s %s",a,b,d);}
            if((a[0]=='A'&&b[0]=='O')||(b[0]=='A'&&a[0]=='O')) {char d[]="{A,O}";printf("%s %s %s",a,b,d);}
            if((a[0]=='B'&&b[0]=='O')||(b[0]=='B'&&a[0]=='O')) {char d[]="{B,O}";printf("%s %s %s",a,b,d);}
            if(a[0]=='O'&&b[0]=='O') {char d[]="{O}";printf("%s %s %s",a,b,d);}
        }
        if(lena==2&&lenb==1)
        {
            if(b[0]=='A') {char d[]="{A,AB,B}";printf("%s %s %s",a,b,d);}
            if(b[0]=='B') {char d[]="{A,AB,B}";printf("%s %s %s",a,b,d);}
            if(b[0]=='O') {char d[]="{A,B}";printf("%s %s %s",a,b,d);}
        }
         if(lena==1&&lenb==2)
        {
            if(a[0]=='A') {char d[]="{A,AB,B}";printf("%s %s %s",a,b,d);}
            if(a[0]=='B') {char d[]="{A,AB,B}";printf("%s %s %s",a,b,d);}
            if(a[0]=='O') {char d[]="{A,B}";printf("%s %s %s",a,b,d);}
        }
        if(lena==2&&lenb==2) {char d[]="{A,AB,B}";printf("%s %s %s",a,b,d);}
    }
    if(a[0]=='?')
    {
        int lenb=strlen(b),lenc=strlen(c);
        if(lenc==1&&lenb==1)
        {
            if(c[0]=='A')
            {
                if(b[0]=='A') {char d[]="{A,AB,B,O}";printf("%s %s %s",d,b,c);}
                if(b[0]=='B') {char d[]="{A,AB}";printf("%s %s %s",d,b,c);}
                if(b[0]=='O') {char d[]="{A,AB}";printf("%s %s %s",d,b,c);}
            }
            if(c[0]=='B')
            {
                if(b[0]=='A') {char d[]="{AB,B}";printf("%s %s %s",d,b,c);}
                if(b[0]=='B') {char d[]="{A,AB,B,O}";printf("%s %s %s",d,b,c);}
                if(b[0]=='O') {char d[]="{AB,B}";printf("%s %s %s",d,b,c);}
            }
            if(c[0]=='O')
            {
                if(b[0]=='A') {char d[]="{A,B,O}";printf("%s %s %s",d,b,c);}
                if(b[0]=='B') {char d[]="{A,B,O}";printf("%s %s %s",d,b,c);}
                if(b[0]=='O') {char d[]="{A,B,O}";printf("%s %s %s",d,b,c);}
            }
        }
         if(lenc==2&&lenb==1)
         {
                if(b[0]=='A') {char d[]="{AB,B}";printf("%s %s %s",d,b,c);}
                if(b[0]=='B') {char d[]="{A,AB}";printf("%s %s %s",d,b,c);}
                if(b[0]=='O') {char d[]="impossible";printf("%s %s %s",d,b,c);}
         }
         if(lenc==1&&lenb==2)
          {
                if(c[0]=='A') {char d[]="{A,AB,B,O}";printf("%s %s %s",d,b,c);}
                if(c[0]=='B') {char d[]="{A,AB,B,O}";printf("%s %s %s",d,b,c);}
                if(c[0]=='O') {char d[]="impossible";printf("%s %s %s",d,b,c);}
         }
         if(lenc==2&&lenb==2) {char d[]="{A,AB,B}";printf("%s %s %s",d,b,c);}
         
    }
    if(b[0]=='?')
    {
        int lena=strlen(a),lenc=strlen(c);
        if(lenc==1&&lena==1)
        {
            if(c[0]=='A')
            {
                if(a[0]=='A') {char d[]="{A,AB,B,O}";printf("%s %s %s",a,d,c);}
                if(a[0]=='B') {char d[]="{A,AB}";printf("%s %s %s",a,d,c);}
                if(a[0]=='O') {char d[]="{A,AB}";printf("%s %s %s",a,d,c);}
            }
            if(c[0]=='B')
            {
                if(a[0]=='A') {char d[]="{AB,B}";printf("%s %s %s",a,d,c);}
                if(a[0]=='B') {char d[]="{A,AB,B,O}";printf("%s %s %s",a,d,c);}
                if(a[0]=='O') {char d[]="{AB,B}";printf("%s %s %s",a,d,c);}
            }
            if(c[0]=='O')
            {
                if(a[0]=='A') {char d[]="{A,B,O}";printf("%s %s %s",a,d,c);}
                if(a[0]=='B') {char d[]="{A,B,O}";printf("%s %s %s",a,d,c);}
                if(a[0]=='O') {char d[]="{A,B,O}";printf("%s %s %s",a,d,c);}
            }
        }
         if(lenc==2&&lena==1)
         {
                if(a[0]=='A') {char d[]="{AB,B}";printf("%s %s %s",a,d,c);}
                if(a[0]=='B') {char d[]="{A,AB}";printf("%s %s %s",a,d,c);}
                if(a[0]=='O') {char d[]="impossible";printf("%s %s %s",a,d,c);}
         }
         if(lenc==1&&lena==2)
          {
                if(c[0]=='A') {char d[]="{A,AB,B,O}";printf("%s %s %s",a,d,c);}
                if(c[0]=='B') {char d[]="{A,AB,B,O}";printf("%s %s %s",a,d,c);}
                if(c[0]=='O') {char d[]="impossible";printf("%s %s %s",a,d,c);}
         }
         if(lenc==2&&lena==2) {char d[]="{A,AB,B}";printf("%s %s %s",a,d,c);}
         
    }
    return 0;
    
}