#ifndef LIBJRRP_JRRP_H
#define LIBJRRP_JRRP_H

#include <cstdint>

#define PCLNullptr     0LL
#define PCLCallResult  int
#define PCLRenPin      unsigned char
#define PCLHash        uint64_t
#define PCLBool        unsigned char
#define PCLTrue        1
#define PCLFalse       0
#define PCLSuccess     0LL
#define PCLFail        1LL

#if COMPILER_MSVC
#define PCLExport __declspec(dllexport)
#elif COMPILER_CLANG
#define PCLExport [[gnu::visibility("default")]] [[gnu::used]]
#endif

#ifndef PCLExport
#define PCLExport
#endif

PCLExport uint32_t PCLGetDayOfYear();
PCLExport uint16_t PCLGetYear();
PCLExport uint16_t PCLGetDay();
PCLExport PCLRenPin PCLJrrp(char* address);
PCLExport char* PCLStringifyJrrp(PCLRenPin rp);

#endif//LIBJRRP_JRRP_H
