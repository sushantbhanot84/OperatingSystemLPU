#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int pid;
    int arrival;
    int Burst;
    int priority;
    int readyS;     //Ready to get into ready state
}process;
int newQ[100];
int check[100];
int arr[4][10];
int lim;
void sort()
{
    
}
void insertReady(process p)
{
    if(p.priority==1)
    {//Round Robin implementation ie sort acc to arrival time and check...
        for(int i=0;i<=9;i++)
        {
            if(i==9 && arr[0][i]!=-6996)
            {
                printf("Queue full");
                break;
            }
            else if(arr[0][i]==-6996)
            {
                arr[0][i]=p.pid;
                //Sorting acc to arrival time
                break;
            }
            else if(arr[0][i]==p.pid)
            {
                printf("2 processes have same pid -- Terminating");
                exit(0);
            }
            else
            {
                continue;
            }
        }
    }
    if(p.priority==2)//SJF implementation ie sort acc to burst time 
    {
        for(int i=0;i<=9;i++)
        {
            if(i==9 && arr[1][i]!=-6996)
            {
                printf("Queue full");
                break;
            }
            else if(arr[1][i]==-6996)
            {
                arr[1][i]=p.pid;break;
            }
            else if(arr[1][i]==p.pid)
            {
                printf("2 processes have same pid -- Terminating");
                exit(0);
            }
            else
            {
                continue;
            }
        }
    }
        if(p.priority==3)   //FCFS implementation ie sort acc to arrival time
    {
        for(int i=0;i<=9;i++)
        {
            if(i==9 && arr[2][i]!=-6996)
            {
                printf("Queue full");
                break;
            }
            else if(arr[2][i]==-6996)
            {
                arr[2][i]=p.pid;
                //sort acc to arrival time
                break;

            }
            else if(arr[2][i]==p.pid)
            {
                printf("2 processes have same pid -- Terminating");
                exit(0);
            }
            else
            {
                continue;
            }
        
        }
    }
        if(p.priority==4)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==9 && arr[3][i]!=-6996)
            {
                printf("Queue full");
                break;
            }
            else if(arr[3][i]==-6996)
            {
                arr[3][i]=p.pid;break;
            }
            else if(arr[3][i]==p.pid)
            {
                printf("2 processes have same pid -- Terminating");
                exit(0);
            }
            else
            {
                continue;
            }
        }
    }
}
int insertNew(int val)
{
    for(int i=0;i<100;i++){
        if(newQ[i]==-6996 && newQ[i]!=val){
            newQ[i]=val;
            lim=i;
            return 0;
        }
        else if(newQ[i]==val)
        {
            break;
        }
        else
        {
            continue;
        }    
    }
}
void removeNew(process p)
{
    for(int i=0;i<100;i++){
        if(p.pid==newQ[i])
        {
            newQ[i]=-6996;
            int j=i+1;
            while(newQ[j]!=-6996){newQ[j-1]==newQ[j];j++;}
            break;
}}}
void initialization()
{
    for(int i=0;i<100;i++)
    {
        check[i]=-6996;
        newQ[i]=-6996;
        if(i<10){
        arr[0][i]=-6996;
        arr[1][i]=-6996;
        arr[2][i]=-6996;
        arr[3][i]=-6996;        
    }}}
int main()
{    
    int val;
    printf("Welcome to the program of process scheduling\n");
    printf("Enter the number of processes");
    scanf("%d",&val);
    process p[val];
    initialization();
    for (int i=0;i<val;i++)
    {
        printf("Enter pid:\t");
        scanf("%d",&p[i].pid);
        printf("\nEnter arrival time:\t");
        scanf("%d",&p[i].arrival);
        printf("\nEnter Burst time:\t");
        scanf("%d",&p[i].Burst);
        printf("Enter priority of process:\t");
        scanf("%d",&p[i].priority);
        p[i].readyS=0;
        if(check[p[i].pid]!=-6996){printf("\nOverlapping PIDs ---Exiting");exit(-1);}else{check[p[i].pid]=p[i].pid;}
    }
    for(int i=0;i<val;i++)
    {
        if(p[i].readyS==0)
        {
            int k=insertNew(p[i].pid);
            if (k==0)p[i].readyS=1;
            else p[i].readyS=0;
        }
    }
    for(int i=0;i<val;i++)
    {
        insertReady(p[i]);
        removeNew(p[i]);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf(" %d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("ALL PROCESSES IN NEW QUEUE");
    return 0;
}