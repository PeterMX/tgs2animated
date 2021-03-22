cmake_minimum_required(VERSION 3.17)
project(tgs2animated)

set(CMAKE_CXX_STANDARD 14)

#webp
add_library(webp STATIC
        libs/libwebp/src/dec/alpha_dec.c
        libs/libwebp/src/dec/buffer_dec.c
        libs/libwebp/src/dec/frame_dec.c
        libs/libwebp/src/dec/idec_dec.c
        libs/libwebp/src/dec/io_dec.c
        libs/libwebp/src/dec/quant_dec.c
        libs/libwebp/src/dec/tree_dec.c
        libs/libwebp/src/dec/vp8_dec.c
        libs/libwebp/src/dec/vp8l_dec.c
        libs/libwebp/src/dec/webp_dec.c
        libs/libwebp/src/dsp/alpha_processing.c
        libs/libwebp/src/dsp/alpha_processing_mips_dsp_r2.c
        libs/libwebp/src/dsp/alpha_processing_neon.c
        libs/libwebp/src/dsp/alpha_processing_sse2.c
        libs/libwebp/src/dsp/alpha_processing_sse41.c
        libs/libwebp/src/dsp/cost.c
        libs/libwebp/src/dsp/cost_mips32.c
        libs/libwebp/src/dsp/cost_mips_dsp_r2.c
        libs/libwebp/src/dsp/cost_neon.c
        libs/libwebp/src/dsp/cost_sse2.c
        libs/libwebp/src/dsp/cpu.c
        libs/libwebp/src/dsp/dec.c
        libs/libwebp/src/dsp/dec_clip_tables.c
        libs/libwebp/src/dsp/dec_mips32.c
        libs/libwebp/src/dsp/dec_mips_dsp_r2.c
        libs/libwebp/src/dsp/dec_msa.c
        libs/libwebp/src/dsp/dec_neon.c
        libs/libwebp/src/dsp/dec_sse2.c
        libs/libwebp/src/dsp/dec_sse41.c
        libs/libwebp/src/dsp/enc.c
        libs/libwebp/src/dsp/enc_mips32.c
        libs/libwebp/src/dsp/enc_mips_dsp_r2.c
        libs/libwebp/src/dsp/enc_msa.c
        libs/libwebp/src/dsp/enc_neon.c
        libs/libwebp/src/dsp/enc_sse2.c
        libs/libwebp/src/dsp/enc_sse41.c
        libs/libwebp/src/dsp/filters.c
        libs/libwebp/src/dsp/filters_mips_dsp_r2.c
        libs/libwebp/src/dsp/filters_msa.c
        libs/libwebp/src/dsp/filters_neon.c
        libs/libwebp/src/dsp/filters_sse2.c
        libs/libwebp/src/dsp/lossless.c
        libs/libwebp/src/dsp/lossless_enc.c
        libs/libwebp/src/dsp/lossless_enc_mips32.c
        libs/libwebp/src/dsp/lossless_enc_mips_dsp_r2.c
        libs/libwebp/src/dsp/lossless_enc_msa.c
        libs/libwebp/src/dsp/lossless_enc_neon.c
        libs/libwebp/src/dsp/lossless_enc_sse2.c
        libs/libwebp/src/dsp/lossless_enc_sse41.c
        libs/libwebp/src/dsp/lossless_mips_dsp_r2.c
        libs/libwebp/src/dsp/lossless_msa.c
        libs/libwebp/src/dsp/lossless_neon.c
        libs/libwebp/src/dsp/lossless_sse2.c
        libs/libwebp/src/dsp/rescaler.c
        libs/libwebp/src/dsp/rescaler_mips32.c
        libs/libwebp/src/dsp/rescaler_mips_dsp_r2.c
        libs/libwebp/src/dsp/rescaler_msa.c
        libs/libwebp/src/dsp/rescaler_neon.c
        libs/libwebp/src/dsp/rescaler_sse2.c
        libs/libwebp/src/dsp/ssim.c
        libs/libwebp/src/dsp/ssim_sse2.c
        libs/libwebp/src/dsp/upsampling.c
        libs/libwebp/src/dsp/upsampling_mips_dsp_r2.c
        libs/libwebp/src/dsp/upsampling_msa.c
        libs/libwebp/src/dsp/upsampling_neon.c
        libs/libwebp/src/dsp/upsampling_sse2.c
        libs/libwebp/src/dsp/upsampling_sse41.c
        libs/libwebp/src/dsp/yuv.c
        libs/libwebp/src/dsp/yuv_mips32.c
        libs/libwebp/src/dsp/yuv_mips_dsp_r2.c
        libs/libwebp/src/dsp/yuv_neon.c
        libs/libwebp/src/dsp/yuv_sse2.c
        libs/libwebp/src/dsp/yuv_sse41.c
        libs/libwebp/src/enc/alpha_enc.c
        libs/libwebp/src/enc/analysis_enc.c
        libs/libwebp/src/enc/backward_references_cost_enc.c
        libs/libwebp/src/enc/backward_references_enc.c
        libs/libwebp/src/enc/config_enc.c
        libs/libwebp/src/enc/cost_enc.c
        libs/libwebp/src/enc/filter_enc.c
        libs/libwebp/src/enc/frame_enc.c
        libs/libwebp/src/enc/histogram_enc.c
        libs/libwebp/src/enc/iterator_enc.c
        libs/libwebp/src/enc/near_lossless_enc.c
        libs/libwebp/src/enc/picture_csp_enc.c
        libs/libwebp/src/enc/picture_enc.c
        libs/libwebp/src/enc/picture_psnr_enc.c
        libs/libwebp/src/enc/picture_rescale_enc.c
        libs/libwebp/src/enc/picture_tools_enc.c
        libs/libwebp/src/enc/predictor_enc.c
        libs/libwebp/src/enc/quant_enc.c
        libs/libwebp/src/enc/syntax_enc.c
        libs/libwebp/src/enc/token_enc.c
        libs/libwebp/src/enc/tree_enc.c
        libs/libwebp/src/enc/vp8l_enc.c
        libs/libwebp/src/enc/webp_enc.c
        libs/libwebp/src/mux/anim_encode.c
        libs/libwebp/src/mux/muxedit.c
        libs/libwebp/src/mux/muxread.c
        libs/libwebp/src/mux/muxinternal.c
        libs/libwebp/src/utils/bit_reader_utils.c
        libs/libwebp/src/utils/bit_writer_utils.c
        libs/libwebp/src/utils/color_cache_utils.c
        libs/libwebp/src/utils/filters_utils.c
        libs/libwebp/src/utils/huffman_utils.c
        libs/libwebp/src/utils/huffman_encode_utils.c
        libs/libwebp/src/utils/quant_levels_utils.c
        libs/libwebp/src/utils/quant_levels_dec_utils.c
        libs/libwebp/src/utils/random_utils.c
        libs/libwebp/src/utils/rescaler_utils.c
        libs/libwebp/src/utils/thread_utils.c
        libs/libwebp/src/utils/utils.c
        libs/libwebp/examples/example_util.c
        libs/libwebp/imageio/imageio_util.c)
