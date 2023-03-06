#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtInvoiceApplication.h"

#include "UserHoverMenu.h"
#include "dashboardWidget.h"
#include "invoiceWidget.h"

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
    HoverFrame* hoverFrame;

    QFrame* activeUserFrame;
    QStackedWidget* mainStackedWidget;


    DashboardWidget* dashboardWidget;
    InvoiceWidget* invoiceWidget;

    QPoint cur_pos;
    QPoint new_pos;
    QSize cur_size;
    QSize new_size;
    QSize windowSize;

    const int edgeSize = 8;
    bool isMaximised = false;
    bool isResizing = false;

    QPoint resizingStartPos;
    QSize resizingStartSize;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    bool eventFilter(QObject* object, QEvent* event);

    void changeEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void actionUserSettingsTriggered();
    void actionSignOutTriggered();

private slots:
    void on_closeButton_clicked();
    void on_maximizeButton_clicked();
    void on_minimizeButton_clicked();
    void on_restoreButton_clicked();

    // Sidebar buttons
    void on_dashboardButton_clicked();
    void on_contactButton_clicked();
    void on_financeButton_clicked();
    void on_invoiceButton_clicked();
    void on_productButton_clicked();
};