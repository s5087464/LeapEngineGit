1. First, Open "×64 Native Tools Command Prompt for VS 2022".
2. Type "cd /d (path for "LeapEngine")".
3. "cmake -B build"
4. "cmake --build build"
5. Go "contrib" -> "cl-windows-x86_64" -> "bin". Then copy all ".dll" filles.(And do not forget copy ".dll" from LeapSDK)
6. paste them at "build" file.
7. Open the ".sln". And in Solution explorer, right click the "demo". click the "Set as Startup Project".

Fnally, It will work.
