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

void mode_to_str(int mode, char *str) {
	strcpy(str, "----------.");
	if (mode & 0400) str[1]='r';
	if (mode & 0200) str[2]='w';
	if (mode & 0100) str[3]='x';
	if (mode & 0040) str[4]='r';
        if (mode & 0020) str[5]='w';
        if (mode & 0010) str[6]='x';
	if (mode & 0004) str[7]='r';
        if (mode & 0002) str[8]='w';
        if (mode & 0001) str[9]='x';
}

int main(int ac, char *av[]){
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	char modestr[12];
	int count = 0;
	char dir[256] = ".";	
	char fullpath[512];

	if (ac > 1) {
		strncpy(dir, av[1], sizeof(dir) - 1);
        	dir[sizeof(dir) - 1] = '\0';  // 确保字符串以'\0'结尾
	}
	if((dp=opendir(dir))==NULL){
		perror("Cannot open dir");
		exit(1);
	}
	while((p=readdir(dp))!=NULL){
		if(p->d_name[0]!='.'){
			snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, p->d_name); // 拼接成完整路径
			if (stat(fullpath, &buf) == -1) {
                		perror("stat error");
                		continue; // 跳过当前文件
            		}
			mode_to_str(buf.st_mode, modestr);
			printf("%s %d %s %s\t%d\t%.*s\t%s\n", modestr, buf.st_nlink, 
				getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name, 
				buf.st_size,12,4+ctime((const time_t *)&(buf.st_mtime)), p->d_name);
			count++;
		}
	}
	printf("total %d\n", count);
	closedir(dp);
	return 0;
}

