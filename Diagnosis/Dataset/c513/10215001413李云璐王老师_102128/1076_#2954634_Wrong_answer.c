#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[110]={'\0'},s1[110];
        scanf("%s",s1);
        int len=strlen(s1);
        int k=1,l=1;
        s[0]=s1[0];
        while(s1[k])
        {
            int flag=k;
            switch(s1[k])
            {
                case '{':{if(s[l-1]=='('||l==0) {s[l]=s1[k];k++;l++;break;}
                else break;}
                case '[':{if(s[l-1]=='{'||l==0) {s[l]=s1[k];k++;l++;break;}
                else break;}
                case '(':{if(s[l-1]=='['||l==0) {s[l]=s1[k];k++;l++;break;}
                else break;}
                case ')':{if(s[l-1]=='(') {s[l-1]='0';l--;k++;break;}
                else break;}
                case ']':{if(s[l-1]=='['){s[l-1]='0';l--;k++;break;}
                else break;}
                case '}':{if(s[l-1]=='{'){s[l-1]='0';l--;k++;break;}
                else break;}
                default:break;
            }
          if(k==flag) break;
        }
        if(k<len) printf("No\n");
        else if(s[l-1]!='0') printf("No\n");
        else printf("Yes\n");





    }
    return 0;
}