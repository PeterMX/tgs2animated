/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#include "utils.h"

int ImgIoUtilWriteFile(const char* const file_name,
                       const uint8_t* data, size_t data_size) {
    int ok=1;
    if (data == nullptr) {
        return 0;
    }
    std::ofstream fp;
    fp.open(file_name,std::ios::out | std::ios::binary);
    fp.write((char*)data, data_size);
    return ok;
}
