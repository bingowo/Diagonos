#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
    int n;
    scanf("%d",&n);
    char s[4100][20];
    int max=0;
    for(int h=0;h<n;h++)
        {
            scanf("%s",s[h]);
            max=(max<strlen(s[h]))?strlen(s[h]):max;
        }
    printf("%d",max);
    char a[5100];
    scanf("%s",a);
    int len=strlen(a),l=0;
    while(l<len)
    {
        int i,flag=0;
        for(i=max;i>0;i--)
      {
        char a1[5100];
        memset(a1,'\0',5000);
        strncpy(a1,a+l,i);
        //printf("%s\n",a1);
        for(int k=0;k<n;k++)
           {
               if(strcmp(a1,s[k])==0) {l+=i;printf("%s ",s[k]);flag=1;break;}
           }
        //printf("%d",flag);
        if(flag==1) break;
      }
        if(i==0&&l<=len-1) {printf("%c ",a[l]);l++;}

    }

    return 0;
}
