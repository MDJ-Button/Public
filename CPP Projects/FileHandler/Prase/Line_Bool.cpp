#include "../FileHandler.h"

bool FileHandler::Prase::Line_Bool(std::string _line, std::string Type)
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

    bool s_bool;

    if(_line == "true") s_bool = true;
    else if(_line == "false") s_bool = false;

    return s_bool;
}
