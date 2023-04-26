#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i,j;
    for(i = 0;i<T;i++)
    {
        char s[101],a[4] = {0},b[4],c[4];
        scanf("%s",s);
        for(j = 0;j<strlen(s);j++)
        {
            switch(s[j])
            {
                case 'R':a[0]++;b[0] = j%4;break;
                case 'B':a[1]++;b[1] = j%4;break;
                case 'Y':a[2]++;b[2] = j%4;break;
                case 'G':a[3]++;b[3] = j%4;break;
            }
        }
        int n = strlen(s)/4,m = strlen(s)%4;
            for(j = 0;j<4;j++)
            {
                c[j] = n;
                if(b[j]<m) c[j]++;
                //printf("%d ",c[j]);
            }
            printf("case #%d:\n%d %d %d %d\n",i,c[0]-a[0],c[1]-a[1],c[2]-a[2],c[3]-a[3]);
    }
    return 0;
}
