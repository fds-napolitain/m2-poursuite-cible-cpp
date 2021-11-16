//
// Created by Maxime Boucher on 16/11/2021.
//

#include "ImageStreamWidget.hpp"

/**
 * Constructeur par défaut
 */
ImageStreamWidget::ImageStreamWidget() {
	image = new ImageWidget(this);
}


/**
 * Constructeur avec un widget parent.
 * @param parent
 */
ImageStreamWidget::ImageStreamWidget(QWidget *parent) {
	image = new ImageWidget(this);
	setParent(parent);
}

/**
 * Destructeur
 */
ImageStreamWidget::~ImageStreamWidget() {
	delete image;
}

/**
 * Charge les images du disque, et affiche la première.
 * @param filenames
 */
void ImageStreamWidget::loadImages(const QStringList& filenames) {
	n = filenames.size();
	images.resize(n);
	for (int i = 0; i < n; i++) {
		images[i].loadImage(filenames[i]);
	}
	next();
}

/**
 * Affiche l'image suivante et fait tourner l'algorithme défini.
 */
void ImageStreamWidget::next() {
	image->loadImage(images[indice]);
	(++indice) %= n;
}
