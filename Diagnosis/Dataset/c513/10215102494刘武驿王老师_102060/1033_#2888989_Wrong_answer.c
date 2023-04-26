#include<stdio.h>
#include<stdlib.h>
struct time
{
  int date;
  int year;
  char months[10];
  int month;
};
int cmp(void *a,void *b)
{
  if(((struct time *)a)->year!=((struct time *)b)->year) return ((struct time *)a)->year-((struct time *)b)->year;
  if(((struct time *)a)->month!=((struct time *)b)->month) return ((struct time *)a)->month-((struct time *)b)->month;
  return ((struct time *)a)->date-((struct time *)b)->date;

}
int main()
{
    int n;
    scanf("%d",&n);
    char tab[19][10]={{"pop\0"},{"no\0"},{"zip\0"},{"zotz\0"},{"tzec\0"},{"xul\0"},{"yoxkin\0"},{"mol\0"},{"chen\0"},{"yax\0"},{"zac\0"},{"ceh\0"},{"mac\0"},{"kankin\0"},{"muan\0"},{"pax\0"},{"koyab\0"},{"cumhu\0"},{"uayet\0"}};
    for(int i=0;i<n;i++)

    {
        int pros;
        struct time input[20000];
        scanf("%d",&pros);
        for(int j=0;j<pros;j++)
        {
            scanf("%d. ",&input[j].date);
            scanf("%s",&input[j].months);
            scanf("%d",&input[j].year);
            int p=0;
            while(strcmp(tab[p],input[j].months)!=0) p++;
            input[j].month=p;
        }
        qsort(input,pros,sizeof(input[0]),cmp);
        for(int j=0;j<pros;j++)
        {
            printf("case $%d:\n",i);
            printf("%d. ",input[j].date);
            printf("%s ",input[j].months);
            printf("%d\n",input[j].year);
        }
    }
}