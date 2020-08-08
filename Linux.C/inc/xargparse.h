#ifndef _XARGPARSE_
#define _XARGPARSE_

#include <string>
#include <map>

namespace test_argparse
{
    using std::string;
    using std::map;

    class Argparse
    {
        public:
            Argparse();
            ~Argparse();
            bool add_argument(const string& key, const string& value = "");
            void del_argument(const string& key);
            void parse_args(int argc, char * argv[]);
            string& operator [] (const string& key);
            string get(const string& key);
        private:
            int is_Optional_parameters(const char * buf);
            const char * convert_parse(const char * buf);
            bool set_argument(const string& key, const string& value = "");
        private:
            map<string, string> * data;
            map<string, string>::iterator it;
    };
    
    int to_int32(const string& v);
    long long int to_int64(const string& v);
    const char * to_char_pointer(const string& v);
    const void * to_void_pointer(const string& v);
};

#endif // _XARGPARSE_
