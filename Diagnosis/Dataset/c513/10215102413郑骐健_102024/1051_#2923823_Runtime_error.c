#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//建立对照表
char s[64];
int main()
{
    for(int i =0;i < 26;i++)
    {
        s[i] = 'A'+i;
    }
    for(int i =26;i<52;i++)
    {
        s[i]= 'a'+i-26;
    }
    for(int z =52;z<62;z++)
    {
        s[z] = '0'+z-52;
    }
    s[62] ='+';
    s[63] = '/';


    int t;
    scanf("%d",&t);
    for(int j = 0;j < t; j++)
    {

    int left = 8;
    char init[101];
    memset(init,0,101);
    scanf("%s",init);
    int n = 0,length;
    n = strlen(init);
    length = n;
    int n2 = length/3*4 ;
    if(length%3)n2 +=length%3+1;
    if(length%3)n = n2+3-length%3;
    else n = n2;
    int point = 0;
    int p2 = 0;
    char res[101];
    int needed = 6;

    for(int o=0;o<n2;o++)
    {
        int m = 0;
      while(needed!=0)
      {
          unsigned int x = (unsigned int) init[point];
          if(left >=needed)
          {
              m += '\0'^(((x<<(32-left))>>(32-left))>>(left-needed));
               left-=needed;
               needed =0;

            }
            else
            {
            m=m+ '\0'^(((x<<(32-left))>>(32-left))<<(needed-left));
             needed -= left;
             left = 0;

            }
            if(left==0)
            {
                point++;
                left+=8;
            }
    }
    res[o] = s[m];
    needed+=6;
    }


    printf("case #%d:\n",j);
    for(int i = 0;i<n;i++)
    {
        if(i<n2)printf("%c",res[i]);
        else printf("=");
    }
    printf("\n");
    }
    return 0;
}
