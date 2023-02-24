#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtInvoiceApplication.h"
#include <QMouseEvent>
#include <QPoint>
#include <QSize>


class QtInvoiceApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtInvoiceApplication(QWidget *parent = nullptr);
    ~QtInvoiceApplication();

private:
    Ui::MainWindow *ui;

    QPoint cur_pos;
    QPoint new_pos;
    QSize cur_size;
    QSize new_size;
    QSize windowSize;

    int edgeSize = 10;
    bool isMaximised = false;
    bool isResizing = false;

    QPoint resizingStartPos;
    QSize resizingStartSize;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

    void changeEvent(QEvent* event);

private slots:
    void on_closeButton_clicked();
    void on_maximizeButton_clicked();
    void on_minimizeButton_clicked();
    void on_restoreButton_clicked();

};