// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ootzCommon.h"
#include "ootzMathf.h"
#include "Singleton.h"
#include <stdexcept>
#include <cassert>
#include "ootz_dll_manager.h"

using Clamp = float(*)(const float, const float, const float);

//class Dll : private boost::noncopyable
//{
//private:
//    static std::map<const char*, Dll*> dlls_;
//
//private:
//    static Dll* GetHandle_(const char* filename)
//    {
//        const auto result = dlls_.find(filename);
//        const bool isfound = result != dlls_.end();
//        if (isfound)
//        {
//            return result->second;
//        }
//
//        Dll* dll = Load(filename);
//        dlls_.emplace(filename, dll);
//        return dll;
//    }
//
//    static Dll* Load(const char* filename)
//    {
//        HMODULE hModule = LoadLibraryA(filename);
//        
//        assert(hModule && "failed to load dll file");
//
//        Dll* dll = nullptr;
//        try
//        {
//            dll = new Dll(hModule);
//        }
//        catch (std::bad_alloc& ba)
//        {
//            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
//        }
//
//        return dll;
//    }
//
//public:
//    static Dll& GetHandle(const char* filename)
//    {
//        return *GetHandle_(filename);
//    }
//
//private:
//    HMODULE hModule_;
//
//private:
//    Dll(HMODULE hModule)
//        : hModule_(hModule)
//    {
//    }
//
//    ~Dll()
//    {
//        if (hModule_)
//        {
//            const BOOL result = FreeLibrary(hModule_);
//            assert(result && "free library is returned bad result");
//        }
//    }
//
//public:
//
//};

int main()
{
    //auto result = ootz::Mathf::Clamp(1.0f, 3.0f, 2.0f);
    //std::cout << result << std::endl;
    //std::cout << ootz::Mathf::PI << std::endl;

    //HMODULE hMod = LoadLibraryA("ootzUtility.dll");
    //DWORD error = NOERROR;
    //if (hMod == nullptr)
    //{
    //    error = GetLastError();
    //    std::cout << "failed to load dll file\n";
    //}
    //else
    //{
    //    std::cout << "load success\n";

    //    FARPROC result = GetProcAddress(hMod, "Clamp");
    //    if (result == nullptr)
    //    {
    //        std::cout << "failed to search function\n";
    //    }
    //    Clamp clamp = (Clamp)result;
    //    float result2 = clamp(0.0f, 1.0f, 2.0f);
    //    std::cout << result2 << std::endl;

    //    const BOOL resultFree = FreeLibrary(hMod);
    //    if (resultFree)
    //    {
    //        std::cout << "success\n";
    //    }
    //    else
    //    {
    //        std::cout << "failed\n";
    //    }
    //}

    //Dll::GetHandle("ootzUtility.dll").GetHandle().GetHandle();

    auto func = ootz::Dll::GetHandle("ootzUtility.dll").GetAddressPtr("Clamp");
    Clamp clamp = (Clamp)func;
    std::cout << clamp(0.0f, 1.0f, 2.0f) << '\n';

    func = ootz::Dll::GetHandle("ootzUtility.dll").GetAddressPtr("PI");
    auto pi = (float*)func;
    auto fpi = *pi;
    std::cout << fpi;

    ootz::Dll::Release();
    ootz::MemoryAllocator::CheckNumUnreleaseds();

    system("pause");
    return 0;
}

