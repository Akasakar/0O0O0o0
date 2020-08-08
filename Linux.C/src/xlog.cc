#include <cstdio>

#include "../inc/xlog.h"

namespace test_log
{
    Log LogWarning;
    Log LogError;

    Log::Log()
    {
        file_stream = stderr;
        status = 0;
        _log_debug_("init file stream [%p] by stderr.\n", file_stream);
    }

    Log::~Log()
    {
        if(file_stream != stderr || file_stream != stdout)
            close_log();
    }

    int Log::close_log()
    {
        if(status > 0) 
        {
            status = fclose(file_stream);
            _log_debug_("close file stream [%p] status[%d].\n", \
                    file_stream, status);
        }
        return status;
    }

    int Log::open_log(const char * filename, const char * mode)
    {
        if(status == 0) 
        {
            file_stream = fopen(filename, mode);
            if(file_stream != nullptr) status = 1;
            _log_debug_("open file stream [%p] status[%d].\n", \
                    file_stream, status);
        }
        return status;
    }

    int Log::reset_log(const char * filename, const char * mode)
    {
        close_log();
        int status = open_log(filename, mode);
        return status;
    }

    void open_log(const char * filename, const char * mode, int _Lv)
    {
        _log_debug_("open log level %d.\n", _Lv);
        switch(_Lv)
        {
            case Lv_Debug:
                break;
            case Lv_Info:
            case Lv_Warning:
                LogWarning.reset_log(filename, mode);
                break;
            case Lv_Error:
                LogError.reset_log(filename, mode);
                break;
            case Lv_None:
            default:
                break;
        }
    }
};