target_compile_options(webp PUBLIC
        -Wall -fPIC -finline-functions -ffast-math -Os)
target_compile_definitions(webp PUBLIC
        HAVE_MALLOC_H HAVE_PTHREAD WEBP_USE_THREAD)
target_include_directories(webp PUBLIC
        libs/libwebp
        libs/libwebp/src)

#rlottie
add_library(rlottie STATIC
        libs/rlottie/src/lottie/lottieanimation.cpp
        libs/rlottie/src/lottie/lottieitem.cpp
        libs/rlottie/src/lottie/lottiekeypath.cpp
        libs/rlottie/src/lottie/lottieloader.cpp
        libs/rlottie/src/lottie/lottiemodel.cpp
        libs/rlottie/src/lottie/lottieparser.cpp
        libs/rlottie/src/lottie/lottieproxymodel.cpp
        libs/rlottie/src/vector/freetype/v_ft_math.cpp
        libs/rlottie/src/vector/freetype/v_ft_raster.cpp
        libs/rlottie/src/vector/freetype/v_ft_stroker.cpp
        libs/rlottie/src/vector/pixman/vregion.cpp
        libs/rlottie/src/vector/stb/stb_image.cpp
        libs/rlottie/src/vector/vbezier.cpp
        libs/rlottie/src/vector/vbitmap.cpp
        libs/rlottie/src/vector/vbrush.cpp
        libs/rlottie/src/vector/vcompositionfunctions.cpp
        libs/rlottie/src/vector/vdasher.cpp
        libs/rlottie/src/vector/vdebug.cpp
        libs/rlottie/src/vector/vdrawable.cpp
        libs/rlottie/src/vector/vdrawhelper.cpp
        libs/rlottie/src/vector/vdrawhelper_neon.cpp
        libs/rlottie/src/vector/vdrawhelper_sse2.cpp
        libs/rlottie/src/vector/velapsedtimer.cpp
        libs/rlottie/src/vector/vimageloader.cpp
        libs/rlottie/src/vector/vinterpolator.cpp
        libs/rlottie/src/vector/vmatrix.cpp
        libs/rlottie/src/vector/vpainter.cpp
        libs/rlottie/src/vector/vpath.cpp
        libs/rlottie/src/vector/vpathmesure.cpp
        libs/rlottie/src/vector/vraster.cpp
        libs/rlottie/src/vector/vrect.cpp
        libs/rlottie/src/vector/vrle.cpp)
target_compile_options(rlottie PUBLIC
        -Wall -fPIC -fno-rtti -finline-functions -ffast-math -Os -fno-unwind-tables -fno-asynchronous-unwind-tables -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unused-parameter -fvisibility=hidden)
target_compile_definitions(rlottie PUBLIC
        NDEBUG)
target_include_directories(rlottie PUBLIC
        libs/rlottie/inc
        libs/rlottie/src/vector/
        libs/rlottie/src/vector/pixman
        libs/rlottie/src/vector/freetype
        libs/rlottie/src/vector/stb)

add_executable(tgs2animated
        main.cpp
        webp/webp_builder.cpp webp/webp_builder.h
        webp/render.cpp webp/render.h
        webp/utils.cpp webp/utils.h
        data/data_holder.cpp data/data_holder.h
        )
target_compile_options(tgs2animated PUBLIC
        -ffast-math -Os -funroll-loops -ffast-math -fno-strict-aliasing -fno-math-errno)

target_link_libraries(tgs2animated rlottie webp pthread dl)

target_include_directories(tgs2animated
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/libs/rlottie/inc/"
        "${CMAKE_CURRENT_LIST_DIR}/libs/libwebp")
