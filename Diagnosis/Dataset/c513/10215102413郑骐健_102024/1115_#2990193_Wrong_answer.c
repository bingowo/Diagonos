#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
    printf("case #%d:",i);
    int num[10];
    memset(num,0,sizeof(num));
    char mid[50];
    scanf("%s",mid);
    int po = strlen(mid)-2;
    char last = mid[strlen(mid)-1];
    num [last-'0']++;
    while(po>=0)
    {
        int flag=0;
        int s;
        for(s=0;s<10;s++)
        {
            if(num[s]!=0&&s>mid[po]-'0')
            {
                  last = s+'0';
                    flag =1;
                    break;
            }
        }

      if(flag)break;
      num[mid[po]-'0']++;
      po--;
    }
        if(po==-1)
        {
          num[0]++;
          for(int j=1;j<10;j++)
          {
              if(num[j]!=0)
              {
              printf("%d",j);
              num[j]--;
              break;
              }
          }
          for(int q=0;q<num[0];q++)printf("0");
          for(int z=1;z<10;z++)
          {
              for(int o=0;o<num[z];o++)
              {
                  printf("%d",z);
              }
          }
          printf("\n");
        }
        else
        {
            num[mid[po]-'0']++;
            mid[po] = 0;
            printf("%s%c",mid,last);
            num[last-'0']--;
             for(int z=0;z<10;z++)
          {
              for(int o=0;o<num[z];o++)
              {
                  printf("%d",z);
              }

          }
            printf("\n");
        }
    }
    return 0;
}
