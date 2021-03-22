# tgs2animated
Converts animated Telegram stickers (*.tgs) to animated WEBPs (.webp)

##Building from source

1. Make sure you have g++, make and cmake installed
1. Clone this repository
   
```
git clone --recursive https://github.com/PeterMX/tgs2animated.git
```
3. Build

```
cd tgs2animated
mkdir build
cd build
cmake ..
make -j 2
```
###Convert
Pass an input tgs and an output webp
```
$ ./tgs2animated -i ./sticker.tgs -o ./animation.webp
```
###CLI arguments
```
$ ./tgs2animated -help
Usage:
 tgs2animated [options] -i tgs_file -o webp_file
  -i <tgs_file>............. input tgs file[Required]
  -o <webp_file>............ output webp file[Required]
Options:
  -h / -help ............... this help
  -q <float> ............... quality factor (0:small..100:big)
  -m <int> ................. compression method (0=fast, 6=slowest)
  -min_size ................ minimize size
  -wh <int>................. Width and height in px

  -version ................. print version number and exit

```