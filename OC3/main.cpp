#include <iostream>
#include <sys/types.h>
#include <unistd.h>

void oldman(){
 fprintf(stdout, "Im not dead yet! My ID is %i\n", (int) getpid());
}
void recreation(){
    fprintf(stdout, "Who am I? My ID is %i\n", (int) getpid());
}

int main() {
    pid_t child_pid, parent_pid, child1, child2;

//    double s = 0.0;
//    child_pid = fork();
//    if (child_pid != 0){
//        s += 3.14;
//        fprintf(stdout, "CHILD: %i s=%g &s=%u\n", (int) getpid(),s,&s);
//    }else{
//        s += 2.72;
//        fprintf(stdout, "PARENT: %i s=%g &s=%u\n", (int) getpid(),s,&s);
//    }

    int i = 0;
    parent_pid = (int) getpid();
    fprintf(stdout, "Before RECREATION %i\n", parent_pid);
    child_pid = fork();
    child1 = fork();
    child2 = fork();
    while (i++ < 5){
        if (child_pid != 0)
            oldman();
        else
            recreation();
    }
    while (true){

    }
    return 0;
}
