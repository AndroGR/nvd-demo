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
#if defined(__linux__) || defined(__linux) || defined(__gnu_linux__)
#include <pthread.h>
#else
#warning "Will not create multithreaded dialogs, as the system does not support pthread."
#endif /* __linux__ */

static void __dlg_pthread(void) {
        puts("thread2");
        NvdDialogBox* dialog = nvd_dialog_box_new("Multithreaded dialog",
                                                  "As you can see, unlike the previous dialogs, NvDialog"
                                                  "can also make use of multiple threads to run independently of"
                                                  "the main application thread, which may be what you want sometimes.",
                                                  NVD_DIALOG_SIMPLE);
        nvd_show_dialog(dialog);
        nvd_free_object(dialog);
}

void app_basic_dialog() {
        NvdDialogBox* dialog = nvd_dialog_box_new("Welcome to NvDialog",
                                                  "NvDialog is a simple library that allows\n"
                                                  "you to create dialog boxes like these. It uses\n"
                                                  "a system API to make it easy to follow the system theme too.\n",
                                                  NVD_DIALOG_SIMPLE);
        NvdDialogBox* warning_dialog = nvd_dialog_box_new("Warnings and errors are supported!\n",
                                                          "A library like this would be incomplete if you couldn't\n"
                                                          "make it obvious from the dialog that an error has occured.\n"
                                                          "You can use NVD_DIALOG_SIMPLE, NVD_DIALOG_WARNING, or NVD_DIALOG_ERROR\n"
                                                          "to respectively style the dialog as an informational, a warning or an error one.\n",
                                                          NVD_DIALOG_WARNING);
        
        nvd_show_dialog(dialog);
        nvd_show_dialog(warning_dialog);
}

void app_question() {
        NvdQuestionBox* dialog = nvd_dialog_question_new("Would you like to exit?",
                                                         "If you press yes, the demo will exit here.",
                                                         NVD_YES_NO);
        char* title;
        char* message;
        NvdReply rep = nvd_get_reply(dialog);

        switch (rep) {
        case NVD_REPLY_OK:
                title   = "Terminating the application.";
                message = "The application will now terminate. Goodbye!";
                break;
        case NVD_REPLY_NO:
                title   = "Won't terminate.";
                message = "The application will continue running.";
                break;
        }

        NvdDialogBox* dlg = nvd_dialog_box_new(title, message, NVD_DIALOG_SIMPLE);
        nvd_show_dialog(dlg);

        nvd_free_object(dlg);
        nvd_free_object(dialog);
        exit(EXIT_SUCCESS);
}

void app_threaded_dialog() {
        #if defined(__linux__) || defined(__linux) || defined(__gnu_linux__)
        pthread_t thread = 0;
        pthread_create(&thread, NULL, __dlg_pthread, NULL);
        #endif /* __linux__ */
}