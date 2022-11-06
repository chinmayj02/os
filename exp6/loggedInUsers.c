#include <stdio.h>
#include <sys/utsname.h>
#include <utmp.h>
#include <time.h>

int main(){
    struct utmp *n;
    int count=0;
    setutent();
    n = getutent();
    while (n != NULL) {
        if (n->ut_type == 7)count++;
        n=getutent();
    }
    setutent();
    n = getutent();
    printf("Number of logged in users = %d\n\n",count);
    while (n != NULL) {
        if (n->ut_type == 7){
            printf("%s ", n->ut_user);
            printf("%s ", n->ut_line);
            printf("%s ", n->ut_host);
            time_t t;
            t = n->ut_time;
            printf("%s", ctime(&t));
            printf("\n");
        }
        n = getutent();
    }
}

/* sample output

Number of logged in users = 3

chinmay :0 :0 Mon Oct 31 11:27:46 2022

chinmay tty3  Mon Oct 31 16:27:00 2022

chinmay tty5  Mon Oct 31 16:29:33 2022

*/