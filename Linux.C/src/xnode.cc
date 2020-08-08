#include <cstdio>
#include <cstdint>
#include <cstring>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// #ifndef _LOG_MACROS_
// #define _LOG_MACROS_
// #endif // _LOG_MACROS_

#include "../inc/xlog.h"

#include "../inc/xsock.h"
#include "../inc/xnode.h"

namespace test_socket
{
    xnode::xnode() 
    {
        _log_debug_("create null xnode.%c", 10);
    }

    xnode::xnode(int __domain, int __type, int __protocol): \
        xsock(__domain, __type, __protocol), sock_fd(-1) 
    {
        sock_fd = file_descriptor;
        _log_debug_("create xnode.%c", 10);
    };

    xnode::~xnode()
    {
        sock_fd = 0;
        _log_debug_(" ~xnode\%c", 10);
    }

    int xnode::xbind(const char* ip, uint16_t port)
    {
        set_ip(ip, port);
        const int& FD = file_descriptor;
        struct sockaddr * ADDR = (struct sockaddr *) socket_address;
        socklen_t LEN = sizeof(sockaddr_in);
        int status = bind(FD, ADDR, LEN);
        _log_debug_("bind %s:%d status[%d].\n", ip, port, status);
        if(status == -1)
            _log_error_("server FD[%d] bind failed.\n", FD);
        return status;
    }

    int xnode::xlisten(int _N)
    {
        const int& FD = file_descriptor;
        int status = listen(FD, _N);
        _log_debug_("listen status[%d].\n", status);
        if(status == -1)
            _log_error_("server FD[%d] listen failed.\n", FD);
        return status;
    }

    int xnode::xaccept(class xnode& client)
    {
        const int& FD = file_descriptor;
        struct sockaddr * ADDR = (struct sockaddr *) client.socket_address;
        socklen_t LEN = sizeof(sockaddr_in);
        int new_FD = accept(FD, ADDR, &LEN);
        if(new_FD == -1)
        {
            _log_error_("server FD[%d] accept failed.\n", FD);
            return new_FD;
        }
        client.file_descriptor = new_FD;
        sock_fd = new_FD;
        _log_debug_("accept. new FD[%d].\n", new_FD);
        return new_FD;
    }

    int xnode::xconnect(const char* ip, uint16_t port)
    {
        set_ip(ip, port);
        const int& FD = file_descriptor;
        struct sockaddr * ADDR = (struct sockaddr *) socket_address;
        socklen_t LEN = sizeof(sockaddr_in);
        int status = connect(FD, ADDR, LEN);
        sock_fd = FD;
        _log_debug_("connect %s:%d status[%d].\n", ip, port, status);
        if(status)
            _log_error_("client FD[%d] connect failed.\n", FD);
        return status;
    }

    int xnode::xsend(const char * buf, size_t _N)
    {
        if(sock_fd == -1) return sock_fd;
        ssize_t status = send(sock_fd, buf, _N, 0);
        _log_debug_("from \"%s\" send %ld bytes.\n", buf, status);
        return status;
    }

    int xnode::xrecv(char * buf, size_t _N)
    {
        if(sock_fd == -1) return sock_fd;
        ssize_t status = recv(sock_fd, buf, _N, 0);
        _log_debug_("from \"%s\" recv %ld bytes.\n", buf, status);
        return status;
    }

    int xnode::xsendto(const class xnode& to, char* buf, size_t n_bytes)
    {
        //const int& FD = file_descriptor;
        if(sock_fd == -1) return sock_fd;
        struct sockaddr * ADDR = (struct sockaddr *) to.socket_address;
        socklen_t LEN = sizeof(sockaddr_in);
        ssize_t status = sendto(sock_fd, buf, n_bytes, 0, ADDR, LEN);
        _log_debug_("from \"%s\" send %ld bytes\n", buf, status);
        return status;
    }

    int xnode::xrecvfrom(const class xnode& from, char* buf, size_t n_bytes)
    {
        //const int& FD = file_descriptor;
        if(sock_fd == -1) return sock_fd;
        struct sockaddr * ADDR = (struct sockaddr *) from.socket_address;
        socklen_t LEN = sizeof(sockaddr_in);
        ssize_t status = recvfrom(sock_fd, buf, n_bytes, 0, ADDR, &LEN);
        _log_debug_("from \"%s\" recv %ld bytes\n", buf, status);
        return status;
    }
};
