#include <fstream>
#include <map>
#include <iostream>

int main()
{
    std::ifstream ifs("Wild_wild_west.txt");
    std::string s;
    std::map<std::string, int> map;

    while (ifs >> s) 
        ++map[s];

   
    typedef std::map<std::string, int>::const_iterator iter;

    for (iter it = map.begin(); it != map.end(); ++it)
       std::cout << "occurence " << it->first << ": " << it->second << std::endl;

    return 0;
}