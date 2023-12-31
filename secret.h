//
// Created by lamadaemon on 12/30/2023.
//

#ifndef LIBJRRP_SECRET_H
#define LIBJRRP_SECRET_H

#include "jrrp.h"
#include <cstdint>

PCLExport PCLHash PCLGetHash(char* str);
PCLExport PCLCallResult PCLStrFill(char* str, char code, char len, char** result);
PCLExport PCLCallResult PCLMidString(char* str, size_t start, size_t caplen, PCLBool strend, char* result);
PCLExport PCLCallResult PCLNumberToString(uint64_t number, char** result);
PCLExport PCLCallResult PCLNumberToHexString(uint64_t number, char** result);

#endif // LIBJRRP_SECRET_H
