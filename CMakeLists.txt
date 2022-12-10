cmake_minimum_required(VERSION 3.10)
project(nvd-demo
        LANGUAGES C
        VERSION 0.1.0
        DESCRIPTION "Demonstration application for NvDialog"
        HOMEPAGE_URL "https://github.com/AndroGR/nvd-demo.git")

set(NVD_DEMO_SOURCE_CODE src/main.c src/dialogs.c)

add_executable(nvd-demo ${NVD_DEMO_SOURCE_CODE})
target_link_libraries(nvd-demo PUBLIC nvdialog glfw GLEW m GL)