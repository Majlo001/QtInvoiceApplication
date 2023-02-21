#include "QtInvoiceApplication.h"
#include "ui_QtInvoiceApplication.h"

QtInvoiceApplication::QtInvoiceApplication(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
}

QtInvoiceApplication::~QtInvoiceApplication()
{
    delete ui;
}
