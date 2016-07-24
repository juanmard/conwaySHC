#ifndef MAPAQT_HPP
#define MAPAQT_HPP

#include <QWidget>
#include <QColor>
#include <QTimer>
#include <QPainter>
#include "mapa.hpp"

namespace SHC
{
    class MapaQt : public QWidget
    {
        Q_OBJECT
    public:
        explicit MapaQt(QWidget *parent = 0);
        //~GameWidget();

    protected:
        void paintEvent(QPaintEvent *);
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);

    signals:
        ////when one of the cell has been changed,emit this signal to lock the universeSize
        void environmentChanged(bool ok);
        ////when game is over or clear is called,emit it to unlock the universeSize
        void gameEnds(bool ok);

    public slots:
        void startGame(const int &number = -1); // start
        void stopGame(); // finish
        void clear(); // clear
        int cellNumber(); // number of the cells in one row
        void setCellNumber(const int &s); // set number of the cells in one row

        int interval(); // interval between generations
        void setInterval(int msec); // set interval between generations

        QColor masterColor(); // color of the cells
        void setMasterColor(const QColor &color); // set color of the cells

        QString dump(); // dump of current universe
        void setDump(const QString &data); // set current universe from it's dump

    private slots:
        void paintMap (QPainter &p);
        void paintGrid(QPainter &p);
        void paintUniverse(QPainter &p);
        void newGeneration();

    private:
        QColor m_masterColor;
        int universeSize;
        QTimer* timer;
        int generations;
        SHC::Mapa &mapa;

        bool isAlive(int k, int j); // return true if universe[k][j] accept rules
        void resetUniverse();// reset the size of universe
    };
}

#endif // MAPAQT_HPP
