#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
  char a[1000];
  int b['Z'+1]={0};
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

                 if(a[1]=='U'&&strlen(a)==9){b[a[4]]*=b[a[7]];break;}
                 if(a[1]=='U'&&strlen(a)>9){b[a[4]]=b[a[7]]*b[a[10]];break;}
                 if(a[1]=='O'&&a[2]=='D'&&strlen(a)==9) {b[a[4]]%=b[a[7]];break;}
                 if(a[1]=='O'&&a[2]=='D'&&strlen(a)>9) {b[a[4]]=b[a[7]]%b[a[10]];break;}
                 }
        case'A':{if(a[1]=='D'&&strlen(a)==9){b[a[4]]+=b[a[7]];break;}
                 if(a[1]=='D'&&strlen(a)>9){b[a[4]]=b[a[7]]+b[a[10]];break;}
                 if(a[1]=='N'&&strlen(a)==9){b[a[4]]=b[a[4]]&b[a[7]];break;}
                 if(a[1]=='N'&&strlen(a)>9){b[a[4]]=b[a[7]]&b[a[10]];break;}}
        case'S':{if(strlen(a)==9){b[a[4]]-=b[a[7]];break;}
                 else {b[a[4]]=b[a[7]]-b[a[10]];break;}}
        case'D':{if(strlen(a)==9){b[a[4]]/=b[a[7]];break;}
                else {b[a[4]]=b[a[7]]/b[a[10]];break;}}
        case'O':{if(a[1]=='U'){printf("%d\n",b[a[4]]);break;}
                  if(a[1]='O'&&strlen(a)==8){b[a[3]]=b[a[3]]|b[a[6]];break;}
                  if(a[1]='O'&&strlen(a)>8){b[a[3]]=b[a[9]]|b[a[6]];break;}}
        case'X':{if(a[1]=='C'){c=b[a[5]];b[a[5]]=b[a[8]];b[a[8]]=c;break;}
                 if(a[1]=='O'&&strlen(a)==9){b[a[4]]=b[a[4]]^b[a[7]];break;}
                 if(a[1]=='O'&&strlen(a)>9){b[a[4]]=b[a[7]]^b[a[10]];break;}}}

        }
        }


