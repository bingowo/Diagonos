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
        int R=5,B=5,Y=5,G=5,i;
        int l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(str[i]=='R') R=i;
            else if(str[i]=='B') B=i;
            else if(str[i]=='Y') Y=i;
            else if(str[i]=='G') G=i;
        }
        if(R==5||B==5||Y==5||G==5)
        {
            if(R==5) R=10-B-Y-G;
            else if(B==5) B=10-R-Y-G;
            else if(Y==5) Y=10-R-B-G;
            else if(G==5) G=10-R-Y-B;
        }
        else {R=R%4;B=B%4;Y=Y%4;G=G%4;}
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
