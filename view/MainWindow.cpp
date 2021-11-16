//
// Created by Maxime Boucher on 16/11/2021.
//

#include "MainWindow.hpp"
#include <QPixmap>
#include <iostream>

/**
 * Fenêtre principale
 */
MainWindow::MainWindow() : QMainWindow() {
	widget = new QWidget;
	setCentralWidget(widget);

	createActions();
	createMenus();

	hdrbox = new QGroupBox(widget);
	hdrbox->setLayout(new QHBoxLayout);
	image = new ImageStreamWidget(hdrbox);
	hdrbox->layout()->addWidget(image->image->getQLabel());
}

/**
 * Crée les actions
 */
void MainWindow::createActions() {
	actionOpenFiles = new QAction(tr("&Open Files"), this);
	actionOpenFiles->setShortcut(QKeySequence(Qt::Key_O));
	actionOpenFiles->setStatusTip(tr("Open a set of images"));
	connect(actionOpenFiles, &QAction::triggered, this, &MainWindow::openFiles);

	actionOpenFolder = new QAction(tr("&Open Folder"), this);
	actionOpenFolder->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	actionOpenFolder->setStatusTip(tr("Open a folder of images"));
	connect(actionOpenFolder, &QAction::triggered, this, &MainWindow::openFolder);

	actionPearson = new QAction(tr("&Track with Pearson correlation"), this);
	actionPearson->setShortcut(QKeySequence(Qt::Key_A));
	actionPearson->setStatusTip(tr("Track with Pearson correlation"));
	actionPearson->setCheckable(true);
	connect(actionPearson, &QAction::triggered, this, &MainWindow::correlatePearson);

	actionSAD = new QAction(tr("&Track with SAD correlation"), this);
	actionSAD->setShortcut(QKeySequence(Qt::Key_Z));
	actionSAD->setStatusTip(tr("Track with SAD correlation"));
	actionSAD->setCheckable(true);
	connect(actionSAD, &QAction::triggered, this, &MainWindow::correlateSAD);

	actionSSD = new QAction(tr("&Track with SSD correlation"), this);
	actionSSD->setShortcut(QKeySequence(Qt::Key_E));
	actionSSD->setStatusTip(tr("Track with SSD correlation"));
	actionSSD->setCheckable(true);
	connect(actionSSD, &QAction::triggered, this, &MainWindow::correlateSSD);

	actionOpticalFlow = new QAction(tr("&Track with optical flow"), this);
	actionOpticalFlow->setShortcut(QKeySequence(Qt::Key_R));
	actionOpticalFlow->setStatusTip(tr("Track with optical flow"));
	actionOpticalFlow->setCheckable(true);
	connect(actionOpticalFlow, &QAction::triggered, this, &MainWindow::opticalFlow);

	actionGroupAlgorithms = new QActionGroup(this);
	actionGroupAlgorithms->setExclusive(true);
	actionGroupAlgorithms->addAction(actionPearson);
	actionGroupAlgorithms->addAction(actionSAD);
	actionGroupAlgorithms->addAction(actionSSD);
	actionGroupAlgorithms->addAction(actionOpticalFlow);
}

/**
 * Crée les menus
 */
void MainWindow::createMenus() {
	menuFile = menuBar()->addMenu(tr("&File"));
	menuFile->addAction(actionOpenFiles);
	menuFile->addAction(actionOpenFolder);

	menuAlgorithms = menuBar()->addMenu(tr("&Algorithms"));
	menuAlgorithms->addAction(actionPearson);
	menuAlgorithms->addAction(actionSAD);
	menuAlgorithms->addAction(actionSSD);
	menuAlgorithms->addAction(actionOpticalFlow);
}

/**
 * Slot action: ouvrir une ou plusieurs images
 */
void MainWindow::openFiles() {
	QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Images"), "../images/", tr("Image Files (*.png *.jpg *.JPG *.bmp)"));
	if (fileNames.empty()) {
		qDebug() << tr("Empty file list");
		return;
	}
	image->loadImages(fileNames);
	qDebug() << fileNames;
}

/**
 * Slot action: ouvrir un dossier d'images
 */
void MainWindow::openFolder() {
	QDir directory(QFileDialog::getExistingDirectory(this, tr("Open folder"), "../images/"));
	QStringList fileNames = directory.entryList(QStringList() << tr("*.jpg") << tr("*.JPG"), QDir::Files);
	for (QString& fileName: fileNames) {
		fileName = directory.path().append(tr("/")).append(fileName);
	}
	if (fileNames.empty()) {
		qDebug() << tr("Empty folder");
		return;
	}
	image->loadImages(fileNames);
	qDebug() << fileNames;
}

/**
 *
 */
void MainWindow::correlatePearson() {

}

/**
 *
 */
void MainWindow::correlateSAD() {

}

/**
 *
 */
void MainWindow::correlateSSD() {

}

/**
 *
 */
void MainWindow::opticalFlow() {

}
