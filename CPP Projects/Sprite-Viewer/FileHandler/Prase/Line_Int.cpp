#include "../FileHandler.h"

#include <string>

int FileHandler::Prase::Line_Int(std::string _line, std::string Type)
{
    if(Type == "Title") _line = _line.substr(_line.find("-")+1);
    else if(Type == "Name")
    {
        _line = _line.substr(_line.find(' ')+1);
        _line = _line.erase(_line.find(":"));
    }
    else if(Type == "Data")
    {
        _line = _line.substr(_line.find("\"")+1);
        _line = _line.erase(_line.find(";")-1);
    }
    else std::cout << Type << " is not a type of string.\n";

    int s_int = std::stoi(_line);

    return s_int;
}
