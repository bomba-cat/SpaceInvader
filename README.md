The implementation of the classic SpaceInvader game in C using the [ZFB](https://github.com/The-Sigmas/ZFB.git) library.

# Build
## Windows
```bash
cmake -B build
cmake --build build
```
## Any Other
```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake
cmake --build build
```

# Note
This has been developed with the Windows version of [ZFB](https://github.com/The-Sigmas/ZFB.git).
