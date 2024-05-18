# DDE
My drawing engine library that uses OpenGL under the hood.

# Libraries

These are all the libraries used in DDE. DDE uses statically built library files that are packaged with the project. The branch and hash these library files are based off of is included below.

## GLFW
GLFW is the windowing library used to easily create a window and handle incoming window events. It also provides an easy way to create an OpenGL context.

Branch - `master`

Hash - `b35641f4a3c62aa86a0b3c983d163bc0fe36026d`

## GLAD
GLAD is the library that will provide DDE access to modern OpenGL function pointers. GLAD is typically downloaded as a `.c` file and compiled and linked with a project. DDE however compiles Glad to a static library `.a` file to keep it consistent with the other libraries. This `.c` file is downloaded from `glad.dav1d.de` and is different based on the version of OpenGL specified. The detailed specification for the version of GLAD that DDE uses is shown below.

Language - `C/C++`

Specification - `OpenGL`

Profile - `Core`

API/gl - `Version 4.6`

API/gles1 - `None`

API/gles2 - `None`

API/glsc2 - `None`

[X] Generate a loader

[] Omit KHR

[] Local Files
