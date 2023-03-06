#pragma once

#include <QWidget>
#include "ui_invoiceWidget.h"

class InvoiceWidget : public QWidget
{
	//Q_OBJECT

public:
	InvoiceWidget(QWidget *parent = nullptr);
	~InvoiceWidget();

private:
	Ui::invoiceWidgetClass *ui;
	QScrollArea* scrollArea;
};
