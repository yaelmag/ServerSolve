//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_POINT_H
#define PROJECT2_POINT_H
class Point {
    int row;
    int col;
public:
    Point(int row, int col) {
        this->row = row;
        this->col = col;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }
};

#endif //PROJECT2_POINT_H
