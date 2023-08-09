
#ifndef CANVAS_H
#define CANVAS_H

#include <QPixmap>
#include <QTime>
#include <QWidget>
#include <memory>

class System;

enum MouseMode { ModeEdit, ModeMass, ModeSpring };

/* Number of previous mouse state saves */
#define MOUSE_PREV 4

class Canvas : public QWidget {
    Q_OBJECT
public:
    explicit Canvas(QWidget* parent = nullptr);
    MouseMode mouseMode() const;
    void setMouseMode(MouseMode);
    void setSystem(System*);
    System* getSystem();
    void redraw();
    void setAction(bool);

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void updateControls();

private:
    struct Circle {
        int x, y, radius, size;
    };
    struct MouseInfo {
        int x, y;
        unsigned long time;
    };
    void createPixmap(int, int);
    void drawMass(int, int, double);
    void drawMass(QPainter&, const Circle&, bool);
    void drawSpring(const QPoint&, const QPoint&);
    void drawSprings(QPainter&, const QVector<QLine>&, bool);
    void drawSystem();
    void eraseRect(const QRect&);
    void gridSnap(int&, int&);
    void mouseVelocity(int&, int&);
    void drawRubberBand();

    template <typename NumericType> NumericType coordX(NumericType dx) const {
        return dx;
    }

    template <typename NumericType> NumericType coordY(NumericType dy) const {
        return height() - dy;
    }

    MouseMode mode_;
    std::unique_ptr<QPixmap> pixmap_;
    std::unique_ptr<QPixmap> spheres_[5];
    std::unique_ptr<QPixmap> selectedSpheres_[5];
    std::unique_ptr<QPixmap> systemPixmap_;
    System* system_;
    bool mouseDown_;
    QRect rect_;
    bool staticSpring_;
    bool action_;
    int selection_;
    MouseInfo mousePrev_[MOUSE_PREV];
    int mouseOffset_;
    QPoint startPoint_, endPoint_;
    bool shiftKeyDown_;
    Qt::MouseButton mouseButton_;
};

#endif // CANVAS_H
