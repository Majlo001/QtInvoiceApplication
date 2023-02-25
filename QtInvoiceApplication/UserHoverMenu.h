#pragma once

#ifndef HOVERFRAME_H
#define HOVERFRAME_H

#include <QFrame>
#include <QMenu>

class HoverFrame{
public:
    explicit HoverFrame(QFrame* activeUserFrame = nullptr);
    void onHoverEnter();
    void actionUserSettings();
    void actionSignOut();

    QAction* action1;
    QAction* action2;

private:
    QMenu* menu;
    QFrame* activeUserFrame;
};

#endif // HOVERFRAME_H
