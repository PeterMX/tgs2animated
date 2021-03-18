/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#ifndef TGS2ANIMATED_DATA_HOLDER_H
#define TGS2ANIMATED_DATA_HOLDER_H

#include <cstdint>
#include <iostream>

class DataHolder {
public:
    explicit DataHolder(uint32_t quality, uint32_t method, bool min_size, uint32_t width, uint32_t height);
    ~DataHolder();
    static uint32_t mQuality;
    static uint32_t mMethod;
    static bool mMin_size;
    static uint32_t mWidth;
    static uint32_t mHeight;
};
#endif //TGS2ANIMATED_DATA_HOLDER_H
