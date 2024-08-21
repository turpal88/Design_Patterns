del /q build
del /q install
cmake -B build -DBUILD_SHARED_LIBS=OFF -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
pause