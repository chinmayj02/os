#include<stdio.h>
#include<unistd.h>

void child(int ppid){
    printf("\nChild process entered.Parent id= %d",ppid);
}

void parent(int pid){
    printf("\nParent process entered.Id= %d",pid);

}

int main(){
    int forkRetVal=fork();
    if(forkRetVal<0) printf("Fork failed!");
    else if(forkRetVal==0) child(getppid());
    else parent(getpid());
}