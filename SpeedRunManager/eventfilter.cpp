#include "eventfilter.h"



EventFilter::EventFilter(QObject* parent):
    QObject(parent)
{
    hotkey = false;
}


bool EventFilter::eventFilter(QObject* object, QEvent* event) {
    // Skip if parent is not a custom application
    Application* app = dynamic_cast<Application *>(parent());

    if (app == NULL) {
        return false;
    }

    // Check key press event
    if (event->type() == QEvent::KeyPress) {
            if (!hotkey && static_cast<QKeyEvent *>(event)->modifiers() == HOTKEY) {
                // Emit signal
                app->notifyHotkeyStatus(true);

                // Store highlight status
                hotkey = true;

                // Stop propagation
                return true;
            }
        }


    // Check key release event
        if (event->type() == QEvent::KeyRelease) {
            // Emit highlightHelp(false) if hotkey's combination is not pressed
            // and they where active before
            if (hotkey && static_cast<QKeyEvent *>(event)->modifiers() != HOTKEY) {
                // Emit signal
                app->notifyHotkeyStatus(false);

                // Reset highlight status
                hotkey = false;

                // Stop propagation
                return true;
            }
        }

        // Propagate event
        return false;
    }
