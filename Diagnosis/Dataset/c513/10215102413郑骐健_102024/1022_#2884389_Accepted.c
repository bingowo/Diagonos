#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int cmp(const void*p1,const void*p2)
{
    char *p_1 = *((char**)p1);
    char*p_2 = *((char **)p2);
    char*m1 =p_1;
    char*m2 =p_2;
    while(*m1 != '@')
    {
        m1++;
    }
    while(*m2 !='@')
    {
        m2++;
    }
    int z = strcmp(m1,m2);
    if(z == 0)
    {
        return strcmp(p_2,p_1);
    }
    else return z;
}
char s[1000011];
int main()
{
    int n;
    scanf("%d",&n);
    char **email;
    email = (char**)malloc(n*sizeof(char*));
    for(int i =0;i < n;i++)
    {
        scanf("%s",s);
        int length = strlen(s);
        email[i] = (char *)malloc(sizeof(char*)*(length+1));
        strcpy(email[i],s);

    }
    qsort(email,n,sizeof(char*),cmp);
      for(int g =0;g<n;g++)
        {

            printf("%s\n",email[g]);
        }
     for(int i =0;i < n;i++)
    {
        free(email[i]);
    }
    free(email);

    return 0;
}
