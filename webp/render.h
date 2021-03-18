/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#ifndef TGS2ANIMATED_RENDER_H
#define TGS2ANIMATED_RENDER_H
#include <cmath>
#include <string>
#include <rlottie.h>
#include "webp_builder.h"
#include "../data/data_holder.h"
bool render(const std::string &lottieData, const std::string &outputPath);
#endif //TGS2ANIMATED_RENDER_H
