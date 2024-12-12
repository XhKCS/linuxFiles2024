#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

main(){
	DIR *dp;
	struct dirent *p;
	if((dp=opendir("."))==NULL){
		perror("Cannot open dir");
		exit(1);
	}
	while((p=readdir(dp))!=NULL){
		if(p->d_name[0]!='.'){
			printf("%s\n", p->d_name);
		}
	}
	closedir(dp);
}
