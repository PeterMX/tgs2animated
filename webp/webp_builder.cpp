/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/

#include "webp_builder.h"

WebpBuilder::WebpBuilder(const std::string &fileName, uint32_t timems) {

    WebPDataInit(&webp_data);
    WebPAnimEncoderOptionsInit(&anim_config);
    WebPConfigInit(&config);
    WebPPictureInit(&pic);
    config.lossless = 0;
    config.quality = DataHolder::mQuality;
    config.method = DataHolder::mMethod;
    anim_config.minimize_size = DataHolder::mMin_size;
    duration = timems;
    this->fileName = fileName;
    this->width = DataHolder::mWidth;
    this->height = DataHolder::mHeight;

}
WebpBuilder::~WebpBuilder() {
    ok = ok && WebPAnimEncoderAdd(enc, nullptr, timestamp_ms, nullptr);
    if (!ok) {
        std::cout<<"Could not create WebPAnimEncoderAdd"<<std::endl;
    }
    ok = ok && WebPAnimEncoderAssemble(enc, &webp_data);
    if (!ok) {
        std::cout<<"Error during final animation assembly"<<std::endl;
    }
    WebPAnimEncoderDelete(enc);
    ok = ImgIoUtilWriteFile(const_cast<char*>(fileName.c_str()), webp_data.bytes, webp_data.size);
    if (ok) std::cout<<"output: "<<fileName<<std::endl;
    if (ok) std::cout<<"["<<pic_num<<" frames, "<<(unsigned int)webp_data.size<<" bytes]"<<std::endl;
    WebPDataClear(&webp_data);
}
void WebpBuilder::addFrame(rlottie::Surface& s) {
    if (ok) {
        ok = WebPValidateConfig(&config);
    }
    pic.use_argb = 1;
    argbTorgba(s);

    if (enc == nullptr) {
        std::cout<<"init encoder"<<std::endl;
        enc = WebPAnimEncoderNew(width,height,&anim_config);
        ok = (enc != nullptr);
        if(!ok) {
            std::cout<<"Could not create WebpAnimEncoder object"<<std::endl;
        }
    }

    stride = (int64_t) 4 * width * sizeof(uint8_t);

    pic.width = width;
    pic.height = height;

    ok = WebPPictureImportRGBA(&pic, reinterpret_cast<uint8_t *>(s.buffer()), (int)stride);

    if(!ok) {
        std::cout<<"Could not create WebPPictureImportRGBA"<<std::endl;
    }

    ok = WebPAnimEncoderAdd(enc, &pic, timestamp_ms, &config);
    if (!ok) {
        std::cout<<"Error while adding frame #"<<pic_num<<std::endl;
    }
    WebPPictureFree(&pic);
    timestamp_ms += duration;
    ++pic_num;

}
void WebpBuilder::argbTorgba(rlottie::Surface &s)
{
    auto *buffer = reinterpret_cast<uint8_t *>(s.buffer());
    uint32_t totalBytes = s.height() * s.bytesPerLine();

    for (uint32_t i = 0; i < totalBytes; i += 4) {
        unsigned char a = buffer[i+3];
        // compute only if alpha is non zero
        if (a) {
            unsigned char r = buffer[i+2];
            unsigned char g = buffer[i+1];
            unsigned char b = buffer[i];

            if (a != 255) { //un premultiply
                r = (r * 255) / a;
                g = (g * 255) / a;
                b = (b * 255) / a;
                buffer[i] = r;
                buffer[i+1] = g;
                buffer[i+2] = b;

            } else {
                // only swizzle r and b
                buffer[i] = r;
                buffer[i+2] = b;
            }
        }
    }
}
