/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#ifndef TGS2ANIMATED_WEBP_BUILDER_H
#define TGS2ANIMATED_WEBP_BUILDER_H
#include <string>
#include <iostream>
#include <rlottie.h>
#include "utils.h"
#include "src/webp/encode.h"
#include "src/webp/mux.h"
#include "../data/data_holder.h"
class WebpBuilder {
public:
    explicit WebpBuilder(const std::string &fileName, uint32_t timems);
    ~WebpBuilder();
    void addFrame(rlottie::Surface& s);
    static void argbTorgba(rlottie::Surface& s);

private:
    WebPData webp_data{};
    WebPAnimEncoderOptions anim_config{};
    WebPConfig config{};
    WebPPicture pic{};
    WebPAnimEncoder* enc = nullptr;
    std::string fileName;
    int pic_num = 0;
    int timestamp_ms = 0;
    int duration = 0;
    int64_t stride{};
    int ok = 1;
    uint32_t width;
    uint32_t height;
};
#endif //TGS2ANIMATED_WEBP_BUILDER_H
