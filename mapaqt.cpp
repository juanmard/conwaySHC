#include "mapaqt.hpp"

namespace SHC
{
    MapaQt::MapaQt(QWidget *parent) :
      QWidget(parent),
      universeSize(10),
      mapa(*new SHC::Mapa(10,10))
    {
        //timer->setInterval(300);
        //m_masterColor = "#000";
        //universe = new bool[(universeSize + 2) * (universeSize + 2)];
        //next = new bool[(universeSize + 2) * (universeSize + 2)];
        //connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
        //memset(universe, false, sizeof(bool)*(universeSize + 2) * (universeSize + 2));
        //memset(next, false, sizeof(bool)*(universeSize + 2) * (universeSize + 2));
        mapa[0][0] = SHC::Celda::full;
        mapa[9][9] = SHC::Celda::full;
        mapa[1][3] = mapa[1][5] = SHC::Celda::full;
    }

    void MapaQt::paintEvent (QPaintEvent *)
    {
        QPainter p(this);
        paintMap(p);
    }

    void MapaQt::paintMap (QPainter &p)
    {
        double cellWidth = (double)width()/universeSize;
        double cellHeight = (double)height()/universeSize;
        for(int k=1; k <= universeSize; k++) {
            for(int j=1; j <= universeSize; j++) {
                if((mapa.operator[](k-1)).operator[](j-1) == SHC::Celda::full)
                { // if there is any sense to paint it
                    qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
                    qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
                    QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                    p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color
                }
            }
        }
    }

    void MapaQt::startGame(const int &number){}

    void MapaQt::stopGame() {}

    void MapaQt::clear() {}

    int MapaQt::cellNumber() {return 0;}

    void MapaQt::setCellNumber(const int &s){}

    void MapaQt::resetUniverse(){}

    QString MapaQt::dump(){return *new QString();}

    void MapaQt::setDump(const QString &data){}

    int MapaQt::interval(){return 0;}

    void MapaQt::setInterval(int msec){}

    bool MapaQt::isAlive(int k, int j){return true;}

    void MapaQt::newGeneration(){}

    void MapaQt::mousePressEvent(QMouseEvent *e){}

    void MapaQt::mouseMoveEvent(QMouseEvent *e){}

    void MapaQt::paintGrid(QPainter &p){}

    void MapaQt::paintUniverse(QPainter &p){}

    QColor MapaQt::masterColor(){return QColor();}

    void MapaQt::setMasterColor(const QColor &color){}
}