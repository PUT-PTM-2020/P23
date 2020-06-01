#include <string>
using namespace std;
class Config
{
    public:
        static string url;
        static string WifiSSID;
        static string WifiPassword;

        static string LoggerUrl;

    static void StaticConstructor()
    {
        url = "tesett";
    }
};