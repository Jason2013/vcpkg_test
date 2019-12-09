# coding=utf-8

import os
import sys

def InstallScript(visualstudio, architecture, config):
    packages = [
        "glew",
        "glfw3",
        "glm",
    ]

    # vcpkg install --triplet=x86-windows:x64-windows <pkg>
    # Platform = os.environ["Platform"]
    # if not Platform in ["x86", "x64"]:
    #     raise AssertionError()

    ERROR_COMMAND = 'IF %ERRORLEVEL% NEQ 0 EXIT /B 1\n'
    VCPKG_INSTALL = "vcpkg install --triplet {ARCHITECTURE}-windows {PACKAGE}\n".format(ARCHITECTURE=architecture)

    s = ''.join([VCPKG_INSTALL.format(PACKAGE=pkg) + ERROR_COMMAND for pkg in packages])

    with open("install_{ARCHITECTURE}.bat".format(ARCHITECTURE=architecture), "w") as f:
        f.write(s)

def BuildScript(visualstudio, architecture, config):
    # print(os.environ["APPVEYOR_BUILD_WORKER_IMAGE"])
    # print(os.environ["Configuration"])
    # print(os.environ["Platform"])

    # VS = os.environ["APPVEYOR_BUILD_WORKER_IMAGE"]
    # Config = os.environ["Configuration"]
    # Platform = os.environ["Platform"]

    VS_MAP = {
        # "Visual Studio 2017" : "Visual Studio 15 2017",
        # "Visual Studio 2015" : "Visual Studio 14 2015",
        # "Visual Studio 2013" : "Visual Studio 12 2013",
        # "Visual Studio 2012" : "Visual Studio 11 2012",
        # "Visual Studio 2010" : "Visual Studio 10 2010",
        # "Visual Studio 2008" : "Visual Studio 9 2008",
    }

    # Generator = VS_MAP[VS]
    # if Platform == "x64":
    #     Generator += " Win64"

    ERROR_COMMAND = 'IF %ERRORLEVEL% NEQ 0 EXIT /B 1\n'
    CMAKE_COMMAND1 = 'cmake -G"{VISUALSTUDIO}" -A {ARCHITECTURE} -DCMAKE_TOOLCHAIN_FILE=%VCPKG_INSTALLATION_DIR%/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET={ARCHITECTURE}-windows ..\n'.format(VISUALSTUDIO=visualstudio, ARCHITECTURE=architecture)
    CMAKE_COMMAND2 = 'cmake --build . --config {CONFIG}\n'.format(CONFIG=config)

    BUILD_DIR = "build_{ARCHITECTURE}".format(ARCHITECTURE=architecture)
    CMAKE_COMMANDS = ["mkdir {}\n".format(BUILD_DIR),
        "cd {}\n".format(BUILD_DIR),
        CMAKE_COMMAND1,
        ERROR_COMMAND,
        CMAKE_COMMAND2,
        ERROR_COMMAND,
        "cd ..\n",
    ]

    with open("{}.bat".format(BUILD_DIR), "w") as f:
        f.write("".join(CMAKE_COMMANDS))

if __name__ == "__main__":
    if not len(sys.argv) == 5:
        raise AssertionError()

    mode = sys.argv[1]
    if not mode in ("install", "build"):
        raise AssertionError()

    visualstudio = sys.argv[2]
    architecture = sys.argv[3]
    config = sys.argv[4]
    print(mode)

    if mode == "install":
        InstallScript(visualstudio, architecture, config)
    elif mode == "build":
        BuildScript(visualstudio, architecture, config)
