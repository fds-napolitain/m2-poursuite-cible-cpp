//
// Created by Maxime Boucher on 16/11/2021.
//

#ifndef M2_POURSUITE_CIBLE_2_MAINWINDOW_HPP
#define M2_POURSUITE_CIBLE_2_MAINWINDOW_HPP


#include <QMainWindow>
#include <QGroupBox>
#include <QtWidgets>
#include <QString>
#include "ImageStreamWidget.hpp"
#include "WorkerThread.hpp"

class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow();
private:
	QMenu* menuFile;
	QMenu* menuAlgorithms;
	QAction* actionOpenFiles;
	QAction* actionOpenFolder;
	QAction* actionRunNext;
	QAction* actionRunLoop;
	QActionGroup* actionGroupAlgorithms;
	QAction* actionPearson;
	QAction* actionSAD;
	QAction* actionSSD;
	QAction* actionOpticalFlow;
	QWidget* widget;
	QGroupBox* groupBox;
	ImageStreamWidget* image;
	WorkerThread* runner;
	void createActions();
	void createMenus();
	void runNext();
private slots:
	void openFiles();
	void openFolder();
	void runThread();

};


#endif //M2_POURSUITE_CIBLE_2_MAINWINDOW_HPP
