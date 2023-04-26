#include <stdio.h>
#include<math.h>
int main(void)
{
    int n,j;
    char c,str[100];
    scanf("%d ",&n);
    for(int i=0; i<n;i++)
        {
        int ans = 0;
        j=0;
        while((c=getchar())!='\n')
            {
                str[j]=c;
                j++;
            }
            j--;
        for(int m=0;m<=j;m++)
        {
            if(str[m]=='-') ans-=pow(3,j-m);
            else ans+=pow(3,j-m)*(str[m]-'0');
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
        return 0;
}
