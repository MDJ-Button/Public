#ifndef __FILEHANDLER_H__
#define __FILEHANDLER_H__

#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------
namespace FileHandler
{
    namespace Prase
    {
        std::string DLL_EXPORT Line(std::string _line, std::string Type);
        std::string DLL_EXPORT Line_Str_Array(std::string _line, int return_this);
        int         DLL_EXPORT Line_Int(std::string _line, std::string Type);
        int         DLL_EXPORT Line_Int_Array(std::string _line, int return_this);
        bool        DLL_EXPORT Line_Bool(std::string _line, std::string Type);
        bool        DLL_EXPORT Line_Bool_Array(std::string _line, int return_this);
        float       DLL_EXPORT Line_Float(std::string _line, std::string Type);
        float       DLL_EXPORT Line_Float_Array(std::string _line, int return_this);
    }
}
//------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __FILEHANDLER_H__
