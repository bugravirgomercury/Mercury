# Mercury
![](docs/resources/icon-128.png)

Mercury is a translating virtualizer for Android apps. 

# How to build
The default build is to use VSCode. Currently we only support building on VSCode.
- Open the devcontainer in VSCode. It will install BOOST v1.74.0 into the devcontainer while building its image.
- Configure & build Mercury through VSCode's `CMake Tools' extension. You must use clang++.
- Test the build by running CTest.
- The built library is in /workspaces/Mercury/build/libmercury.so.


**UNDER CONSTRUCTION**