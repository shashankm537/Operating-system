#include<stdio.h>
 int main()
{
    int burst_time[20],p[20],waiting_time[20],tat[20],i,j,n,total=0,arr_time[20];
    float avg_waiting_time,avg_tat,a=0,b=0;4
    
    printf("please enter number of process: ");
    scanf("%d",&n);
    printf("\n enter the Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        scanf("%d",&arr_time[i]);
    }

    for(i=0;i<n;i++)
    {
        total+=burst_time[i];
        tat[i]=total-arr_time[i];
        waiting_time[i]=tat[i]-burst_time[i];
        a+=waiting_time[i];
        b+=tat[i];
    }
    printf("%f\n",a/n);
    printf("%f",b/n);
}
    
