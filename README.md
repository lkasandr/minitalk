# minitalk
A small data exchange program using UNIX signals.

______

## Server

The server takes signals(SIGUSR1, SIGUSR2) sent from client.

## Client

The clien sends signals to process of server.

______

## How to run it

Using following steps:

1) make
2) ./server (and you get the process id of server)
3) ./clien ID_from_server "your message"

![Image alt](https://github.com/lkasandr/minitalk/raw/master/gh/img.png)
