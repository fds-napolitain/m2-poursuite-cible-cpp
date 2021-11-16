//
// Created by Maxime Boucher on 16/11/2021.
//

#include "ImageStreamWidget.hpp"

ImageStreamWidget::ImageStreamWidget() {
	image = new ImageWidget(this);
}

ImageStreamWidget::ImageStreamWidget(QWidget *parent) {
	image = new ImageWidget(this);
	setParent(parent);
}

/**
 * Charge les images du disque, et affiche la première.
 * @param filenames
 */
void ImageStreamWidget::loadImages(const QStringList& filenames) {
	images.resize(filenames.size());
	for (int i = 0; i < filenames.size(); i++) {
		images[i].loadImage(filenames[i]);
	}
	image->loadImage(images[0]);
}
