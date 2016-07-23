#include "mapaqt.hpp"
#include "conversor.hpp"

namespace SHC
{
    MapaQt::MapaQt(QWidget *parent) :
      QWidget(parent),
      universeSize(81*6),
      mapa(*new SHC::Mapa(81*6,81*6))
    {
        mapa[0][0] = SHC::Celda::full;
        mapa[1][3] = mapa[1][5] = SHC::Celda::full;
        mapa.setPatron(0,0,*new SHC::Patron());
        mapa.setPatron(20,20,*new SHC::Patron("*-*-*-\n-*-*-*\n*-*-*-\n-*-*-*\n*-*-*-\n-*-*-*\n"));
        //mapa[universeSize-1][universeSize-1] = SHC::Celda::full;

        SHC::Conversor conversor;
        conversor.setMapa(mapa);
        conversor.convertir();

    }

    void MapaQt::paintEvent (QPaintEvent *)
    {
        QPainter p(this);
        paintMap(p);
    }

    void MapaQt::paintMap (QPainter &p)
    {
        unsigned int anchomap, altomap;
        anchomap = mapa.numcol();
        altomap = mapa.numfil();
        double cellWidth = (double)width()/anchomap;
        double cellHeight = (double)height()/altomap;
        for(int k=1; k <= anchomap; k++) {
            for(int j=1; j <= altomap; j++) {
                if(mapa[j-1][k-1] == SHC::Celda::full)
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
