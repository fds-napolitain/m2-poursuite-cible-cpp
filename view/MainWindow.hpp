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

class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow();
private:
	QMenu* menuFile;
	QMenu* menuAlgorithms;
	QAction* actionOpenFiles;
	QAction* actionOpenFolder;
	QAction* actionRun;
	QActionGroup* actionGroupAlgorithms;
	QAction* actionPearson;
	QAction* actionSAD;
	QAction* actionSSD;
	QAction* actionOpticalFlow;
	QWidget* widget;
	QGroupBox* groupBox;
	ImageStreamWidget* image;
	void createActions();
	void createMenus();
private slots:
	void openFiles();
	void openFolder();
	void runLoop();

};


#endif //M2_POURSUITE_CIBLE_2_MAINWINDOW_HPP
