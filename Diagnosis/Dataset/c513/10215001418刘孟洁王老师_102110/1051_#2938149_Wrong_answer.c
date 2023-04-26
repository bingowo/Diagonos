#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char p[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

char f[1000007];
int main()
{
    int n,i,j,k,l,x,c;
    int number[207] = {0};
    char d,ans[47],s[107],t[9];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
        for(j = 0; j < strlen(s); j++)
        {
            c = s[j] - '0'+48;
            for(k = 0; k < 8; k++)
            {
                t[k] = c%2 +'0';
                c = c/2;
            }
            k--;
            for(l = 0; l <= 3; l++)
            {
                d = t[l];
                t[l] = t[k-l];
                t[k-l] = d;
            }
            t[k+1] = '\0';
            for(x = j*8, l =0; l <= k; l++, x++)f[x] = t[l];
            for(l = 0; l < k; l++)t[l] = '\0';
        }
       if(strlen(s)%3)for(; x%6; x++)f[x] = '0';
       f[x] = '\0';
       for(k = 0,l = 0,x-=1; x >= 0; x--)
       {
           if(l<6)
           {
               number[k] = number[k]+ (f[x]-'0')*pow(2,l) ;
               l++;
           }
           else
           {
               l = 0;
               k++;
               number[k] = f[x]-'0';
               l++;
           }
       }
       for(l = 0; l <= k; l++)ans[l] = p[number[l]];
       for(l = 0; l <= k/2; l++)
       {
           d = ans[l];
           ans[l] = ans[k-l];
           ans[k-l] = d;
       }
       ans[k+1] = '\0';
       printf("case #%d:\n",i);
       if(!(strlen(s)%3))printf("%s\n",ans);
       else if(strlen(s)%3 == 1)printf("%s==\n",ans);
       else if(strlen(s)%3 == 2)printf("%s=\n",ans);
       for(l = 0; l < k; l++)number[l] = 0;
    }
    return 0;
}
