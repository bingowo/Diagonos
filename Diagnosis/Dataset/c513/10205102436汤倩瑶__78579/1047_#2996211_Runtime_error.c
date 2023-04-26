#include<stdio.h>
#include<string.h>
typedef struct {
    char c;
    int num;
}node;
int main()
{
    int t;
    scanf("%d",&t);
    char s[505];

    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        node p[505]={0};
        int cnt=0;
        scanf("%s",s);
        int l=strlen(s);
        int j;

       while(j<l)
        {
            if(s[j]==s[j+1]){j++;p[cnt].num++;}
            else {p[cnt].c=s[j];p[cnt].num++;cnt++;j++;
            }
        }
      for(int j=0;j<cnt;j++)
      {
          if(p[j].num<=255)
          printf("%d%c",p[j].num,p[j].c);
          else printf("%d%c%d%c",255,p[j].c,p[j].num-255,p[j].c);

      }
      printf("\n");

    }

}
