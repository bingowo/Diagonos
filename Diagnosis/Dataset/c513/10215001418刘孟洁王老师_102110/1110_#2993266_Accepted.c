#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int signxi[1007],xi[1007],shu[1007];
    int equal,i,k,l;
    double ans,sumxi,sumshu;
    char s[1007],al;
    scanf("%s",s);
    int len = strlen(s);
    for(i = 0; i < len; i++)
         if(s[i] == '='){equal = i;break;}
    for(i = 0; i < len; i++)
         if((s[i] <= 'z'&&s[i] >= 'a')||(s[i] <= 'Z'&&s[i] >= 'A')){al = s[i];break;}
    //printf("%d\n",equal);
    for(i = 0,l = 0,k = 0; i < len;)
    {
        if(isdigit(s[i]))
        {
            if((s[i-1] == '+'&& i < equal)||i == 0||(s[i-1] == '-'&&i > equal))signxi[k] = 1;
            else if((s[i-1] == '-'&&i < equal)||(s[i-1] == '+'&&i > equal)||s[i-1] == '=')signxi[k] = -1;
            xi[k] = 0;
            for(; isdigit(s[i]); i++)xi[k] = xi[k]*10 + s[i]-'0';
            xi[k] *= signxi[k];
            i--;
            if(s[i+1] == '-'||s[i+1] == '+'||s[i+1] == '='||s[i+1] == '\0'){shu[l++] = -1*xi[k];k--;}
            i++;
            k++;
        }
        else if((s[i] <= 'z'&&s[i] >= 'a')||(s[i] <= 'Z'&&s[i] >= 'A'))
            {
                if(!isdigit(s[i-1])&&i >= 1)
               {
                 if((s[i-1] == '-'&&i < equal)||(s[i-1] == '+'&&i > equal)){xi[k] = -1;signxi[k++] = -1;}
                 else if((s[i-1] == '-'&&i > equal)||(s[i-1] == '+'&&i < equal)){xi[k] = 1;signxi[k++] = 1;}
                 i++;
               }
               else if(i == 0){signxi[k] = 1;xi[k] = 1;k++;i++;}
               else i++;
            }
        else i++;
    }
    for(i = 0,sumxi = 0; i < k; i++)sumxi += xi[i];
    for(i = 0,sumshu = 0; i < l; i++)sumshu += shu[i];
    ans = sumshu/sumxi;
    printf("%c=%.3lf\n",al,ans);
    //printf("%lf %lf\n",sumshu,sumxi);
    return 0;
}