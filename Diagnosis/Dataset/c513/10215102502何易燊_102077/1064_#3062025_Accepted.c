#include <stdio.h>
#include <stdlib.h>

double recurrence()
{
    char s[10] = {};
    scanf("%s",s);
    if (s[0]=='+') {double l = recurrence(); double r = recurrence(); return l+r;}
    else if (s[0]=='-') {double l = recurrence(); double r = recurrence(); return l-r;}
    else if (s[0]=='*') {double l = recurrence(); double r = recurrence(); return l*r;}
    else if (s[0]=='/') {double l = recurrence(); double r = recurrence(); return l/r;}
    else return atof(s); 
}

int main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("case #%d:\n%.6lf\n",i,recurrence());
    }
    system("pause");
    return 0;
}