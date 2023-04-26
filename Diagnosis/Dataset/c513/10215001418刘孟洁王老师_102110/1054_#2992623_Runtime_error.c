#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ans[107][107],ss[107][37];
int main()
{
    int n,i,cas,j,r,k,l,p,g,m,h,b,b1,b2,num,len[1007];
    char s[2007];
    i = 0;
    scanf("%d",&n);
    gets(s);
    for(r = 0; r < n; r++)
   {
      memset(ans,0,sizeof(ans));
      for(i = 0; i < 107; i++)memset(ss[i],0,sizeof(ss[i]));
      scanf("%d",&num);
      gets(s);
      cas = 0;
      gets(s);
      for(i = 0,k = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' '&&s[i+1] != '\0'){ss[cas][k++] = s[i];}
        else if(s[i] == ' ')
            {
                if(strlen(ss[cas][k])){ss[cas][k] = '\0';len[cas++] = k;k = 0;}
            } 
        else if(s[i+1] == '\0')
        {
            ss[cas][k++] = s[i];
            ss[cas++][k] = '\0';
            len[cas-1] = k;
        }
    }
       for(i = 0,l = 0,p = 0,k = 0; i < cas; i++)
       {
          l += len[i];k++;
          if(l+k-1 <= num)continue;
          else
         {
            b = num - l + len[i];
            int u = k-2;
            for(j = 0,m = 0,g = i-k+1; j < k-1; g++,j++)
            {
                b = b/u;
                for(h = 0; h < len[g]&&m < num; m++,h++)ans[p][m] = ss[g][h];
                for(h = 0; h < b&&m < num;m++,h++)ans[p][m] = ' ';
                //else for(h = 0; h < b1 + b2&&m < num;m++,h++)ans[p][m] = ' ';
                if(u>1)u--;
            }
            ans[p][m] = '\0';
            k = 1;
            l = len[i];
            p++;
          }
       }
       if(l)
       {
            b = num - l;
            for(j = 0,m = 0,g = i-k; j < k; g++,j++)
            {
                for(h = 0; h < len[g]&&m < num; m++,h++)ans[p][m] = ss[g][h];
                for(h = 0; h < 1&&m < num;m++,h++)ans[p][m] = ' ';
            }
            for(; m < num;m++)ans[p][m] = ' ';
            ans[p][m] = '\0';
            p++;
       }
       printf("case #%d:\n",r);
       for(j = 0; j < p; j++)printf("%s\n",ans[j]);
    }
    return 0;
}
