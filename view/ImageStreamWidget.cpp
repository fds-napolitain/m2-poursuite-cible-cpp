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
 * Charge les images du disque, et affiche la première.
 * @param filenames
 */
void ImageStreamWidget::loadImages(const QStringList& filenames) {
	n = filenames.size();
	images.resize(n);
	for (int i = 0; i < n; i++) {
		images[i].loadImage(filenames[i]);
	}
	image->loadImage(images[0]);
}

/**
 * Affiche l'image suivante et fait tourner l'algorithme défini.
 */
void ImageStreamWidget::reload() {

}
