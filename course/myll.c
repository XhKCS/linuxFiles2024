#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

main(){
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	if((dp=opendir("."))==NULL){
		perror("Cannot open dir");
		exit(1);
	}
	while((p=readdir(dp))!=NULL){
		if(p->d_name[0]!='.'){
			stat(p->d_name, &buf); 
			printf("%d %d %s %s\t%d\t%.*s\t%s\n",buf.st_mode & 0777, buf.st_nlink, 
				getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name, 
				buf.st_size,12,4+ctime((const time_t *)&(buf.st_mtime)), p->d_name);
		}
	}
	closedir(dp);
}
