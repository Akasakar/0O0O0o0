#include <cstdio>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>

#include "../inc/xlog.h"
#include "../inc/xargparse.h"
#include "../inc/xnode.h"

int main(int argc, char *argv[])
{
    test_argparse::Argparse args;
    args.add_argument("--ip", "127.0.0.1");
    args.add_argument("--port", "1080");
    args.add_argument("-cnt", "1");
    args.parse_args(argc, argv);

    const char *ip = args["ip"].c_str();
    uint16_t port = test_argparse::to_int32(args["port"]);
    int cnt = test_argparse::to_int32(args["cnt"]);

    char buf[1 << 10] = {0};

    for(int i = 0; i < cnt; i++)
    {
        test_socket::xnode client(AF_INET, SOCK_DGRAM, IPPROTO_IP);
        client.set_ip(ip, port);
        strcpy(buf, "client fuck server");
        client.xsendto(client, buf, 24);
        client.xrecvfrom(client, buf, sizeof(buf));
    }
    return 0;
}
