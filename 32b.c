#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int i;
  pid_t pid[i];
	int status[i];
	for (i = 0; i < 3; i++){
		pid[i] = fork();
		if (pid[i] != 0 & i > 0)
			exit(0);
		if ((pid[i] == 0 & pid[i - 1] == 0 & pid[0] == 0) || (pid[i] != 0 & i == 0)){
			if (pid[i] != 0){
				waitpid (pid[i], &status[i], WUNTRACED | WCONTINUED);
				printf("The main Parent %d\n", status[i]);
			} else printf ("Child %d\n", i);
		}
	}
	free;
	return 0;
}
