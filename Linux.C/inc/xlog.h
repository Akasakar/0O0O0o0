#ifndef _XLOG_
#define _XLOG_

#ifdef _LOG_MACROS_

    #define _TEXT_COLOR_
    #include "xcolor.h"

    // debugging macros so we can pin down message origin at a glance
    #define _log_where_fmt_         "[file %s, line %d]: "
    #define _log_where_arg_         __FILE__, __LINE__
    
    // log file level macros
    #define _log_file_lv0_          stderr
    #define _log_file_lv1_          test_log::LogWarning.file_stream
    #define _log_file_lv2_          test_log::LogWarning.file_stream
    #define _log_file_lv3_          test_log::LogError.file_stream
    #define _log_file_lv4_          stdout
    
    // log type message macros
    #define _log_debug_message_     "[debug]: "
    #define _log_info_message_      "[info]: "
    #define _log_warning_message_   "[warning]: "
    #define _log_error_message_     "[error]: "
    #define _log_none_message_      "[none]: "
    
    // log echo macros
    #define _log_fprintf_(...) \
        fprintf(__VA_ARGS__)
    
    #define _log_echo_(_file_stream_, TEXT_COLOR, _fmt, ...) \
        _log_fprintf_(_file_stream_, _log_where_fmt_ TEXT_COLOR _fmt \
                TEXT_NONE, _log_where_arg_, __VA_ARGS__)
    #define _log_debug_(_fmt, ...) \
        _log_echo_(_log_file_lv0_, TEXT_GREEN, _log_debug_message_  _fmt, \
                __VA_ARGS__)
    #define _log_info_(_fmt, ...) \
        _log_echo_(_log_file_lv1_, TEXT_YELLOW, _log_info_message_ _fmt, \
                __VA_ARGS__)
    #define _log_warning_(_fmt, ...) \
        _log_echo_(_log_file_lv2_, TEXT_RED, _log_warning_message_ _fmt, \
                __VA_ARGS__)
    #define _log_error_(_fmt, ...) \
        _log_echo_(_log_file_lv3_, TEXT_PURPLE, _log_error_message_ _fmt, \
                __VA_ARGS__)
    #define _log_none_(_fmt, ...) \
        _log_echo_(_log_file_lv4_, TEXT_INDIGO, _log_none_message_ _fmt, \
                __VA_ARGS__)
#else

    #define _log_debug_(_fmt, ...)
    #define _log_info_(_fmt, ...)
    #define _log_warning_(_fmt, ...)
    #define _log_error_(_fmt, ...)
    #define _log_none_(_fmt, ...)

#endif // _LOG_MACROS_

namespace test_log
{
    class Log
    {
        public:
            Log();
            ~Log();
            int close_log();
            int open_log(const char * filename, const char * mode);
            int reset_log(const char * filename, const char * mode);
        public:
            FILE * file_stream;
            int status;
    };
    enum Log_Level { Lv_Debug, Lv_Info, Lv_Warning, Lv_Error, Lv_None };
    void open_log(const char * filename, const char * mode, int level);
    extern Log LogWarning;
    extern Log LogError;
};

#endif //_XLOG_
