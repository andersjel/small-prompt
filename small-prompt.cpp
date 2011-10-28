#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

string shorten_rec(const string &s, size_t max_length)
{
    if(s.length() < max_length)
    {
        return s;
    }
    size_t n = s.find('/');
    if(n==string::npos)
    {
        return s;
    }
    return shorten_rec(string(s, n + 1), max_length);
}

string shorten(const string &s, size_t max_length)
{
    if(s.length() < max_length)
    {
        return s;
    }
    if(s.find('/')==string::npos)
    {
        return s;
    }
    return string(".../") + shorten_rec(s, max_length-4);
}

int main(int argc, char *argv[]){
    size_t max_length = 30;
    if(argc >= 2)
    {
        istringstream iss(argv[1],istringstream::in);
        iss >> max_length;
        if(max_length < 3)
        {
            max_length = 5;
        }
    }
    char* home = getenv("HOME");
    size_t homelen = strlen(home);
    char* cwd;
    // This should be freed, but we are not going
    // to do this since the program runtime is so limited.
    cwd = get_current_dir_name();
    string output;
    if(strncmp(home, cwd, homelen) == 0)
    {
        output += '~';
        output += cwd + homelen;
    }
    else
    {
        output += cwd;
    }
    output = shorten(output, max_length);
    char last_char = output[output.size()-1];
    if(last_char!='/'  && last_char!='~')
    {
        output += '/';
    }
    cout << output;
    return 0;
}
