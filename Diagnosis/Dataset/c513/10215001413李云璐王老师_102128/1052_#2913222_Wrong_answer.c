#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[21];
        scanf("%s",s);
        int len=strlen(s);
        int a[128]={0},b[10]={0};
        for(int k=0;k<len;k++)
        a[s[k]]++; //a中存储每个字母的个数
        b[0]=a['Z'];
        b[2]=a['W'];
        b[4]=a['U'];
        b[6]=a['X'];
        b[8]=a['G'];
        b[7]=a['S']-a['X'];
        b[5]=a['F']-a['U'];
        b[3]=a['H']=a['G'];
        b[9]=a['I']-b[5]-b[6]-b[8];
        b[1]=a['O']-b[0]-b[2]-b[4];
        printf("case #%d:\n",i);
        for(int l=0;l<10;l++)
        {
               if(b[l]!=0)
                {for(int p=0;p<b[l];p++) printf("%d",l);
                printf("\n");}
        }
    }
    return 0;
}