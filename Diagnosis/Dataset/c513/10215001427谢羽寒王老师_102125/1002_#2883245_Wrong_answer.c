#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,y,x,result,r,c,l,k,z,f;
    int N=61;
    char s[N];
    int d[N],a[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){

        scanf("%s",s);
        d[0]=1;

    for(j=1;j<strlen(s);j++){
            for(y=0;y<j;y++){

                    if(s[j]==s[y]){d[j]=d[y];break;}
                    else{
                            if(d[y]==1){d[j]=0;}
                            if(d[y]==0){d[j]=2;}
                            if(d[y]>1){d[j]=d[y]+1;
                            }

                    }

               }



        }
        c=j;
        
        for(l=0;l<j;l++){
            for(k=l+1;k<j;k++){
                if(d[k]==d[l]){c--;break;}


            }

        }
         if(c==1) c=2;
         result=0;

        for(x=j-1,r=1;x>=0;x--){

                z=d[x]*r;
                result=result+z;
                r=r*c;

        }







        printf("case #%d:",i);
        printf("\n");
        printf("%d",result);
        printf("\n");
         for(f=0;f<j;f++){
        d[f]='\0' ;
    }

     }
    }
