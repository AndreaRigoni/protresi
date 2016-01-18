#ifndef IMAGESOURCE_H
#define IMAGESOURCE_H


class ImageSource
{

    static ImageSource *loadDICOM(const char *path);
public:
    ImageSource();
    ~ImageSource();
    friend class ImageSourceData;
    class ImageSourceData *d;
};

#endif // IMAGESOURCE_H
