#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char s[51];
    int a[51]={0},count=0;
    scanf("%s",s);
    int i=0;
    if(s[1]=='\0')
        printf("1");
    else
    {
        while(s[i+1])
        {
            if(s[i+1]!=s[i])
            {
                for(int j=i+1; s[j]; j++)
                {
                    if(s[j]!=s[j+1])
                        a[count]++;
                    else
                        break;
                }
                i+=a[count];
                count++;
            }
            else
                i++;
        }
        qsort(a,count,sizeof(int),cmp);
        printf("%d",&a[0]);
    }
    return 0;
}
