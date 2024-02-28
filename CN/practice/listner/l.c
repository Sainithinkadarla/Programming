#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sockect.h>
//#include<netinet/in.h>

int main(int argc, char *argv[])
{
int sockmain, i;
char buffer[512];
struct sockaddr_in saddr, caddr;
int alength, mlength;

sockmain = sock(AF_INET, SOCK_DGRAM, 0);

saddr.sin_addr.s_addr = htonl(INADDR_ANY);
saddr.family = AF_NET;
saddr.sin_port = htons(atoi(argv[1]));

i = sizeof(saddr);

bind(sockmain, (char *)buffer, sizeof(buffer), 0, (struct sockaddr*)&caddr, (socklen_t *)&alength);


}