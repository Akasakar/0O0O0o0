#include <cstdint>
#include <cstring>
#include <cstdio>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// #ifndef _LOG_MACROS_
// #define _LOG_MACROS_
// #endif // _LOG_MACROS_

#include "../inc/xlog.h"

#include "../inc/xsock.h"

namespace test_socket
{
    xsock::xsock()
    {
        socket_address = new (struct sockaddr_in);
        memset(socket_address, 0, sizeof(sockaddr_in));
        _log_debug_("create new xsock *addr[%p].\n", socket_address);
    }

    xsock::xsock(int __domain, int __type, int __protocol)
    {
        socket_address = new (struct sockaddr_in);
        memset(socket_address, 0, sizeof(sockaddr_in));

        file_descriptor = socket(__domain, __type, __protocol);
        socket_address->sin_family = __domain;
        _log_debug_("create new xsock *addr[%p]. then create FD[%d].\n", \
                socket_address, file_descriptor);
        if(file_descriptor == -1)
            _log_error_("socket FD[-1] failed.%c", 10);
    }

    xsock::~xsock()
    {
        delete socket_address;
        int status = close(file_descriptor);
        _log_debug_("delete xsock *addr[%p]. then close FD[%d]. status[%d].\n",\
                socket_address, file_descriptor, status);
        if(status)
            _log_error_("FD[%d] close failed. status[%d].\n", \
                    file_descriptor, status);
        socket_address = nullptr;
    }

    void xsock::set_ip(const char* ip, uint16_t port)
    {
        inet_aton(ip, &(socket_address->sin_addr));
        socket_address->sin_port = htons(port);
        _log_debug_("set sockaddr ip address %s:%d.\n", ip, port);
    }
};
