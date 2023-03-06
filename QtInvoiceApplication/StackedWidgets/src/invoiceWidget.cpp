#include "invoiceWidget.h"

InvoiceWidget::InvoiceWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::invoiceWidgetClass)
{
	ui->setupUi(this);

	scrollArea = ui->scrollArea;

}

InvoiceWidget::~InvoiceWidget(){
	delete ui;
}
