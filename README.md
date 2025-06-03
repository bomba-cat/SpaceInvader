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
This has been developed with the Windows version of ZFB.
