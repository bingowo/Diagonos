#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int n,i,j,k,l,m,copy;
    char s[507],p[27],t[507][27];
    scanf("%d",&n);
    gets(s);
    for(i = 0; i < n; i++)
    {
        gets(s);
        for(j = 0,k = 0,l = 0; s[j] != '\0'; j++)
        {
            if(s[j+1] <='z'&&s[j+1] >= 'a')
            {
                t[k][l] = s[j];
                l++;
            }
            else if((s[j+1] == ' '||s[j+1] == '.'||s[j+1] == '!'||s[j+1] == '?'||s[j+1] == ',')&&(s[j] <='z'&&s[j] >= 'a'))
            {
                t[k][l] = s[j];
                t[k][l+1] = '\0';
                for(m = 0,copy = 0; m < k; m++)
                {
                    if(strcmp(t[k],t[m]) == 0){copy++;break;}
                }
                if(copy)for(m = 0;m < l+1; m++)t[k][m] = '\0';
                else k++;
                l = 0;
                for(m = j+1;s[m] < 'a'||s[m] > 'z'; m++);
                  j = m-1;
            }
            else if((s[j+1] == '\0')&&(s[j] <='z'&&s[j] >= 'a'))
            {
                t[k][l] = s[j];
                t[k][l+1] = '\0';
                for(m = 0,copy = 0; m < k; m++)
                {
                    if(strcmp(t[k],t[m]) == 0){copy++;break;}
                }
                if(copy)for(m = 0;m < l+1; m++)t[k][m] = '\0';
                else k++;
            }
        }
        for(j = 0;j < k; j++)
        {
           for(m = j+1; m < k; m++)
           {
               if(strcmp(t[j],t[m])>0)
               {
                  strcpy(p,t[j]);
                  strcpy(t[j],t[m]);
                  strcpy(t[m],p);
               }
           }
        }
        printf("case #%d:\n",i);
        for(j = 0; j < k; j++)printf("%s%c",t[j],j == k-1?'\n':' ');
        for(j = 0; j < k; j++)
            {for(m = 0; m < strlen(t[j]); m++)t[j][m] = '\0';}
        for(j = 0; j < strlen(p); j++)p[j] = '\0';
    }
    return 0;
}
