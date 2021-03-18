/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#include "data_holder.h"

DataHolder::DataHolder(const uint32_t quality, const uint32_t method, const bool min_size, const uint32_t width,
                       const uint32_t height) {
    DataHolder::mQuality = quality;
    DataHolder::mMethod = method;
    DataHolder::mMin_size = min_size;
    DataHolder::mWidth = width;
    DataHolder::mHeight = height;
}

DataHolder::~DataHolder() = default;

uint32_t DataHolder::mQuality;
uint32_t DataHolder::mMethod;
bool DataHolder::mMin_size;
uint32_t DataHolder::mWidth;
uint32_t DataHolder::mHeight;

