#include <cstdio>

#include "../inc/xlog.h"

int main()
{
    test_log::open_log("./test.xlog.log", "w", 2);
    _log_debug_("23%d\n", 3);
    _log_info_("23%d\n", 3);
    _log_warning_("23%d\n", 3);
    _log_error_("23%d\n", 3);
    _log_none_("23%d\n", 3);
}
