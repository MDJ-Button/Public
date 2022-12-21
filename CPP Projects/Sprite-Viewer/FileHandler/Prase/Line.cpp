#include "../FileHandler.h"

std::string FileHandler::Prase::Line(std::string _line, std::string Type)
{
    if(Type == "Title")
    {
        _line = _line.substr(_line.find("-")+1);
    }
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

    return _line;
}
