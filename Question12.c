#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int pid;
    int arrival;
    int burst,tb;
    int flag,status;
}process;
process p1[100],p2[100],p3[100];
int temp1,temp2,temp3,prior;
int timeQ1=8,timeQ2=16;
int Tcount=0;   //counter for all the processes
void push(process arr[],int a,int b,int c,int pos)
{
    arr[pos].pid=a;
    arr[pos].arrival=b;
    arr[pos].burst=c;
    arr[pos].tb=c;
}
void traversal(process arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("pid is:%d",arr[i].pid);
    }
}
void RR(process p[],int tQ/*3or4or5 ie tQ*/,int Totaltq,int k)
{
    int i=0,fl=0;
    //traversal(p1,k);
    //printf("%d K val",k);
    int TurnAround,wait;
    while(1){
        if(i==k){i=0;}
        if(Totaltq==0||fl==k)break; //Aging Implementation
        //printf("%d\n",i);         
        if(p[i].arrival<=Tcount && p[i].status!=1 && p[i].flag!=1)
        {
            //printf("    %d  ",k);
            if(tQ<=Totaltq){}
            else{tQ=Totaltq;}
            if(p[i].tb<=tQ)
            {
               // printf("entered first");
               // printf("%d\tTc val\n",Tcount);
                Tcount+=p[i].tb;
                TurnAround=Tcount-p[i].arrival;
                wait=TurnAround-p[i].burst;
                p[i].status=1;
                p[i].flag=1;
                Totaltq-=p[i].tb;
                fl++;
                printf("process with pid:%d completed\t waitTime is:%d\tTurnAroundTime is %d\n",p[i].pid,wait,TurnAround);
                i++;
                continue;
            }
            if(p[i].tb>tQ)
            {
                //printf("entered second");
                p[i].tb-=tQ;
                Tcount+=tQ;
                p[i].flag=0;
                Totaltq-=tQ;
                i++;
                continue;
            }
        }
        else{
            //printf("K");
            Tcount++;
            Totaltq--;
            //if(i==k){i=0;}
        }
        i++;
    }
    for(int i=0;i<k;i++)
    {
        p[i].flag=0;
    }
}

void FCFS(process p[],int k)
{
    int wait,Tat;
    for(int i=0;i<k;i++)
    {
        if(p[i].arrival<=Tcount && p[i].status!=1 && p[i].flag!=1)
        {
            Tcount+=p[i].tb;
            Tat=Tcount-p[i].arrival;
            wait=Tat-p[i].burst;
            p[i].flag=1;
            p[i].status=1;
            printf("process with pid:%d completed\t waitTime is:%d\tTurnAroundTime is %d\n",p[i].pid,wait,Tat);
        }   
        else{
            continue;
        }
    }
}

int main()
{
    int c1=0,c2=0,c3=0;
    int n,j,full=0;
    printf("Enter total number of processes");
    scanf("%d",&n);
    j=n;
    while(n!=0)
    {
        printf("Enter pid of process");
        scanf("%d",&temp1);
        printf("Enter arrival time:");
        scanf("%d",&temp2);
        printf("Enter burst time:");
        scanf("%d",&temp3);
        
        printf("Enter priority of process");
        scanf("%d",&prior);
        /*Adding elements into array according to the priority*/
        if(prior==1){push(p1,temp1,temp2,temp3,c1);c1++;}
        else if(prior==2){push(p2,temp1,temp2,temp3,c2);c2++;}
        else if(prior==3){push(p3,temp1,temp2,temp3,c3);c3++;}
        else{printf("Wrong priority---TERMINATING");exit(-1);}
        n--;
    }
    //traversal(p1,c1);
    //Aging Implemented
    while(Tcount<1000)
    {
    RR(p1,4,8,c1);
    RR(p2,4,16,c2); 
    FCFS(p3,c3);
    }

    return 0;
}