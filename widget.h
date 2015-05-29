#ifndef WIDGET_H
#define WIDGET_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif
// OpenCV Header
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/contrib/contrib.hpp>
//End of OpenCV

using namespace std;
using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
protected:
    void changeEvent(QEvent *e);
    
public slots:
    void frameAndGuiUpdate();

private:
    Ui::Widget *ui;
    //Camera capture.
    VideoCapture camera;
    Mat frame;
    Mat frameProcessed;
    //All Face Detection.
    Mat frame_gray;
    vector<Rect> faces;
    CascadeClassifier face_cascade;
    //Qt Image and time.
    QImage srcimg;
    QTimer *timer;
};

#endif // WIDGET_H
