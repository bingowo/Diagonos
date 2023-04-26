#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[110];
        scanf("%s",s);
        int a[128]={0};
        int len=strlen(s);
        if(len>4){for(int k=0;k<len;k++)
        {
            if(s[k]=='!')
            {
                int l=k-4*(k/4);
                while(s[l]=='!'&&s[l]!='\0') l+=4;
                a[s[l]]++;

            }

        }}
        if(len==4)
        {
            a['R']=1;a['Y']=1;a['B']=1;a['G']=1;
            for(int k=0;k<4;k++)
                a[s[k]]--;
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",a['R'],a['B'],a['Y'],a['G']);
    }
    return 0;
}