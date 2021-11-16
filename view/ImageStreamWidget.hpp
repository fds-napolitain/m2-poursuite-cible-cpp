//
// Created by Maxime Boucher on 16/11/2021.
//

#ifndef QTHDR_IMAGESTREAMWIDGET_HPP
#define QTHDR_IMAGESTREAMWIDGET_HPP


#include "../model/Image.hpp"
#include "ImageWidget.hpp"

class ImageStreamWidget : public QWidget {

private:
public:
	std::vector<Image> images;
	ImageWidget* image;
	ImageStreamWidget();
	explicit ImageStreamWidget(QWidget* parent);
	void loadImages(const QStringList& filenames);
};


#endif //QTHDR_IMAGESTREAMWIDGET_HPP
