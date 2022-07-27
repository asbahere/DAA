#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void qs(int [],int ,int );

void main()
{
    int i,j,ch,a[15000],n,temp;
    clock_t start,end;
    while(1)
    {
        printf("Enter choice 1.Manual \t 2.Random \t 3. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter no of elements:\n");
                    scanf("%d",&n);
                    printf("Enter elements:\n");
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&a[i]);
                    }
                    start=clock();
                    qs(a,0,n-1);
                    end=clock();
                    printf("Sorted elements :\n");
                    for(i=0;i<n;i++)
                    printf("%d\t",a[i]);
                    printf("\nTime taken to sort %d elements %f seconds\n",n,((double)(end-start))/(CLOCKS_PER_SEC));
                    break;

             case 2: n=500;
                     while(n<=14500)
                     {
                         for(i=0;i<n;i++)
                         {
                             a[i]=n-i;
                         }
                         start=clock();
                         qs(a,0,n-1);
                         for(j=0;j<50000;j++)
                         {
                             temp=38/600;
                         }
                         end=clock();
                         printf("\nTime taken %d ele %f seconds",n,((double)(end-start))/(CLOCKS_PER_SEC));
                         n=n+1000;
                     }
                         break;

              case 3:exit(0);
        }


        }
    }

void qs(int a[],int low,int high )
{
    int i,j,pi,t;
    if(low<high)
    {
        pi=low;
        i=low;
        j=high;
        while(i<j)
        {
            while(a[i]<=a[pi] && i<high)
                i++;
            while(a[j]>a[pi])
                j--;
            if(i<j)
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
       t=a[pi];
       a[pi]=a[j];
       a[j]=t;
       qs(a,low,j-1);
       qs(a,j+1,high);
    }
}

