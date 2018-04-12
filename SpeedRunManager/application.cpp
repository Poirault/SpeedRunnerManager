#include "application.h"




Application::Application(int& argc, char** argv):
    QApplication(argc, argv)
{
}


void Application::notifyHotkeyStatus(bool value) {
    emit hotkey(value);
}
