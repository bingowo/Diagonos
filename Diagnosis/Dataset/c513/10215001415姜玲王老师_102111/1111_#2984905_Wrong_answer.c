#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{   int i,j;
    char a[25];
    char b[41][42]={0};
while(scanf("%s",a)!=EOF)
    { int c[4];
        for(i=0;i<41;i++)
    {
        if(i==20){b[0][i]='^';}
        else b[0][i]='.';
    }
     for(j=1;j<20;j++)
     {
         for(i=0;i<41;i++)
         if(i==20){b[j][i]='|';}
         else b[j][i]='.';
     }
     for(i=0;i<41;i++)
    {
        if(i==20){b[20][i]='+';}
        else {if(i==40)b[20][i]='>';
              else b[20][i]='-';}
    }
    for(j=21;j<41;j++)
     {
         for(i=0;i<41;i++)
         if(i==20){b[j][i]='|';}
         else b[j][i]='.';
     }

   int k=5;
   int num;
   while(k<strlen(a))
   {   num=0;
       if(a[k]>='0'&&a[k]<='9')
       {
           for(;a[k]>='0'&&a[k]<='9';k++)
            num=num*10+a[k]-'0';
        if(k==strlen(a)){c[0]=num;continue;}
        if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=num;k++;continue;}
                if(a[k]=='2'){c[2]=num;k++;continue;}}
            else{c[1]=num;continue;}
            }
        }
        if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=1;k++;continue;}
                if(a[k]=='2'){c[2]=1;k++;continue;}}
            else{c[1]=1;continue;}
            }
        if(a[k]=='+')
        {
            k++;
            if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=1;k++;continue;}
                if(a[k]=='2'){c[2]=1;k++;continue;}}
            else{c[1]=1;continue;}}
            for(;a[k]>='0'&&a[k]<='9';k++)
            {num=num*10+a[k]-'0';}
            if(k==strlen(a)){c[0]=num;continue;}
            if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=num;k++;continue;}
                if(a[k]=='2'){c[2]=num;k++;continue;}}
            else{c[1]=num;continue;}}
            }
       if(a[k]=='-')
        {
            k++;
            if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=-1;k++;continue;}
                if(a[k]=='2'){c[2]=-1;k++;continue;}}
            else{c[1]=-1;continue;}}
            for(;a[k]>='0'&&a[k]<='9';k++)
            {num=num*10+a[k]-'0';}
            if(k==strlen(a)){c[0]=-num;continue;}
            if(a[k]=='x')
            {k++;
             if(a[k]=='^')
                {k++;
                if(a[k]=='3'){c[3]=-num;k++;continue;}
                if(a[k]=='2'){c[2]=-num;k++;continue;}}
            else{c[1]=-num;continue;}}
            }
   }
    int x,y;
    for(x=-20;x<21;x++)
    {
        y=c[3]*x*x*x+c[2]*x*x+c[1]*x+x;
        if(y>=-20&&y<=20)
        {
            b[x+20][20-y]='*';
        }

    }
    for(i=0;i<41;i++)
    {
        printf("%s\n",b[i]);
    }
   printf("\n");
   }
}
