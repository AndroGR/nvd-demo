/***********************************************************************
 * Copyright 2022 Aggelos Tselios.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

#include "nvd_demo.h"
#include <GLFW/glfw3.h>

int main(int argc, char **argv) {
        int result = nvd_init(argv[0]);
        if (result != 0) {
                printf("Failed to initialize NvDialog (error %d): %s\n",
                       nvd_get_error(),
                       nvd_stringify_error(nvd_get_error()));
                abort();
        }

        if (glfwInit() != true) {
                const char* buffer;
                glfwGetError(&buffer);
                printf("Failed to initialize GLFW: %s\n", buffer);
                abort();
        }

        GLFWwindow* window = glfwCreateWindow(NVD_WINDOW_WIDTH,
                                              NVD_WINDOW_HEIGHT,
                                              "NvDialog Demo",
                                              NULL,
                                              NULL);
        if (!window) {
                const char* buffer;
                glfwGetError(&buffer);
                glfwTerminate();

                printf("Failed to create main window: %s\n", buffer);
                abort();
        } else {
                glfwMakeContextCurrent(window);
                glewInit();
        }

        float color_red    = 0.0f;
        float color_green  = 0.0f;
        float color_blue   = 0.0f;
        bool  dialog_shown = false;

        while (!glfwWindowShouldClose(window)) {
                if (!(color_blue >= 0.96f))
                        color_blue += 0.03f;
                else if (!(color_red >= 0.96f))
                        color_red += 0.03f;
                else if (!(color_green >= 0.96f))
                        color_green += 0.03f;
                else {
                        color_red   = 0.1f;
                        color_green = 0.1f;
                        color_blue  = 0.1f;
                }
                glClearColor(color_red, color_green, color_blue, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                if (!dialog_shown) {
                        app_basic_dialog();
                        app_question();
                        dialog_shown = true;
                }

                app_threaded_dialog();
                glfwSwapBuffers(window);
                glfwPollEvents();
        }

        glfwTerminate();
        return 0;
}