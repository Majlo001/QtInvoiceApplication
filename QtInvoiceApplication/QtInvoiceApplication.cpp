#include "QtInvoiceApplication.h"
#include "ui_QtInvoiceApplication.h"
#include <iostream>
#include <QMessageBox>

QtInvoiceApplication::QtInvoiceApplication(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_Hover);

    activeUserFrame = ui->activeUser;
    mainStackedWidget = ui->mainStackedSpace;


    ui->restoreButton->setVisible(false);
    //ui->dashboardButton->setDown(true);

    hoverFrame = new HoverFrame(activeUserFrame);
    activeUserFrame->installEventFilter(this);

    dashboardWidget = new DashboardWidget(this);
    mainStackedWidget->addWidget(dashboardWidget);


    connect(hoverFrame->action1, &QAction::triggered, this, &QtInvoiceApplication::actionUserSettingsTriggered);
    connect(hoverFrame->action2, &QAction::triggered, this, &QtInvoiceApplication::actionSignOutTriggered);
}

QtInvoiceApplication::~QtInvoiceApplication()
{
    delete ui;
    delete hoverFrame;
    delete activeUserFrame;
    delete mainStackedWidget;
}


void QtInvoiceApplication::mousePressEvent(QMouseEvent* event) {
    if (ui->Header->underMouse()) {
        cur_pos = event->globalPosition().toPoint();
        isMaximised = false;
    }


    if (event->button() == Qt::LeftButton) {
        QPoint cursorPos = event->pos();
        QRect windowRect = geometry();

        QMessageBox msg;


        int tmpRectY = windowRect.y() + windowRect.height();

        // Check if the cursor is on the top edge of the window
        if (cursorPos.y() <= windowRect.top()) {
            resizingStartPos = cursorPos;
            resizingStartSize = size();
        }
        // Check if the cursor is on the bottom edge of the window
        else if (cursorPos.y() <= tmpRectY && cursorPos.y() >= (tmpRectY - edgeSize)) {
            isResizing = true;
            resizingStartPos = cursorPos;
            resizingStartSize = size();
            msg.setText("Bottom");
            msg.exec();
        }
        // Check if the cursor is on the left edge of the window
        else if (cursorPos.x() <= windowRect.left()) {
            isResizing = true;
            resizingStartPos = cursorPos;
            resizingStartSize = size();
        }
        // Check if the cursor is on the right edge of the window
        else if (cursorPos.x() >= windowRect.right()) {
            isResizing = true;
            resizingStartPos = cursorPos;
            resizingStartSize = size();
        }
    }
}
void QtInvoiceApplication::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && isResizing) {
        isResizing = false;
    }
    QMainWindow::mouseReleaseEvent(event);
}
void QtInvoiceApplication::mouseDoubleClickEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && event->modifiers() == Qt::NoModifier && ui->Header->underMouse()){
        if (windowState().testFlag(Qt::WindowNoState)) {
            on_maximizeButton_clicked();
        }
        else if (windowState().testFlag(Qt::WindowMaximized)) {
            on_restoreButton_clicked();
        }
    }
}
void QtInvoiceApplication::mouseMoveEvent(QMouseEvent* event) {
    if (ui->Header->underMouse()) {
        new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
        move(x() + new_pos.x(), y() + new_pos.y());
        cur_pos = event->globalPosition().toPoint();
    }


    QPoint cursorPos = event->pos();
    QRect windowRect = geometry();
    int tmpRectY = windowRect.y() + windowRect.height();

    if (cursorPos.y() <= tmpRectY && cursorPos.y() >= (tmpRectY - edgeSize)) {
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else {
        setCursor(QCursor(Qt::ArrowCursor));
    }

    //int x = event->x();
    //int y = event->y();
    //int width = this->width();
    //int height = this->height();

    //if (y >= height - edgeSize) {
    //    setCursor(QCursor(Qt::SizeVerCursor)); // krawêdŸ dolna
    //}
    //else if (x <= edgeSize) {
    //    setCursor(QCursor(Qt::SizeHorCursor)); // krawêdŸ lewa
    //}
    //else if (x >= width - edgeSize) {
    //    setCursor(QCursor(Qt::SizeHorCursor)); // krawêdŸ prawa
    //}
    //else if (y <= edgeSize) {
    //    setCursor(QCursor(Qt::SizeVerCursor)); // krawêdŸ górna
    //}
    //else {
    //    setCursor(QCursor(Qt::ArrowCursor)); // pozosta³e obszary
    //}



    if (isResizing) {
        QPoint cursorPos = event->pos();
        int newWidth = resizingStartSize.width() + (cursorPos.x() - resizingStartPos.x());
        int newHeight = resizingStartSize.height() + (cursorPos.y() - resizingStartPos.y());

        // Only resize in the bottom-right direction
        if (newWidth > minimumWidth() && newHeight > minimumHeight()) {
            resize(newWidth, newHeight);
        }
    }

    QWidget::mouseMoveEvent(event);
}



void QtInvoiceApplication::changeEvent(QEvent* event) {
    if (event->type() == QEvent::WindowStateChange) {
        if (windowState().testFlag(Qt::WindowNoState)) {
            if (isMaximised == true) {
                on_maximizeButton_clicked();
                event->ignore();
                return;
            }

            ui->restoreButton->setVisible(false);
            ui->maximizeButton->setVisible(true);
            event->ignore();
        }
        else if (windowState().testFlag(Qt::WindowMaximized)) {
            isMaximised = true;
            ui->restoreButton->setVisible(true);
            ui->maximizeButton->setVisible(false);
            event->ignore();
        }
    }
    event->accept();
}
void QtInvoiceApplication::leaveEvent(QEvent* event) {
    setCursor(QCursor(Qt::ArrowCursor));
    QWidget::leaveEvent(event);
}


// Top right buttons
void QtInvoiceApplication::on_closeButton_clicked() {
    close();
}
void QtInvoiceApplication::on_maximizeButton_clicked() {
    isMaximised = true;
    ui->restoreButton->setVisible(true);
    ui->maximizeButton->setVisible(false);
    setWindowState(Qt::WindowMaximized);
    showMaximized();
}
void QtInvoiceApplication::on_minimizeButton_clicked() {
    setWindowState(Qt::WindowMinimized);
}
void QtInvoiceApplication::on_restoreButton_clicked() {
    isMaximised = false;
    ui->restoreButton->setVisible(false);
    ui->maximizeButton->setVisible(true);
    setWindowState(Qt::WindowNoState);
}


// Sidebar buttons
void QtInvoiceApplication::on_dashboardButton_clicked() {};
void QtInvoiceApplication::on_contactButton_clicked() {};
void QtInvoiceApplication::on_financeButton_clicked() {};
void QtInvoiceApplication::on_invoiceButton_clicked() {};
void QtInvoiceApplication::on_productButton_clicked() {};

bool QtInvoiceApplication::eventFilter(QObject* object, QEvent* event){
    if (object == activeUserFrame) {
        if (event->type() == QEvent::Enter) {
            hoverFrame->onHoverEnter();
            return true;
        }
        /*else if (event->type() == QEvent::Leave) {
            hoverFrame->onHoverLeave();
            return true;
        }*/
    }


    return QMainWindow::eventFilter(object, event);
}
void QtInvoiceApplication::actionUserSettingsTriggered() {
    hoverFrame->actionUserSettings();
}
void QtInvoiceApplication::actionSignOutTriggered() {
    hoverFrame->actionSignOut();
}