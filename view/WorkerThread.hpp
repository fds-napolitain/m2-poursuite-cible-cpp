//
// Created by Maxime Boucher on 16/11/2021.
//

#ifndef TARGETTRACKING_WORKERTHREAD_HPP
#define TARGETTRACKING_WORKERTHREAD_HPP


#include <QTimer>
#include <QThread>

class WorkerThread : public QThread {

	Q_OBJECT

public:
	WorkerThread();
	void run() override;
signals:
	void resultReady(const QString &s);

};


#endif //TARGETTRACKING_WORKERTHREAD_HPP
