#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int result[4]={},t[4]={},num[4]={};
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        for (int j=0;j<len;j++)
        {
            t[j%4]++;
            switch (s[j])
            {
            case 'R':
                result[0]++;
                num[0]=j%4;
                break;
            case 'B':
                result[1]++;
                num[1]=j%4;
                break;
            case 'Y':
                result[2]++;
                num[2]=j%4;
                break;
            case 'G':
                result[3]++;
                num[3]=j%4;
                break;
            }
        }
        printf ("case #%d:\n%d %d %d %d\n",i,t[num[0]]-result[0],t[num[1]]-result[1],t[num[2]]-result[2],t[num[3]]-result[3]);
    }
    return 0;
}
