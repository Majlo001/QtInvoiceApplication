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


    ui->restoreButton->setVisible(false);
}

QtInvoiceApplication::~QtInvoiceApplication()
{
    delete ui;
}


void QtInvoiceApplication::mousePressEvent(QMouseEvent* event) {
    if (ui->Header->underMouse()) {
        cur_pos = event->globalPosition().toPoint();
        isMaximised = false;
    }


    if (event->button() == Qt::LeftButton) {
        QPoint cursorPos = event->pos();
        //QRect windowRect = frameGeometry();
        QRect windowRect = geometry();

        // Check if the cursor is on the top edge of the window
        if (cursorPos.y() <= windowRect.top()) {
            resizingStartPos = cursorPos;
            resizingStartSize = size();
        }
        // Check if the cursor is on the bottom edge of the window
        else if (cursorPos.y() >= windowRect.bottom()) {
            isResizing = true;
            resizingStartPos = cursorPos;
            resizingStartSize = size();
            setCursor(Qt::SizeVerCursor);
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

    //windowSize = size();
    //if (event->pos().y() > windowSize.height() - edgeSize) {
    //    // The cursor is on the bottom edge of the window
    //    setCursor(Qt::SizeVerCursor);
    //}
    //else {
    //    setCursor(Qt::ArrowCursor);
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
}

void QtInvoiceApplication::changeEvent(QEvent* event) {
    QMessageBox msg;

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

