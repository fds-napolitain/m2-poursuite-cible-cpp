//
// Created by Maxime Boucher on 16/11/2021.
//

#include "WorkerThread.hpp"

/**
 * Constructeur par défaut
 */
WorkerThread::WorkerThread() = default;

void WorkerThread::run() {
	QString result;
	QTimer timer = QTimer(this);
	bool test = true;
	while (test) {
		//if (!actionRun->isChecked()) {
		//	test = false;
		//}
		//image->next();
		timer.start(16); // 60 FPS cap
	}
	emit resultReady(result);
}

void WorkerThread::resultReady(const QString &s) {

}
