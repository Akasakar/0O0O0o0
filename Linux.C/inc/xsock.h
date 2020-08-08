#ifndef _XSOCK_
#define _XSOCK_

namespace test_socket
{
    class xsock
    {
        public:
            xsock();
            xsock(int __domain, int __type, int __protocol);
            ~xsock();
            void set_ip(const char* ip, uint16_t port);
        public:
            int file_descriptor;
            struct sockaddr_in * socket_address;
    };
};

#endif //_XSOCK_
