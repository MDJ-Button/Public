import PrintList

def func(to_be_removed):
    string_list = PrintList.func("n/a").split(", ");
    string = ''
    for i in string_list:
        if to_be_removed == "clear_list":
            string = '';
            break;
        elif not string:
            string = i;
        elif to_be_removed in i:
            continue;
        else:
            string = string + ", " + i;
            
    file = open("PrintList.py", "w");
    file.write("todo = [" + "\"" + string + "\"" + "]\n\n" + "def func(listname):\n\tstring = ''\n\tfor i in todo:\n\t\tif not string:\n\t\t\tstring = i;\n\t\telse:\n\t\t\tstring = string + \t + i;\n\n\treturn string;");
    file.close();
            
    return string;

print(func("clear_list"))
