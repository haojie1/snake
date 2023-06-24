# snake
A snake game based on SDL2, SDL2_image and SDL2_ttf. A project for practing SDL2 library.

# Windows and Linux
In this project, you don't need download or install any other library, all we need are in this project except the "make" and "g++" tools. Whatever you are using linux or windows system, the only thing you need modify is the "Makefile".
## Windows
comment "OS=LINUX" and uncomment "OS=WINDOWS"
## Linux
comment "OS=WINDOWS" and uncomment "OS=LINUX"

# some pictures for running this game
![startUI](https://github.com/haojie1/snake/blob/main/src/image/startUI.png?raw=true)
![process](https://github.com/haojie1/snake/blob/main/src/image/process.png?raw=true)
![exit](https://github.com/haojie1/snake/blob/main/src/image/exit.jpg?raw=true)

# Dependencies for Running
As saied before , Only "g++" and "make" tools are needed. SDL2, SDL2_Image and SDL2_TTF are included in this repo. So you don't need to download it any more. I think this will make life better for all beginners.  
## Windows
g++.exe (x86_64-posix-seh-rev2 6.3.0)
mingw32-make.exe (GNU Make 4.1, Built for x86_64-w64-mingw32)
[download address](https://github.com/niXman/mingw-builds-binaries/releases)
## Linux
Nothing you need to download and install. make and g++ are provided for almost all linux sytem.

# how to start
it's very easy to start this project. As you can see, all files and libs needed in this game are here. All you need to compile this program is to rum 'make' command. This program is tested only in windows.
1. Clone this repo.
2. modify "Makefile" according to your system
2. Compile: make
3. Run it: main.exe

# what is this project's goal?
I write this game for all beginner who want to learn sdl2 library. I think you can make better understand of sdl2 through this project, so enjoy and if you find some mistakes in this project, you are welcome to Pull Request.
