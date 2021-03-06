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

	groupBox = new QGroupBox(widget);
	groupBox->setLayout(new QHBoxLayout);
	image = new ImageStreamWidget(groupBox);
	groupBox->layout()->addWidget(image->image->getQLabel());
}

/**
 * Crée les actions
 */
void MainWindow::createActions() {
	/*
	 * actions I/O et exécutables (facon film)
	 */
	actionOpenFiles = new QAction(tr("&Open Files"), this);
	actionOpenFiles->setShortcut(QKeySequence(Qt::Key_O));
	actionOpenFiles->setStatusTip(tr("Open a set of images"));
	connect(actionOpenFiles, &QAction::triggered, this, &MainWindow::openFiles);

	actionOpenFolder = new QAction(tr("&Open Folder"), this);
	actionOpenFolder->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	actionOpenFolder->setStatusTip(tr("Open a folder of images"));
	connect(actionOpenFolder, &QAction::triggered, this, &MainWindow::openFolder);

	actionRunNext = new QAction(tr("&Run next"), this);
	actionRunNext->setShortcut(QKeySequence(Qt::Key_Space));
	actionRunNext->setStatusTip(tr("Run next"));
	connect(actionRunNext, &QAction::triggered, this, &MainWindow::runNext);

	actionRunLoop = new QAction(tr("&Run loop"), this);
	actionRunLoop->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Space));
	actionRunLoop->setStatusTip(tr("Run loop"));
	actionRunLoop->setCheckable(true);
	actionRunLoop->setChecked(false);
	connect(actionRunLoop, &QAction::triggered, this, &MainWindow::runThread);

	/*
	 * algorithmes a choisir pour le tracking
	 */
	actionPearson = new QAction(tr("&Track with Pearson correlation"), this);
	actionPearson->setShortcut(QKeySequence(Qt::Key_A));
	actionPearson->setStatusTip(tr("Track with Pearson correlation"));
	actionPearson->setCheckable(true);

	actionSAD = new QAction(tr("&Track with SAD correlation"), this);
	actionSAD->setShortcut(QKeySequence(Qt::Key_Z));
	actionSAD->setStatusTip(tr("Track with SAD correlation"));
	actionSAD->setCheckable(true);

	actionSSD = new QAction(tr("&Track with SSD correlation"), this);
	actionSSD->setShortcut(QKeySequence(Qt::Key_E));
	actionSSD->setStatusTip(tr("Track with SSD correlation"));
	actionSSD->setCheckable(true);

	actionOpticalFlow = new QAction(tr("&Track with optical flow"), this);
	actionOpticalFlow->setShortcut(QKeySequence(Qt::Key_R));
	actionOpticalFlow->setStatusTip(tr("Track with optical flow"));
	actionOpticalFlow->setCheckable(true);

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
	menuFile->addAction(actionRunNext);
	menuFile->addAction(actionRunLoop);

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
	QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Images"), "../sequences/", tr("Image Files (*.png *.jpg *.JPG *.bmp *.tiff)"));
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
	QDir directory(QFileDialog::getExistingDirectory(this, tr("Open folder"), "../sequences/"));
	QStringList fileNames = directory.entryList(QStringList() << tr("*.jpg") << tr("*.JPG") << tr("*.bmp") << tr("*.tiff") << tr("*.png"), QDir::Files);
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
 * Slot action: lance la prochaine frame et ses actions.
 */
void MainWindow::runNext() {
	if (!actionRunLoop->isChecked()) {
		image->next();
	}
}

/**
 * Slot action: lancer ou non le thread
 * boucle infinie dans un thread
 * timer permettant 60 FPS
 */
void MainWindow::runThread() {
	if (actionRunLoop->isChecked()) {
		runner = new WorkerThread;
		//connect(runner, &WorkerThread::resultReady, this, &MainWindow::handleResults);
		runner->start();
	}
}
