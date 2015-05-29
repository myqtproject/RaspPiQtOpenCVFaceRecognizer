#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Open the camera and check it is connected or not.
    camera.open(0);
    if(camera.isOpened() == false)
    {
        ui->sysMessage->append("Error: The webcam is not connected !");
        return;
    }

    //--New the time and start !--//
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frameAndGuiUpdate()));
    timer->start(30);

}

void Widget::frameAndGuiUpdate()
{
    //Read the camera.
    camera.read(frame);
    if(frame.empty() == true)
        return;

    inRange(frame, Scalar(0, 0, 175), Scalar(100, 100, 256), frameProcessed);
    GaussianBlur(frameProcessed, frameProcessed, Size(10, 10), 1.5);
    cvtColor(frame, frameProcessed, CV_BGR2RGB);

    QImage srcimg = QImage((const uchar*)frame.data, frame.rows, frame.cols, frame.step, QImage::Format_RGB888).rgbSwapped();
    ui->frameView->setPixmap(QPixmap::fromImage(srcimg));
}

Widget::~Widget()
{
    camera.release();
    frame.release();
    timer->stop();
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

