#include <cstdio>
#include <cstdint>
#include <cstring>
#include <sys/time.h>
#include <arpa/inet.h>

#include "../inc/xlog.h"
#include "../inc/xargparse.h"
#include "../inc/xnode.h"

double get_ms(const struct timeval& tv)
{
    return tv.tv_sec * 1000LL + tv.tv_usec / 1000.0;
}

int main(int argc, char *argv[])
{
    test_argparse::Argparse args;
    args.add_argument("--ip", "127.0.0.1");
    args.add_argument("--port", "1080");
    args.add_argument("--cnt", "1");
    args.parse_args(argc, argv);

    const char *ip = args["ip"].c_str();
    uint16_t port = test_argparse::to_int32(args["port"]);
    int cnt = test_argparse::to_int32(args["cnt"]);

    char buf[1 << 10] = {0};
    
    for(int i = 1;i <= cnt; i++)
    {
        test_socket::xnode client(2, 1, 0);

        struct timeval tv[3] = {0};
        gettimeofday(tv, nullptr);
        memcpy(buf, tv, sizeof(struct timeval));
        int status = client.xconnect(ip, port);
        if(status == -1)
            continue;
        
        printf("%d %d\n", (client.socket_address)->sin_family, \
                (client.socket_address)->sin_addr.s_addr);
        client.xsend(buf, sizeof(struct timeval));

        int N = client.xrecv(buf, sizeof(buf));

        memcpy(tv, buf, N);
        
        // printf("rtime %.2lf\n", get_ms(tv[0]));
        // printf("otime %.2lf\n", get_ms(tv[1]));
        // printf("ttime %.2lf\n", get_ms(tv[2]));

        printf("64 bytes from %s: icmp_seq=%d ttl=128 time=%.2lf ms\n", \
                args["ip"].c_str(), i, get_ms(tv[2]) - get_ms(tv[0]));
    }
    return 0;
}
