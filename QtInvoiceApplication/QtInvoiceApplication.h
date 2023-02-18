#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtInvoiceApplication.h"

class QtInvoiceApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtInvoiceApplication(QWidget *parent = nullptr);
    ~QtInvoiceApplication();

private:
    Ui::QtInvoiceApplicationClass ui;
};
