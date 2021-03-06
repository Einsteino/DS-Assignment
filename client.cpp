#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#define PORT 8080

using namespace std;

int main(){
  struct sockaddr_in address;
      int sock = 0, valread;
      struct sockaddr_in serv_addr;
      char hello[] = "Hello from client";
      char buffer[1024] = {0};
      sock = socket(AF_INET, SOCK_STREAM, 0);
      memset(&serv_addr, '0', sizeof(serv_addr));

      serv_addr.sin_family = AF_INET;
      serv_addr.sin_port = htons(PORT);

      inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
      connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
      send(sock , hello , strlen(hello) , 0 );
      printf("Hello message sent\n");
      valread = read( sock , buffer, 1024);
      printf("%s\n",buffer );
      return 0;
}
