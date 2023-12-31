//
// Created by lamadaemon on 12/30/2023.
//

#ifndef LIBJRRP_UUID_H
#define LIBJRRP_UUID_H

#include "jrrp.h"
#include <cstdint>

PCLExport uint32_t PCLGetTime();
PCLExport PCLCallResult PCLGetPlatformUUID(char** result);
PCLExport PCLCallResult PCLGetIdentify(char** result);
PCLExport PCLCallResult PCLGenerateIdentify(char** result);
PCLExport PCLCallResult PCLBuildIdentify(uint32_t ticks, uint64_t mems, char** result);
PCLExport PCLCallResult PCLGetUniqueID(char* identify, char* platformUUID, char** result);

#endif // LIBJRRP_UUID_H
