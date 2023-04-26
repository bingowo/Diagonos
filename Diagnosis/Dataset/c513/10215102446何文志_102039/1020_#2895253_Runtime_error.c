#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct MyFile
{
    int time[5];
    int size;
    char name[100];//a whole string
    char fileName[100];
}myfile;

int cmpName(const void *a,const void *b)
{
    myfile A = *(myfile*)a,B = *(myfile*)b;

    return strcmp(A.fileName,B.fileName);
}
int cmpSize(const void *a,const void *b)
{
    myfile A = *(myfile*)a,B = *(myfile*)b;

    if(A.size!=B.size){return A.size - B.size;}
    else return strcmp(A.fileName,B.fileName);
}
int cmpTime(const void *a,const void *b)
{
    myfile A = *(myfile*)a,B = *(myfile*)b;
    if(A.time[0]!=B.time[0]){return A.time[0]-B.time[0];}
    else if(A.time[1]!=B.time[1]){return A.time[1]-B.time[1];}
    else if(A.time[2]!=B.time[2]){return A.time[2]-B.time[2];}
    else if(A.time[3]!=B.time[3]){return A.time[3]-B.time[3];}
    else if(A.time[4]!=B.time[4]){return A.time[4]-B.time[4];}
    else return strcmp(A.fileName,B.fileName);
}
int main()
{
    int n = 1;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n==0){break;}
        myfile files[n];memset(files,0,n*sizeof(myfile));
        getchar();
        for(int i = 0;i<n;i++)
        {
            gets(files[i].name);
        }
        char order[20];memset(order,0,20*sizeof(char));
        gets(order);
        for(int j = 0;j<n;j++)
        {
            //initialize Files
            int i1 = 0,cnt = 0;
            for(int i1 = 0;i1<5;i1++)
            {
                while(isdigit(files[j].name[cnt]))
                {
                    files[j].time[i1] = files[j].time[i1]*10+files[j].name[cnt]-'0';
                    cnt++;
                }
                cnt++;
            }
            while(!isdigit(files[j].name[cnt++]));
            cnt--;
            while(isdigit(files[j].name[cnt]))
            {
                files[j].size = files[j].size*10+files[j].name[cnt]-'0';
                cnt++;
            }
            cnt++;
            int k = 0;
            while(files[j].name[cnt]!=0)
            {
                files[j].fileName[k] = files[j].name[cnt];
                cnt++;k++;
            }
            //end of initialize Files
            //printf("time = ");
            //for(int k =0;k<5;k++){printf("%d ",files[j].time[k]);}
            //printf("size = %d , name = %s\n",files[j].size,files[j].name);
        }
        if(strcmp(order,"LIST /NAME")==0){qsort(files,n,sizeof(files[0]),cmpName);}
        else if(strcmp(order,"LIST /SIZE")==0){qsort(files,n,sizeof(files[0]),cmpSize);}
        else if(strcmp(order,"LIST /TIME")==0){qsort(files,n,sizeof(files[0]),cmpTime);}
        for(int j = 0;j<n;j++)
        {
            //printf("time = ");
            //for(int k =0;k<5;k++){printf("%d ",files[j].time[k]);}
            //printf("size = %d , filename =%s\n",files[j].size,files[j].fileName);
            printf("%s\n",files[j].name);
        }
        printf("\n");
    }


    return 0;
}
