#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




int main()
{
char m[11][6] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int n;
scanf("%d",&n);
for(int i =0;i<n;i++)
{
    char s[26];
    int count[26] = {0};
    int num[11] ={0};
    scanf("%s",s);
    for(int q =0;q<strlen(s);q++)
    {
        count[s[q]-'A']++;
    }
     for(int r = 0;r<strlen(s);r++)
     {
         switch (s[r])
         {
         case 'W':
            for(int g=0;g<strlen(m[2]);g++)
            {
                count[m[2][g]-'A']--;
            }
            num[2]++;
            break;
         case 'U':
            for(int g=0;g<strlen(m[4]);g++)
            {
                count[m[4][g]-'A']--;
            }
            num[4]++;
            break;
        case 'Z':
            for(int g=0;g<strlen(m[0]);g++)
            {
                count[m[0][g]-'A']--;
            }
            num[0]++;
            break;
        case 'G':
            for(int g=0;g<strlen(m[8]);g++)
            {
                count[m[8][g]-'A']--;
            }
            num[8]++;
            break;
        case 'X':
            for(int g=0;g<strlen(m[6]);g++)
            {
                count[m[6][g]-'A']--;
            }
            num[6]++;
            break;
         }
     }
        num[1]+= count['O'-'A'];
         num[5]+=count['F'-'A'];
         num[3]+=count['T'-'A'];
         num[7]+= count['S'-'A'];
         num[9]+=count['I'-'A']-num[5];
         printf("case #%d:\n",i);
         for (int z =0;z <10;z++)
         {
             if(num[z]!=0)
             {
                 for(int x=0;x<num[z];x++)
                 {
                     printf("%d",z);
                 }
             }
         }
         if(i!=n-1)printf("\n");


}
}
