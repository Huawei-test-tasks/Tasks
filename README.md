#  Linux CMake build:
1. cd \<git clone dir\>
2. mkdir ./build
3. cmake -DCMAKE_BUILD_TYPE=Release -B./build
4. cmake --build ./build --config Release --target all -j \`nproc\`
5. Executable files will appear in the bin directory: \<git clone dir\>/build/bin
6. To clean the build just remove build dir.

# Usage
1. Launching programs (./build/bin/task1(2,3)) with a path to a file:
    ```
    task1 <path to data file>
    ```
2. Launching programs with I/O redirection:
    ```
    cat ./input_data_1.txt | ./task1
    ./task2 < ./input_data_2.txt
    ```
> Note: Directory `<git clone dir>/IOData` contains files with test data.
