#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//CREATE FILE START
void createFile(char * permissionStr, char * filePath){
	int permission = strtol(permissionStr,0,8);
	int file = creat(filePath,permission);
	if(file<0){
		puts("ERROR, could not create the file");
		exit(EXIT_FAILURE);
	}
	close(file);
}
//-c permission path
void checkArgsCreate(int argc,char * argv[]){
	if(!strcmp(argv[1],"-c")){
		assert(argc==4);
		createFile(argv[2],argv[3]);
	}
}
//CREATE FILE END

//WRITE FILE START
char * getInput(){
	static char input[1024];
	fflush(stdin);
	fgets(input,1024,stdin);
	fflush(stdin);
	return input;
}
void writeDataToFile(int file,char * textToWrite){
	if(file<0){
		puts("ERROR, could not open the file");
		exit(EXIT_FAILURE);
	}
	write(file, textToWrite, strlen(textToWrite));
	close(file);
}
void writeToFile(char * path){
	char * textToWrite = getInput();
	int file = open(path,O_WRONLY | O_CREAT,0755);
	writeDataToFile(file,textToWrite);
}
//-w path
void checkArgsWrite(int argc,char * argv[]){
	if(!strcmp(argv[1],"-w")){
		assert(argc==3);
		writeToFile(argv[2]);
	}
}
//WRITE FILE END

//READ FILE START
size_t getFileSize(int file){
    struct stat sb;
    fstat(file,&sb);
    return sb.st_size;
}
void printFileData(int file,size_t size){
	char * buffer = (char *) calloc(size,1);
	read(file, buffer, size);
	puts(buffer);
	free(buffer);
}
void readFile(char * path){
	int file = open(path,O_RDONLY);
	if(file<0){
		puts("ERROR, could not open the file");
		exit(EXIT_FAILURE);
	}
	size_t fileSize = getFileSize(file);
	printFileData(file,fileSize);
	close(file);
}
//-r path
void checkArgsRead(int argc,char * argv[]){
	if(!strcmp(argv[1],"-r")){
		assert(argc==3);
		readFile(argv[2]);
	}
}
//READ FILE END

//BATCH FILE CREATE START
void createOneFile(char * fileName){
	int file = creat(fileName,0755);
	if(file<0){
		printf("could not create %s",fileName);
		return;
	}
	close(file);
}
void createBatchFile(char * dirPath, char * prefix, char * ext,int v1,int v2){
	char fileName[4096];
	for(int i=v1;i<=v2;i++){
		sprintf(fileName,"%s%s_%d.%s",dirPath,prefix,i,ext); //preparing fileName
		puts(fileName);
		createOneFile(fileName);
	}
}
//-m dirPath prefix ext v1 v2
void checkArgsBatch(int argc,char * argv[]){
	if(!strcmp(argv[1],"-m")){
		assert(argc==7);
		createBatchFile(argv[2],argv[3],argv[4],strtol(argv[5],0,10),strtol(argv[6],0,10));
	}
}
//BATCH FILE CREATE END

void checkArgs(int argc,char * argv[]){
	checkArgsCreate(argc,argv);
	checkArgsWrite(argc,argv);
	checkArgsRead(argc,argv);
	checkArgsBatch(argc,argv);
}

int main(int argc,char * argv []){
	assert(argc>1);
	checkArgs(argc,argv);
	return 0;
}
