//
// Created by Maxime Boucher on 30/10/2021.
//


#include "Image.hpp"


Image::Image() = default;

/**
 * Initialise une image avec OpenCV.
 * @param filename
 * @param isHDR
 */
Image::Image(const QString& filename) {
	loadImage(filename);
	QStringList tmp = filename.split('/');
}

/**
 * Destructeur
 */
Image::~Image() = default;

/**
 * Charge une image avec OpenCV
 * @param filename chemin d'accès à l'image
 */
void Image::loadImage(const QString& filename) {
	image = cv::imread(filename.toStdString());
}

/**
 * Retourne une image au format QImage (à utiliser dans les widgets UI Qt).
 * @return
 */
QImage Image::getQImage() const {
	return QImage((uchar*) image.data, image.cols, image.rows, QImage::Format_RGB888).rgbSwapped();
}

/**
 * Retourne une image au format QImage à partir du paramètre image
 * @param image matrice OpenCV
 * @return
 */
QImage Image::getQImage(cv::Mat image) {
	return QImage((uchar*) image.data, image.cols, image.rows, QImage::Format_RGB888).rgbSwapped();
}
