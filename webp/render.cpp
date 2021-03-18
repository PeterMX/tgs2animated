/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#include "render.h"

bool render(const std::string &lottieData, const std::string &outputPath) {
    std::unique_ptr<rlottie::Animation> animation = rlottie::Animation::loadFromFile(lottieData);
    if(!animation) return false;

    auto buffer = std::unique_ptr<uint32_t[]>(new uint32_t[DataHolder::mWidth * DataHolder::mHeight]);
    size_t frameCount = animation->totalFrame();
    size_t frameDuration = animation->duration()*1000/frameCount;
    std::cout<<"frames = "<<animation->totalFrame()<<std::endl;
    std::cout<<"framerate = "<<animation->frameRate()<<std::endl;
    WebpBuilder builder(outputPath, frameDuration);
    for (size_t i=0; i < frameCount; i++) {
        rlottie::Surface surface(buffer.get(), DataHolder::mWidth, DataHolder::mHeight, DataHolder::mWidth*4);
        animation->renderSync(i, surface);
        builder.addFrame(surface);
    }
    return true;
}
