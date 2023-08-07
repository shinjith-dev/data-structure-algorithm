
# Algorithm

## server

1. Import required **libraries**
2. **Declare** `client` and `server` structures variables and neccessary variables `lfd`, `confd`, `r_buff`, `s_buff` and `n`
3. Create a **tcp socket** using `socket()` system call by passing `AF_INET` as socket family and `SOCK_STREAM` as socket type
4. **Assign values** to `server structure`
5. **Bind** the socket with **server address** and **server structure** using `bind()` system call
6. **Listen** for connection using `listen()` system call
7. **Accept the connection** from client using `accept()` system call
8. **Receive message** from client using `recv()` system call and **store it** in `r_buff`
9. To send message to client **read and store** input message in `s_buff` buffer and send it to server using `send()` system call
10. **Close** the socket connection using `close()` system call

## client

1. Import required **libraries**
2. **Declare** `server` structure variable and neccassary variables `lfd`, `r_buff` and `s_buff`
3. Create a **tcp socket** using `socket()` system call by passing `AF_INET` as socket family and `SOCK_STREAM` as socket type
4. **Connect to server** using `connect()` system call
5. **Read and store** input message in `s_buff` buffer and send it to server using `send()` system call
6. **Receive meassage** sent by server using `recv()` system call and store it in `r_buff` buffer
7. **Close** the socket connection using `close()` system call