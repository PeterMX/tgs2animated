/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#ifndef TGS2ANIMATED_UTILS_H
#define TGS2ANIMATED_UTILS_H

#include <cstdint>
#include <string>
#include <fstream>

int ImgIoUtilWriteFile(const char* file_name,
                       const uint8_t* data, size_t data_size);
#endif //TGS2ANIMATED_UTILS_H
