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

#include <nvdialog/nvdialog.h>
#include <stdio.h>
#include <stdlib.h>

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
        default: break;
        }

        NvdDialogBox* dlg = nvd_dialog_box_new(title, message, NVD_DIALOG_SIMPLE);
        nvd_show_dialog(dlg);

        nvd_free_object(dlg);
        nvd_free_object(dialog);

        if (rep == NVD_REPLY_OK) exit(EXIT_SUCCESS);
}

void app_about() {
        NvdAboutDialog* dialog = nvd_about_dialog_new("Nvd Demo",
                                                      "nvd-demo is a simple application that"
                                                      "demonstrates the capabilities of NvDialog.",
                                                      NULL);
        nvd_about_dialog_set_license_link(dialog, "https://github.com/AndroGR/nvd-demo/blob/master/COPYING", "License");
        nvd_about_dialog_set_version(dialog, "0.1.0");

        nvd_show_about_dialog(dialog);
        nvd_free_object(dialog);
}

void app_notification() {
        nvd_set_application_name("nvd-demo"); // The notification will show it
        const char* msg = "NvDialog supports notifications as well. While they aren't necessarily dialogs, "
        "it can easily become a hassle to set them up. Windows is the exception here; It isn't supported yet "
        "because it's a pretty complicated process to do so. It will be implemented in newer versions though.";
        NvdNotification* notification = nvd_notification_new("Notifications Supported",
                                                              msg, NVD_NOTIFICATION_SIMPLE);
        nvd_send_notification(notification);
        //nvd_delete_notification(notification);
}

void app_file_picker() {
        const char   * buffer;
        NvdFileDialog* dlg = nvd_open_file_dialog_new("Choose A File", NULL);
        nvd_get_file_location(dlg, &buffer);

        if (buffer) {
                char formatted[1024];
                sprintf(formatted, "You have selected the following file: %s. This is a very nice file!", buffer);
                NvdDialogBox* dialog = nvd_dialog_box_new("Chose A File!",
                                                          formatted,
                                                          NVD_DIALOG_SIMPLE);
                nvd_show_dialog(dialog);
                nvd_free_object(dialog);
        } else {
                NvdDialogBox* dialog = nvd_dialog_box_new("Didn't choose a file...",
                                                          "NvDialog determined that you didn't select a file. If that's wrong, please open an issue :)",
                                                          NVD_DIALOG_ERROR);
                nvd_show_dialog(dialog);
                nvd_free_object(dialog);
        }
}