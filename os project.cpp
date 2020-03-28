#include<stdio.h>
#include<stdlib.h>
void terminate()
{
    printf("error");
    exit(0);
}
main()
{
    int p[100],at[100],bt[100],wt[100],tat[100],start[100],comp[100],n,i,j,temp,swt=0,stat=0,burst;
    float awt,atat;
    printf("enter the number of processes\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++) comp[i] = 0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrival time of process%d\t",(i+1));
        scanf("%d",&at[i]);
        printf("enter the burst time of process%d\t",(i+1));
           scanf("%d",&burst);
        if(burst>10|| burst<0)
        {
            printf("invalid input for burst time");
            terminate();
        }
        bt[i]=burst;
        p[i]=(i+1);
        start[i]=0;
                
    }
    int count = 0, time = 3;
    while(count != n) {
       int burst = 100000, index = -1;
       for(int i = 0 ;  i < n ; i++) {
           if((at[i] < time || at[i] == time) && comp[i] == 0) {
               printf("arrival of P%d is %d\n", i + 1, at[i]);
               if(bt[i] < burst) {
                   burst = bt[i];
                   index = i;
               }
           }
       }
       if(burst != 100000 && index != -1) {
           comp[index] = time + bt[index];
           count++;
           time += burst;
       } else {
           time += 1;
       }
    }
    float tt=0, waiting = 0 ;
    for(int i=0;i<n;i++)
    {
    	printf("comp time is %d\t\n",comp[i]);
	}
    for(int i = 0  ; i < n; i++) {
        tat[i] = comp[i] - at[i];
        wt[i] = tat[i] - bt[i];
        waiting += wt[i];
        tt += tat[i];
    }
    
    printf("Average Waiting time is %f\t\n", waiting / n);
     printf("Average Turn Around time is %f\t\n", tt / n);
    
}
