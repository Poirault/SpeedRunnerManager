#ifndef APPLICATION_H
#define APPLICATION_H
#include <qapplication>


class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int& argc, char** argv);
    void notifyHotkeyStatus(bool value);

signals:
    void hotkey(bool);
};


#endif // APPLICATION_H
