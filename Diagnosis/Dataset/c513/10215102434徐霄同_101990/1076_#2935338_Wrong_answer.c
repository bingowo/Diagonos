#include <stdio.h>
#include <string.h>

int main()
{
    char s[101],a[101];
    int t,i,j,k,l,f;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        printf("%s\n",s);
        l=strlen(s);
        a[0]=s[0];
        k=1;
        j=1;
        f=0;
        for(j=1;j<l;j++)
            if(s[j]=='{')
                if(k!=0&&a[k-1]!='('){
                    f=1;
                    break;
                }
                else{
                    a[k]=s[j];
                    k++;
                }
            else if(s[j]=='[')
                if(k!=0&&a[k-1]!='{'){
                    f=1;
                    break;
                }
                else{
                    a[k]=s[j];
                    k++;
                }
            else if(s[j]=='(')
                if(k!=0&&a[k-1]!='['){
                    f=1;
                    break;
                }
                else{
                    a[k]=s[j];
                    k++;
                }
            else if(s[j]=='}')
                if(k==0||a[k-1]!='{'){
                    f=1;
                    break;
                }
                else{
                    a[k-1]=0;
                    k--;
                }
            else if(s[j]==']')
                if(k==0||a[k-1]!='['){
                    f=1;
                    break;
                }
                else{
                    a[k-1]=0;
                    k--;
                }
            else if(s[j]==')')
                if(k==0||a[k-1]!='('){
                    f=1;
                    break;
                }
                else{
                    a[k-1]=0;
                    k--;
                }
        for(j=1;j<l;j++)
            if((s[j-1]=='{'&&s[j]=='}')||(s[j-1]=='['&&s[j]==']')){
                f=1;
                break;
            }
        //if(f==1)
            //printf("No\n");
        //else
            //printf("Yes\n");
    }
    return 0;
}
