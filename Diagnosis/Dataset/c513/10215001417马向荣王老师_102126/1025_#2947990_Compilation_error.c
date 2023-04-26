#include<stdio.h>
#include<atring.h>
int compare(char a,int lena, char b, int lenb)
{
int max;
if (lena < lenb)
max = lenb;
for(int i = 0; i < max; i++)
{
if(a[i] > b[i])
return 1;
if(a[i] < b[i])
return -1;
}
return 0;
}
int differ(char* a, int lena)
{
int q[21] = {0};
int num = 0;
for(int i = 0; i < lena; i++)
{
int flag = 0;
for(int j = 0; j < lena; j++)
{
if (a[i] == q[j] )
flag = 1;
}
if (flag == 0)
num++;
q[i] = a[i];
}
return num;
}
int main()
{
int t;
scanf("%d", &t);
int w = 0;
while (t--)
{
    int n;
    scanf("%d", &n);
    char a[n][21];
    int a1[n] ;
    for (int i = 0; i < n; i++){
        scanf("%s", &a[i]);
        getchar();
        a1[i] = differ(a[i], strlen(a[i]));
    }
    for(int i = 0; i < n - 1; i++)
    {               
        for(int j = 0; j < n - i - 1; j++)
        {    
            if(a1[j] < a1[j+1])
             {
                 char b[21];
                 strcpy(b, a[j]);
                 strcpy(a[j], a[j+1]);
                 strcpy(a[j+1], b);
                 int t = a1[j];
                 a1[j] = a1[j+1];
                 a1[j+1] = t;
             }
        }
    }
    for (int i = 0; i < n; i++){
        a1[i] = differ(a[i], strlen(a[i]));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a1[j] == a1[j+1])
             {
                 if(compare(a[j], strlen(a[j]), a[j+1], strlen(a[j+1])) > 0)
                 {
                     char b[21];
                     strcpy(b, a[j]);
                     strcpy(a[j], a[j+1]);
                     strcpy(a[j+1], b);
                 }
             }
        }
    }
    printf("case #%d:\n", w);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n",a[i]);
    }
    w++;
}
return 0;
}