
#ifndef TetrisPiece_H
#define TetrisPiece_H

enum TetrisShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

//! [0]
class TetrisPiece
{
public:
    TetrisPiece() { setShape(NoShape); }

    void setRandomShape();
    void setShape(TetrisShape shape);

    TetrisShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    TetrisPiece rotatedLeft() const;
    TetrisPiece rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    TetrisShape pieceShape;
    int coords[4][2];
};
//! [0]

#endif
#ifndef TETRISPIECE_H
#define TETRISPIECE_H



#endif // TETRISPIECE_H
