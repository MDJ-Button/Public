import PrintList

def func(to_be_added):
    string_list = PrintList.func("n/a").split(", ");
    string_list.append(to_be_added)
    string = ''
    for i in string_list:
        if not string:
            string = i;
        else:
            string = string + ", " + i;
            
    file = open("bin\Debug\PrintList.py", "w");
    file.write("todo = [" + "\"" + string + "\"" + "]\n\n" + "def func(listname):\n\tstring = ''\n\tfor i in todo:\n\t\tif not string:\n\t\t\tstring = i;\n\t\telse:\n\t\t\tstring = string + \t + i;\n\n\treturn string;");
    file.close();
    return string;