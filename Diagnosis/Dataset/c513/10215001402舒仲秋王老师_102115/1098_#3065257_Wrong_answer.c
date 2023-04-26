#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int N,k;
    scanf("%d",&N);
    for(k=0;k<N;k++)
    {
        printf("case #%d:\n",k);
        char str[101];
        scanf("%s",str);
        int R,B,Y,G,i;
        int l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(str[i]=='R') R=i;
            else if(str[i]=='B') B=i;
            else if(str[i]=='Y') Y=i;
            else if(str[i]=='G') G=i;
        }
        R=R%4;B=B%4;Y=Y%4;G=G%4;
        int r=0,b=0,y=0,g=0;
        for(i=0;i<l;i++)
        {
            if(str[i]=='!')
            {
                if(i%4==R) r++;
                else if(i%4==B) b++;
                else if(i%4==Y) y++;
                else if(i%4==G) g++;
            }
        }
        printf("%d %d %d %d\n",r,b,y,g);
    }
    return 0;
}
