/*
 * This class embeds pixels and image's metadata used by other components
*/

#ifndef FEATUREEXTRACTOR_IMAGE_H
#define FEATUREEXTRACTOR_IMAGE_H

class Image {
public:
    Image(const int* pixels, uint rows, uint columns, uint mxGrayLevel)
            :pixels(pixels), rows(rows), columns(columns), maxGrayLevel(mxGrayLevel){};
    //Image(Mat& image);
    const int* getPixels() const;
    uint getRows() const;
    uint getColumns() const;
    uint getMaxGrayLevel() const;
    void printElements() const;
private:
    const int * pixels;
    const uint rows;
    const uint columns;
    const uint maxGrayLevel;
};


#endif //FEATUREEXTRACTOR_IMAGE_H
