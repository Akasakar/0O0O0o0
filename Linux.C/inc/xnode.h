#ifndef _XNODE_
#define _XNODE_

#include "xsock.h"

namespace test_socket
{
    class xnode: public xsock 
    {
        public:
            xnode();
            xnode(int __domain, int __type, int __protocol);
            ~xnode();
            int xbind(const char* ip, uint16_t port = 0x00);
            int xlisten(int _N = 0x10);
            int xaccept(class xnode& client);
            int xconnect(const char* ip, uint16_t port = 0x00);
            int xsend(const char * buf, size_t n_bytes);
            int xrecv(char * buf, size_t n_bytes);
            int xsendto(const class xnode& to, char* buf, size_t n_bytes);
            int xrecvfrom(const class xnode& from, char* buf, size_t n_bytes);
        public:
            int sock_fd;
    };
};

#endif //_XNODE_
