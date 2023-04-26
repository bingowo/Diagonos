#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int isnum(char a)
{
    if(a<='9'&&a>='0') return 1;
    else return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char tmp=getchar();
    for(int i=0;i<n;i++)
    {
        char ori[1000];
        gets(ori);
        char cal[200][200];
        int count=0,m=0;
        for(int j=0;j<strlen(ori);j++)
        {
            if(ori[j]==' ')
            {
                cal[count][m]='\0';
                count++;
                m=0;
            }
            else cal[count][m++]=ori[j];
        }
        double nums[200];
        int flag=0;
        for(int j=count;j>=0;j--)
        {
            if(isnum(cal[j][0])||isnum(cal[j][1]))
            {
                nums[flag++]=atof(cal[j]);
                continue;
            }
            if(cal[j][0]=='+')
            {
                nums[flag-2]=nums[flag-1]+nums[flag-2];
                flag--;
            }
            else if(cal[j][0]=='+')
            {
                nums[flag-2]=nums[flag-1]+nums[flag-2];
                flag--;
            }
            else if(cal[j][0]=='-')
            {
                nums[flag-2]=nums[flag-1]-nums[flag-2];
                flag--;
            }
            else if(cal[j][0]=='*')
            {
                nums[flag-2]=nums[flag-1]*nums[flag-2];
                flag--;
            }
            else if(cal[j][0]=='/')
            {
                nums[flag-2]=nums[flag-1]/nums[flag-2];
                flag--;
            }
        }
        printf("case #%d:\n",i);
        printf("%.6lf\n",nums[0]);
    }
}