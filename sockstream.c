#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
	struct sockaddr_un mysocket;
	char path[108] = "./";
	mysocket.sun_family = 1;
	strcpy(mysocket.sun_path, "localhost");
	//mysocket.sun_path = ;
	char *options = "hello";
	printf("Options = %s", options); 
	printf("Sizeof mysocket: %lu", sizeof(mysocket));
}
