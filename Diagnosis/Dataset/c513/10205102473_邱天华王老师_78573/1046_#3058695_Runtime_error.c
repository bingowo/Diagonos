#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    char c;
    scanf("%d",&n);
    c=getchar();
    char* sl[]={"the","The","THE","a","an","A","AN","of","OF","anD","For","and","FOR"};
    for(int i=0;i<n;i++)
    {
        char* p;
        int a=0;
        int s_num=0;
        char s[101];
        int len;
        int flag=0;
        gets(s);
        len=strlen(s);
 
        for(int j=0;j<=len;j++)
        {

            if((s[j]>='a'&& s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))
            {   
                p[a]=s[j];
                a++;
            }
            else
            {
                for(int k=0;k<13;k++)
                {
                    if(p==sl[k])flag=1;
                }

                if(flag!=1)
                    {
                        s_num++;
                        
                    }
                else 
                    flag=0;
                a=0;
                memset(p,'\0',sizeof(p));
            }
        
        }
        printf("case #%d: \n",i);
        printf("%d\n",s_num);
    }
    return 0;  
}
