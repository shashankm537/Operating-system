#include<stdio.h>
#include<stdlib.h>
void waitingtime(int proc[],int n,int burst_time[],int wait_time[])
{
wait_time[0]=0;
for(int i=1;i<n;i++)
{
wait_time[i]=burst_time[i-1]+wait_time[i-1];
}
}

void turnaroundtime(int proc[],int n,int burst_time[],int wait_time[],int tat[])
{
for(int i=0;i<n;i++)
tat[i]=burst_time[i]+wait_time[i];
}

void avgtime(int proc[],int n,int burst_time[],int priority[])
{
int wait_time[n],tat[n],k;
float total_wt=0,total_tat=0;
for(int i=0;i<n;i++)
{
 for(int j=i+1;j<n;j++)
 {
     if(priority[j]<priority[i])
     {
        k=burst_time[i];
        burst_time[i]=burst_time[j];
        burst_time[j]=k;
        k=proc[i];
        proc[i]=proc[j];
        proc[j]=k;
        k=priority[i];
        priority[i]=priority[j];
        priority[j]=k;

     }
 }

}

waitingtime(proc,n,burst_time,wait_time);
turnaroundtime(proc,n,burst_time,wait_time,tat);
printf("\n Process\tBurst Time\tWait Time\tTurnaraound Time\tPriority\n");
for(int i=0;i<n;i++)
{
total_wt+=wait_time[i];
total_tat+=tat[i];
printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",proc[i],burst_time[i],wait_time[i],tat[i],priority[i]);
}
printf("\n Average wait time:%f \n Average turnaround time:%f",total_wt/n,total_tat/n);
}
void main()
{
int proc[10],burst_time[10],priority[10],n;
printf("\n Enter the size of n:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("\n Enter the processor number:");
scanf("%d",&proc[i]);
printf("\n Enter the burst time:");
scanf("%d",&burst_time[i]);
printf("\n Enter priority:");
scanf("%d",&priority[i]);

}
avgtime(proc,n,burst_time,priority);
}
