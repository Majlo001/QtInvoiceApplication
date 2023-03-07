#pragma once

#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include <QWidget>
#include "ui_dashboardWidget.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DashboardWidget : public QWidget
{
	//Q_OBJECT

public:
	DashboardWidget(QWidget *parent = nullptr);
	~DashboardWidget();

private:
	Ui::Form *ui;
	QPushButton* bigButton;
	QSqlDatabase db;

	void bigButton_clicked();
};

#endif //DASHBOARDWIDGET_H