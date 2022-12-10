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

#pragma once

#ifndef __nvd_demo_h__
#define __nvd_demo_h__ 1

#include <stdio.h>
#include <stdlib.h>
#include <nvdialog/nvdialog.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NVD_WINDOW_WIDTH  (800)
#define NVD_WINDOW_HEIGHT (600)

/* 
 * All dialogs that will be created. These functions
 * wrap around them and are then called from main().
 */
void app_basic_dialog();
void app_threaded_dialog();
void app_about_dialog();
void app_question();


#endif /* __nvd_demo_h__ */