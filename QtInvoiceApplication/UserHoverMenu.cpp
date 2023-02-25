#include "UserHoverMenu.h"
#include <QtWidgets/QMainWindow>

HoverFrame::HoverFrame(QFrame* activeUserFrame){
    this->activeUserFrame = activeUserFrame;

    // Creating menu for active user
    menu = new QMenu(activeUserFrame);
    action1 = new QAction("User Settings", activeUserFrame);
    action2 = new QAction("Sign out", activeUserFrame);
    menu->addAction(action1);
    menu->addAction(action2);

    menu->setObjectName("activeUserMenu");
    action1->setObjectName("actionUserSettings");
    action2->setObjectName("actionSignOut");

}

void HoverFrame::onHoverEnter(){
    qDebug() << "Hover entered in HoverFrame";
    QPoint globalPos = activeUserFrame->mapToGlobal(activeUserFrame->rect().bottomRight() - QPoint(0, menu->sizeHint().height()));
    menu->popup(globalPos);
}

void HoverFrame::actionUserSettings() {
    qDebug() << "Action User Settings";
}
void HoverFrame::actionSignOut() {
    qDebug() << "Action Sign Out";
}