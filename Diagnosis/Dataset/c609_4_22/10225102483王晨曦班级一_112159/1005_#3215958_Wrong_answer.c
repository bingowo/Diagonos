#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char ss[100];
        scanf("%s",ss);

        int sum=0;
        for(int i=0; i<strlen(ss); i++)
        {
            if(ss[i]=='0') sum=sum*3+0;
            else if(ss[i]=='-') sum=sum*3-1;
            else if(ss[i]=='1') sum=sum*3+1;
        }
        int h=0;
        printf("case #%d:\n",h++);
        printf("%d\n",sum);
    }

    return 0;
}
