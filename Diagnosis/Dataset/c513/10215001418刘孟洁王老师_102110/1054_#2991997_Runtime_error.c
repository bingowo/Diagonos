#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,cas,j,r,k,l,p,g,m,h,b,b1,b2,num,len[1007];
    char s[107],ans[17][77],ss[107][17];
    i = 0;
    scanf("%d",&n);
    gets(s);
    for(r = 0; r < n; r++)
   {
      memset(ans,0,sizeof(ans));
      //for(i = 0; i < 107; i++)memset(ss[i],0,sizeof(ss[i]));
      scanf("%d",&num);
      gets(s);
      cas = 0;
      gets(s);
      for(i = 0,k = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' '&&s[i+1] != '\0'){ss[cas][k] = s[i];k++;}
        else if(s[i] == ' '){ss[cas][k] = '\0';len[cas] = k;cas++;k = 0;}
        else if(s[i+1] == '\0')
        {
            ss[cas][k++] = s[i];
            ss[cas++][k] = '\0';
            len[cas-1] = k;
        }
    }
       for(i = 0,l = 0,p = 0,k = 0; i < cas; i++)
       {
          if(l+k-1 <= num){l += len[i];k++;}
          else
         {
            b = num - l;
            b1 = b/(k-1);
            b2 = b%(k-1);
            for(j = 0,m = 0,g = i-k; j < k; g++,j++)
            {
                for(h = 0; h < len[g]; m++,h++)ans[p][m] = ss[g][h];
                if(j != k-1)for(h = 0; h < b1&&m < num;m++,h++)ans[p][m] = ' ';
                else for(h = 0; h < b1 + b2&&m < num;m++,h++)ans[p][m] = ' ';
            }
            k = 1;
            l = len[i];
            p++;
          }
       }
       if(l)
       {
            b = num - l;
            b1 = b/(k-1);
            b2 = b%(k-1);
            for(j = 0,m = 0,g = i-k; j < k; g++,j++)
            {
                for(h = 0; h < len[g]; m++,h++)ans[p][m] = ss[g][h];
                if(j != k-1)for(h = 0; h < b1&&m < num;m++,h++)ans[p][m] = ' ';
                else for(h = 0; h < b1 + b2&&m < num;m++,h++)ans[p][m] = ' ';
            }
            k = 1;
            l = len[i];
            p++;
       }
       printf("case #%d:\n",r);
       for(j = 0; j < p; j++)printf("%s\n",ans[j]);
    }
    return 0;
}