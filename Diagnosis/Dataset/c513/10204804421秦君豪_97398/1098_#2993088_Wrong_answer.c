#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 1000000

typedef long long int lli;




int main(void)
{
    int t;
    scanf("%d",&t);
    for(int j = 0;j<t;j++)
    {
        char s[101];
        int badnum=0;//坏掉的灯的个数
        memset (s,0,sizeof(s));

        int t[4]={0,0,0,0};//循坏RBYG
        int tb[128]={0};//统计出现的次数
        scanf("%s",s);
        int l =strlen(s);
        int cout[4]={l/4,l/4,l/4,l/4};//应该出现的次数
        for (int i=0;i<l;i++)
        {
            if (s[i]=='!')  badnum++;
            else
            {
                if (s[i]=='R') t[0]= i%4;
                else if (s[i]=='B') t[1] =i%4;
                else if (s[i]=='Y') t[2] =i%4;
                else if (s[i]=='G') t[3] =i%4;
                tb[s[i]]++;
            }
        }
        int left = l%4;
        if (left)
        {
            for(int i=0;i<4;i++)
            {
                if (t[i]+1<=left) cout[i]++;
            }
        }
        int r = cout[0]-tb['R'];
        int b = cout[1]-tb['B'];
        int y = cout[2]-tb['Y'];
        int g = cout[3]-tb['G'];
        printf("case #%d\n",j);
        printf("%d %d %d %d\n",r,b,y,g);


    }
    return 0;

}
