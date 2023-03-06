#include "dashboardWidget.h"

DashboardWidget::DashboardWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Form)
{
	ui->setupUi(this);

	bigButton = ui->bigButton;

	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->horizontalHeader()->setStretchLastSection(false);


	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("database/InvoiceDatabase.db");
	if (!db.open()) {
		qWarning() << "Cannot open database.";
		return;
	}


	QSqlQuery query;
	query.prepare("SELECT * FROM users_table");
	if (!query.exec()) {
		qWarning() << "Query error: " << query.lastError().text();
		return;
	}
	ui->tableWidget->setRowCount(query.size());
	ui->tableWidget->setColumnCount(query.record().count());

	for (int i = 0; i < query.record().count(); i++) {
		QTableWidgetItem* headerItem = new QTableWidgetItem();
		headerItem->setText(query.record().fieldName(i));
		ui->tableWidget->setHorizontalHeaderItem(i, headerItem);
	}

	int row = 0;
	while (query.next()) {
		ui->tableWidget->insertRow(row);

		int id = query.value(0).toInt();
		QString username = query.value(1).toString();
		QString email = query.value(2).toString();
		int isEnabled = query.value(3).toInt();
		int isAdmin = query.value(4).toInt();
		qInfo() << id << username << email << isEnabled << isAdmin;

		QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(id));
		QTableWidgetItem* item2 = new QTableWidgetItem(username);
		QTableWidgetItem* item3 = new QTableWidgetItem(email);
		QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(isEnabled));
		QTableWidgetItem* item5 = new QTableWidgetItem(QString::number(isAdmin));

		ui->tableWidget->setItem(row, 0, item1);
		ui->tableWidget->setItem(row, 1, item2);
		ui->tableWidget->setItem(row, 2, item3);
		ui->tableWidget->setItem(row, 3, item4);
		ui->tableWidget->setItem(row, 4, item5);

		++row;
	}



	db.close();



	connect(bigButton, &QPushButton::clicked, this, &DashboardWidget::bigButton_clicked);
}

DashboardWidget::~DashboardWidget(){
	delete bigButton;
	delete ui;
}

void DashboardWidget::bigButton_clicked() {
	qDebug() << "bigButton_clicked";
}