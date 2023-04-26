#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
  char a[100];
  int b['E']={0};
  while(gets(a))
        { int   flag=1;
            switch(a[0])
       {
           case'I':{int i=6;
                if(a[6]=='-'){flag=-1;i++;}
                 b[a[3]]=0;
                 for(;i<strlen(a);i++) b[a[3]]=b[a[3]]*10+a[i]-'0';
                 b[a[3]]*=flag;
                 break;}
        case'M':{if(a[1]=='O'){b[a[4]]=b[a[7]];break;}

                 else{b[a[4]]*=b[a[7]];break;}}
        case'A':{b[a[4]]+=b[a[7]];break;}
        case'S':{b[a[4]]-=b[a[7]];break;}
        case'D':{b[a[4]]/=b[a[7]];break;}
        case'O':{printf("%d",b[a[4]]);break;}}



        }
}