#ifndef QTHDR_IMAGE_HPP
#define QTHDR_IMAGE_HPP

#include <QImage>
#include <opencv2/opencv.hpp>

/**
 * Classe qui fait le pont entre une cv::Mat opencv (pour le traitement d'image) et QImage (pour l'interface graphique).
 */
class Image {

private:
public:
	cv::Mat image;
	Image();
	explicit Image(const QString& filename);
	~Image();
	void loadImage(const QString& filename);
	[[nodiscard]] QImage getQImage() const;
	// -- méthodes sur une image
};


#endif //QTHDR_IMAGE_HPP
