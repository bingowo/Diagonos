#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
  char a[1000];
  long long b['Z'+2]={0};
  int c;
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
        case'M':{if(a[1]=='O'&&a[2]=='V'){b[a[4]]=b[a[7]];break;}

                 else{if(a[1]=='U'){b[a[4]]*=b[a[7]];break;}
                 else {b[a[4]]=b[a[4]]%b[a[7]];break;}}}
        case'A':{if(a[1]=='D'){b[a[4]]+=b[a[7]];break;}
                 else{b[a[4]]=b[a[4]]&b[a[7]];break;}}
        case'S':{b[a[4]]-=b[a[7]];break;}
        case'D':{b[a[4]]/=b[a[7]];break;}
        case'O':{if(a[1]=='U'){printf("%lld\n",b[a[4]]);break;}
                  else{b[a[3]]=b[a[3]]|b[a[6]];break;}}
        case'X':{if(a[0]=='C'){c=b[a[5]];b[a[5]]=b[a[8]];b[a[8]]=c;break;}
                 else {b[a[4]]=b[a[4]]^b[a[7]];break;}}

        }
        }
}

