#include <iostream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/channels.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP;

int main ()
{
    try {
        SHA1 sha1;
        string hash;

        cout << "Name: " << sha1.AlgorithmName() << endl;
        cout << "Digest size: " << sha1.DigestSize() << endl;
        cout << "Block size: " << sha1.BlockSize() << endl;
        const char* FILE = "/home/user/111.txt";

        cout << "File name: " << FILE << endl;
        HashFilter filter(sha1, new HexEncoder(new StringSink(hash)));
        ChannelSwitch c;
        c.AddDefaultRoute(filter);
        FileSource(FILE, true, new Redirector(c));

        cout <<"Hash:  "<< FILE << ": " << hash << endl;
    } catch (const Exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
