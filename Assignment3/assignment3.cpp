#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string ip;
    int a, b, c, d;
    char ch;

    cout << "Enter IPv4 Address : ";
    cin >> ip;

    stringstream ss(ip);

    if (!(ss >> a >> ch >> b >> ch >> c >> ch >> d))
    {
        cout << "Invalid IP Address Format!";
        return 0;
    }

    if (a < 0 || a > 255 || b < 0 || b > 255 ||
        c < 0 || c > 255 || d < 0 || d > 255)
    {
        cout << "Invalid IP Address!";
        return 0;
    }

    cout << "\n==============================================";
    cout << "\n          IPv4 Address Information";
    cout << "\n==============================================";

    cout << "\nEntered IP Address : " << ip << endl;

    // Loopback Address Detection
    if (a == 127)
    {
        cout << "\n======================================";
        cout << "\nLoopback Address Detected!";
        cout << "\n======================================";
        cout << "\nLoopback Address : " << ip;
        cout << "\nDefinition       : A loopback address is a special IP address used by a computer";
        cout << "\n                   to communicate with itself.";
        cout << "\nIP Range         : 127.0.0.0 - 127.255.255.255";
        cout << "\nCommon Address   : 127.0.0.1 (localhost)";
        cout << "\nPurpose          :";
        cout << "\n1. Tests the TCP/IP protocol stack.";
        cout << "\n2. Checks whether the network software is working correctly.";
        cout << "\n3. Allows applications on the same computer to communicate.";
        cout << "\n4. No packets are sent over the physical network.";
    }
    else
    {
        cout << "\nNo Loopback Address Detected.";
    }

    cout << "\nDefinition of Subnet:";
    cout << "\nA subnet divides a large network into smaller logical networks.";
   
    cout << "\n\nDefinition of Subnet Mask:";
    cout << "\nA subnet mask is a 32-bit number used to separate the Network ID and Host ID of an IP address.";

    cout << "\n\nFormula:";
    cout << "\nUsable Hosts = 2^(Host Bits) - 2";

    cout << "\nReason for -2:";
    cout << "\n1. First address = Network Address";
    cout << "\n2. Last address  = Broadcast Address";

    cout << "\n\n-------------------------------------------------------------";
    cout << "\nClass Details";
    cout << "\n-------------------------------------------------------------";

    if (a >= 0 && a <= 127)
    {
        cout << "\nIP Class             : A";
        cout << "\nFirst Octet Binary   : 0XXXXXXX";
        cout << "\nIP Range             : 0.0.0.0 - 127.255.255.255";
        cout << "\nSubnet Mask          : 255.0.0.0";
        cout << "\nNetwork Bits         : 8";
        cout << "\nHost Bits            : 24";
        cout << "\nHosts Formula        : 2^24 - 2";
        cout << "\nUsable Hosts         : 16,777,214";
        cout << "\nNo. of Networks      : 2^7 = 128";
    }
    else if (a >= 128 && a <= 191)
    {
        cout << "\nIP Class             : B";
        cout << "\nFirst Octet Binary   : 10XXXXXX";
        cout << "\nIP Range             : 128.0.0.0 - 191.255.255.255";
        cout << "\nSubnet Mask          : 255.255.0.0";
        cout << "\nNetwork Bits         : 16";
        cout << "\nHost Bits            : 16";
        cout << "\nHosts Formula        : 2^16 - 2";
        cout << "\nUsable Hosts         : 65,534";
        cout << "\nNo. of Networks      : 2^14 = 16,384";
    }
    else if (a >= 192 && a <= 223)
    {
        cout << "\nIP Class             : C";
        cout << "\nFirst Octet Binary   : 110XXXXX";
        cout << "\nIP Range             : 192.0.0.0 - 223.255.255.255";
        cout << "\nSubnet Mask          : 255.255.255.0";
        cout << "\nNetwork Bits         : 24";
        cout << "\nHost Bits            : 8";
        cout << "\nHosts Formula        : 2^8 - 2";
        cout << "\nUsable Hosts         : 254";
        cout << "\nNo. of Networks      : 2^21 = 2,097,152";
    }
    else if (a >= 224 && a <= 239)
    {
        cout << "\nIP Class             : D";
        cout << "\nFirst Octet Binary   : 1110XXXX";
        cout << "\nIP Range             : 224.0.0.0 - 239.255.255.255";
        cout << "\nPurpose              : Multicast";
        cout << "\nSubnet Mask          : Not Applicable";
        cout << "\nHosts                : Not Applicable";
        cout << "\nNetworks             : Not Applicable";
    }
    else
    {
        cout << "\nIP Class             : E";
        cout << "\nFirst Octet Binary   : 1111XXXX";
        cout << "\nIP Range             : 240.0.0.0 - 255.255.255.255";
        cout << "\nPurpose              : Experimental / Research";
        cout << "\nSubnet Mask          : Not Applicable";
        cout << "\nHosts                : Not Applicable";
        cout << "\nNetworks             : Not Applicable";
    }

    cout << "\n\n==============================================================";
    cout << "\nSummary Table";
    cout << "\n==============================================================";

    cout << "\nClass\tRange\t\t\tSubnet Mask\tHosts\t\tNetworks";
    cout << "\nA\t0-127\t\t\t255.0.0.0\t16,777,214\t128";
    cout << "\nB\t128-191\t\t\t255.255.0.0\t65,534\t\t16,384";
    cout << "\nC\t192-223\t\t\t255.255.255.0\t254\t\t2,097,152";
    cout << "\nD\t224-239\t\t\tN/A\t\tMulticast\tN/A";
    cout << "\nE\t240-255\t\t\tN/A\t\tExperimental\tN/A";

    cout << "\n\n==============================================================";
    cout << "\n";

    return 0;
}