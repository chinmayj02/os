#include <stdio.h>
#include <unistd.h>

void child(){
    printf("Child Process entered and exited.\n");
}

void parent(int pid){
    printf("Parent process entered.\n");
    printf("Process id of child stored in parent = %d\n",pid);
    printf("Parent process exited.\n");
    // while(1);
}

int main(){
    int pid;
    pid = fork();
    if (pid < 0){ 
        // error occurred
        printf("Fork failed!\n");
        return -1;
    }
    else if (pid == 0) child();
    else parent(pid);
}
/* sample output

Child Process entered and exited.
Parent process entered.
Process id of child stored in parent = 24330
Parent process exited.


*/