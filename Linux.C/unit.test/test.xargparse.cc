#include <cstdio>

#include "../inc/xlog.h"
#include "../inc/xargparse.h"

using test_argparse::Argparse;
using test_argparse::to_int32;
using test_argparse::to_int64;
using test_argparse::to_char_pointer;
using test_argparse::to_void_pointer;

int main(int argc, char * argv[])
{
    Argparse args;
    args.add_argument("--ip", "127.0.0.1");
    args.add_argument("--port", "80");
    args.add_argument("--path", "./tmp");
    args.add_argument("fuck", "233");
    args.parse_args(argc, argv);
    _log_none_("ip %s\n", args["ip"].c_str());
    _log_none_("port %s\n", args.get("ip").c_str());
    args.del_argument("path");
    args.del_argument("path");
    args.del_argument("fuck");
    _log_none_("path %s\n", args.get("ip").c_str());
    _log_none_("to int32 %d\n", to_int32(args["port"]));
    _log_none_("to int64 %lld\n", to_int64(args["port"]));
    _log_none_("to char %s\n", to_char_pointer(args["ip"]));
    const char * p = (const char *) to_void_pointer(args["ip"]);
    _log_none_("to void to char %s\n", p);
    return 0;
}
