#include <iostream>
#include <Python.h>

std::string Print()
{
    return "Printing:\n ";
}

std::string Write()
{
    return "Writing:\n ";
}

std::string Remove()
{
    return "Removing:\n ";
}

template <class T>
T File(std::string Filename, std::string Function_name, std::string Parameters, bool Print_result)
{
    int sizeof_Filename = Filename.length();
    char Filename_char[sizeof_Filename];
    strcpy(Filename_char, Filename.c_str());

    int sizeof_Function_name = Function_name.length();
    char Function_name_char[sizeof_Function_name];
    strcpy(Function_name_char, Function_name.c_str());

    int sizeof_Parameters = Parameters.length();
    char Parameters_char[sizeof_Parameters];
    strcpy(Parameters_char, Parameters.c_str());

    Py_Initialize();

    //Run a python function
    PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

    pName = PyUnicode_FromString((char*)Filename_char); // filename
    pModule = PyImport_Import(pName);
    pFunc = PyObject_GetAttrString(pModule, (char*)Function_name_char); // func name
    pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)Parameters_char)); // func para
    pValue = PyObject_CallObject(pFunc, pArgs);

    auto result = _PyUnicode_AsString(pValue);

    if(Print_result) std::cout << result << std::endl;

    //Close the python instance
    Py_Finalize();

    return result;
}

int main()
{
    int command_list_size = 4;

    std::string user_input;
    std::string commands_list[command_list_size] = {"Print - Displays list.",
                                                    "Write - Writes to the list.",
                                                    "Remove - Removes a single element from the list or use clear_list to remove everything.",
                                                    "Exit - Exit the application."};
    bool Run = true;
    while(Run)
    {
        std::cout << "--------------------------------------------------\n";
        std::cout << "Simple Console To List Application using Python scripts.";

        for(int i = 0; i < command_list_size; i++)
        {
            std::cout << "\n    " << commands_list[i];
        }

        std::cout << "\n\nPlease enter a command from the list above - ";
        std::cin >> user_input;

        if(user_input == "Print")
        {
            std::cout << Print() << File<std::string>("PrintList", "func", "n/a", false) << std::endl;
        }

        else if(user_input == "Write")
        {
            std::cout << "\nType in what you want to add to the list - ";
            std::cin >> user_input;
            std::cout << Write() << File<std::string>("AddToList", "func", user_input, false) << std::endl;
        }

        else if(user_input == "Remove")
        {
            std::cout << "\nType in what you want to remove from the list - ";
            std::cin >> user_input;
            std::cout << Remove() << File<std::string>("RemoveFromList", "func", user_input, false) << std::endl;
        }

        else if(user_input == "Exit")
        {
            Run = false;
            break;
        }

        else
        {
            std::cout << "\n" << user_input << " is not a known command.";
        }

        std::cout << "\n--------------------------------------------------";

        std::cout << std::endl << std::endl;
    }

    return 0;
}
