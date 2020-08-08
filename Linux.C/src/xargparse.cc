#include <string>
#include <map>

#include "../inc/xlog.h"
#include "../inc/xargparse.h"

namespace test_argparse
{
    Argparse::Argparse()
    {
        data = new map<string, string>;
        it = data->end();
        _log_debug_("crate new argparse *addr[%p].\n", data);
    }

    Argparse::~Argparse()
    {
        delete data;
        _log_debug_("delete argparse *addr[%p].\n", data);
        data = nullptr;
    }

    bool Argparse::add_argument(const string& _key, const string& value)
    {
        const char * tmp = convert_parse(_key.c_str());
        string key = string(tmp);
        if(data->count(key) != 0)
        {
            _log_warning_("the key[%s] exist. you can add it after del.\n", \
                    key.c_str());
            return false;
        }
        data->emplace(key, value);
        _log_debug_("add a argument --%s %s.\n", key.c_str(), value.c_str());
        return true;
    }

    void Argparse::del_argument(const string& key)
    {
        it = data->find(key);
        if(it != data->end())
        {
            data->erase(it);
            _log_debug_("del argument --%s\n", key.c_str());
        }
        else _log_warning_("del failed, not find the argument --%s.\n", \
                key.c_str());
    }

    void Argparse::parse_args(int argc, char * argv[])
    {
        for(int i = 1; i < argc; i++)
        {
            if(is_Optional_parameters(argv[i]) == 0)
            {
                _log_warning_("\"%s\" Invalid optional parameter", argv[i]);
                continue;
            }
            else if(i + 1 >= argc)
            {
                _log_warning_("argument %s not value.\n", argv[i]);
                continue;
            }
            else
            {
                const char * tmp = convert_parse(argv[i]);
                set_argument(string(tmp), string(argv[i + 1]));
                i++;
            }
        }
    }

    string& Argparse::operator [] (const string& key)
    {
        return (*data)[key];
    }

    string Argparse::get(const string& key)
    {
        return data->count(key) == 0 ? string("") : (*data)[key];
    }

    int Argparse::is_Optional_parameters(const char * buf)
    {
        return (*buf == '-') + (*(buf + 1) == '-');
    }

    const char * Argparse::convert_parse(const char * buf)
    {
        return buf + is_Optional_parameters(buf);
    }

    bool Argparse::set_argument(const string& key, const string& value)
    {
        if(data->count(key) == 0)
        {
            _log_warning_("the --%s Invalid.\n", key.c_str());
            return false;
        }
        (*data)[key] = value;
        _log_info_("set --%s value %s.\n", key.c_str(), value.c_str());
        return true;
    }

    int to_int32(const string& v)
    {
        int x = 0;
        sscanf(v.c_str(), "%d", &x);
        _log_debug_("convert \"%s\" to int32 %d.\n", v.c_str(), x);
        return x;
    }

    long long int to_int64(const string& v)
    {
        long long int x = 0;
        sscanf(v.c_str(), "%lld", &x);
        _log_debug_("convert \"%s\" to int64 %lld.\n", v.c_str(), x);
        return x;
    }

    const char * to_char_pointer(const string& v)
    {
        return v.c_str();
    }

    const void * to_void_pointer(const string& v)
    {
        return (const void *) v.c_str();
    }
};
