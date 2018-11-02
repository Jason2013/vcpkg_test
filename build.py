# coding=utf-8

import os

print(os.environ["APPVEYOR_BUILD_WORKER_IMAGE"])
print(os.environ["Configuration"])
print(os.environ["Platform"])

VS = os.environ["APPVEYOR_BUILD_WORKER_IMAGE"]
Config = os.environ["Configuration"]
Platform = os.environ["Platform"]

VS_MAP = {
    "Visual Studio 2017" : "Visual Studio 15 2017",
    "Visual Studio 2015" : "Visual Studio 14 2015",
    "Visual Studio 2013" : "Visual Studio 12 2013",
    "Visual Studio 2012" : "Visual Studio 11 2012",
    "Visual Studio 2010" : "Visual Studio 10 2010",
    "Visual Studio 2008" : "Visual Studio 9 2008",
}

Generator = VS_MAP[VS]
if Platform == "x64":
    Generator += " Win64"

ERROR_COMMAND = 'IF %ERRORLEVEL% NEQ 0 EXIT /B 1'
CMAKE_COMMAND1 = 'cmake -G"{GENERATOR}" -DCMAKE_TOOLCHAIN_FILE=c:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake ..'.format(GENERATOR=Generator)
CMAKE_COMMAND2 = 'cmake --build . --config ' + Config

CMAKE_COMMANDS = ["mkdir build",
    "cd build",
    CMAKE_COMMAND1,
    ERROR_COMMAND,
    CMAKE_COMMAND2,
    ERROR_COMMAND,
    "cd ..",
    "\n",
]

with open("build.bat", "w") as f:
    f.write("\n".join(CMAKE_COMMANDS))
