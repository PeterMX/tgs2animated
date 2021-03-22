/*
* Created by uriel on 17/03/21.
* This is licensed under GNU GPL v. 2 or later.
* You should have received a copy of the license in this archive (see LICENSE).
*
* Copyright (c) Uriel Castro, 2021-2021.
*/
#include <iostream>

#include "webp/render.h"
#include "examples/unicode.h"
#include "examples/example_util.h"
#include "data/data_holder.h"
#include "zstr.hpp"

std::string decompress(std::istream& inputFile) {
    zstr::istream zs(inputFile);
    return std::string(std::istreambuf_iterator<char>(zs), std::istreambuf_iterator<char>());
}

bool convert(const std::string& filePath, const std::string& output) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr<<"Could not open file "<<filePath<<std::endl;
        return -1;
    }
    const std::string decompressed = decompress(inputFile);
    inputFile.close();
    return render(decompressed, output);
}

static void Help() {
    using namespace std;
    cout<<"Usage:"<<endl;
    cout<<" tgs2animated [options] -i tgs_file -o webp_file"<<endl;
    cout<<"Options:"<<endl;
    cout<<"  -h / -help ............... this help"<<endl;
    cout<<"  -i <tgs_file>............. input tgs file"<<endl;
    cout<<"  -o <webp_file>............ output webp file"<<endl;
    cout<<"  -q <float> ............... quality factor (0:small..100:big)"<<endl;
    cout<<"  -m <int> ................. compression method (0=fast, 6=slowest)"<<endl;
    cout<<"  -min_size ................ minimize size"<<endl;
    cout<<"  -wh <int>................. Width and height in px"<<endl;
    cout<<""<<endl;
    cout<<"  -version ................. print version number and exit"<<endl;

}

int main(int argc, const char** argv) {
    std::string file;
    std::string op;
    CommandLineArguments cmd_args;

    INIT_WARGV(argc, argv);

    int ok = ExUtilInitCommandLineArguments(argc - 1, argv +1, &cmd_args);
    if (!ok) FREE_WARGV_AND_RETURN(1);

    argc = cmd_args.argc_;
    argv = cmd_args.argv_;

    bool min_size = false;
    int wh = 512, m = 5;
    int c;
    float q = 100;
    for (c = 0; ok && c < argc; c++) {
        if (argv[c][0] == '-') {
            int parse_error = 0;
            if (!strcmp(argv[c],"-min_size")) {
                min_size = true;
            } else if (!strcmp(argv[c], "-h") || !strcmp(argv[c], "-help")) {
                Help();
                return 0;
            } else if (!strcmp(argv[c], "-version")) {
                const int enc_version = WebPGetEncoderVersion();
                const int mux_version = WebPGetMuxVersion();
                const int tgs2animated_version = 1;
                std::cout<<"WebP Encoder version: "<<((enc_version >> 16) & 0xff)<<"."<<((enc_version >> 8) & 0xff)<<"."<<(enc_version & 0xff)<<std::endl;
                std::cout<<"WebP Mux version: "<<((mux_version >> 16) & 0xff)<<"."<<((mux_version >> 8) & 0xff)<<"."<<(mux_version & 0xff)<<std::endl;
                std::cout<<"tgs2animated version: 0.0.1"<<std::endl;
                return 0;
            } else if ((!strcmp(argv[c], "-wh") || !strcmp(argv[c],"-hw")) && c + 1 < argc) {
                wh = ExUtilGetInt(argv[++c], 0, &parse_error);
            } else if (!strcmp(argv[c], "-q") && c + 1 < argc) {
                q = ExUtilGetFloat(argv[++c], &parse_error);
            } else if (!strcmp(argv[c], "-m") && c + 1 < argc) {
                m = ExUtilGetInt(argv[++c], 0, &parse_error);
            } else if (!strcmp(argv[c], "-o") && c + 1 < argc){
                op = argv[++c];
            } else if (!strcmp(argv[c], "-i") && c + 1 < argc){
                file = argv[++c];
            } else {
                parse_error = 1;
                std::cout<<"Unknown option ["<<argv[c]<<"]"<<std::endl;
            }
            ok = !parse_error;
            if (!ok) return 1;
            continue;
        }
    }
    if (file.empty()) {
        std::cout<<"[no input file specified]"<<std::endl;
        Help();
        return 1;
    }
    if (op.empty()) {
        std::cout<<"[no output file specified]"<<std::endl;
        return 1;
    }

    std::cout<<"quality = "<<q<<std::endl;
    std::cout<<"method = "<<m<<std::endl;
    std::cout<<"minimize = "<<min_size<<std::endl;
    std::cout<<"Size = "<<wh<<"x"<<wh<<std::endl;
    std::cout<<"output = "<<op<<std::endl;

    DataHolder data(q, m, min_size, wh, wh);
    return convert(file, op);

}
