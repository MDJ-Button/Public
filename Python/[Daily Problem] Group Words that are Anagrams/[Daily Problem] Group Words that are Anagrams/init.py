import collections

def groupAnagramWords(strs):
    for index, i in enumerate(strs):
        if((index + 2) <= len(strs)):
            print(i);
            len(i);
            print(strs[index + 1]);
            #if(len(i) == len(strs[index + 1])):
                #for j in i:
                    #print(j);
    return strs;

print(groupAnagramWords(['abc', 'bcd', 'cba', 'cbd', 'efg']));
# [['efg'], ['bcd', 'cbd'], ['abc', 'cba']]