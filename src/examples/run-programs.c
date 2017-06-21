#include <stdio.h>
#include <syscall.h>

#define PROGRAM_COUNT 2

enum programs{
  bubsort,
  ls
};

int main(int argc, char const *argv[])
{
  printf("Hello!\n");
  struct threadToPrint threadinfo[PROGRAM_COUNT];
  pid_t pids[PROGRAM_COUNT];
  int isDone[PROGRAM_COUNT];

  pids[bubsort] = exec("bubsort");
  // pids[ls] = exec("ls");

  printf("%d, %d\n", pids[bubsort], pids[ls]);

  printf("----THIS IS THE RETURN VALUES----\n");
  while(!isDone[bubsort]|| !isDone[ls]){
    if(!isDone[bubsort])
      isDone[bubsort] = getthreadinfo(pids[bubsort], &threadinfo[bubsort]);
    if(!isDone[ls])
      isDone[ls] = getthreadinfo(pids[ls], &threadinfo[ls]);


    if(!threadinfo[bubsort].isPrint && !threadinfo[ls].isPrint)
      continue;
    
    printf("TID: %d, Priority = %d, Run Count = %d, Wait Count = %d\n", threadinfo[bubsort].tid, threadinfo[bubsort].priority, threadinfo[bubsort].run_count, threadinfo[bubsort].wait_count);
    // printf("TID: %d, Priority = %d, Run Count = %d, Wait Count = %d\n", threadinfo[ls].tid, threadinfo[ls].priority, threadinfo[ls].run_count, threadinfo[ls].wait_count);
    
    threadinfo[bubsort].isPrint = 0;
    threadinfo[ls].isPrint = 0;
  }
  wait(pids[bubsort]);
  // wait(pids[ls]);

  return 0;
}