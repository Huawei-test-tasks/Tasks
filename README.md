#  Linux CMake build:
1. cd \<git clone dir\>
2. mkdir ./build
3. cmake -DCMAKE_BUILD_TYPE=Release -B./build
4. cmake --build ./build --config Release --target all -j \`nproc\`
5. Executable files will appear in the directory ./build/bin
6. To clean the build just remove build dir.
