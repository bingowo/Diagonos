#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,i;scanf("%d",&T);char s[101];
    for(int t=0;t<T;t++)
    {   
        int flag=-1;int a[127]={0};
        scanf("%s",s);
        for(i=0;i<strlen(s)&&flag==-1;i++)
        {
            switch(s[i])
            {
                case '(':
                    if(s[i+1]=='['||s[i+1]=='('){flag==1;break;}
                    else a[s[i]]++;
                case '[':
                    if(s[i+1]=='['||s[i+1]=='{'){flag==1;break;}
                    else a[s[i]]++;
                case '{':
                    if(s[i+1]=='('||s[i+1]=='{'){flag==1;break;}
                    else a[s[i]]++;
                case ')':
                    if(a['(']!=0||a['[']!=0||a['{']!=0)
                        if(s[i+1]=='['||s[i+1]=='{'){flag==1;break;};
                    else a[s[i]]--;
                case ']':
                    if(a['(']!=0||a['[']!=0||a['{']!=0)
                        if(s[i+1]=='('||s[i+1]=='{'){flag==1;break;};
                    else a[s[i]]--;
                case '}':        
                    if(a['(']!=0||a['[']!=0||a['{']!=0)
                        if(s[i+1]=='('||s[i+1]=='['){flag==1;break;};
                    else a[s[i]]--;   
            }
        }
        if(flag==-1)printf("Yes\n");
        else printf("No\n");
    }
}