#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
void child(int sig){

	int st;
	pid_t pid;
	if(sig == SIGCHLD)
	while(pid = waitpid(-1,&st,WNOHANG) > 0 );
	
	

}
int main(int argc,char **argv){
	if(argc<3|| strcmp(argv[1],"-c")!=0){
	printf("wrong input");
	exit(-1);  // Î´¼ì²âµ½ -c
}
	int num = atoi(argv[2]);
	pid_t pid;
	int i = 0;
	int status;
	struct sigaction act;
	act.sa_handler = child;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(sigaction(SIGCHLD,&act,0)){
	printf("ERROR");
	exit(1);
	}
	int desc = open("multiproc_td.txt",O_RDONLY);

	for(;i<num - 1;i++){
		pid = fork();
		if(pid == -1) exit(-1);
		if(pid == 0)break;
}
	
 if(pid > 0){ //parent progress
	
	
			char buf[6];
			buf[5]='\0';
			printf("%d start\n",getpid());
			
			read(desc,buf,5);		
			printf("%d read [%s]\n",getpid(),buf);
										
			sleep(5);
			printf("%d end\n",getpid());
			close(desc);
			
			exit(0);
		}
		else{	//child progress
			

			printf("%d start\n",getpid());
			char buf[6];
                        buf[5]='\0';

			read(desc,buf,5);
                        printf("%d read [%s]\n",getpid(),buf);
			printf("%d end\n",getpid());
			sleep(1);
			
			close(desc);
			exit(0);
		}
	
	
} 
