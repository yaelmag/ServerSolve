//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_POINT_H
#define PROJECT2_POINT_H
class Point {
    int row;
    int col;
public:
    /**
     * constructor
     * @param row - the number of the row
     * @param col - the number of the col
     */
    Point(int row, int col) {
        this->row = row;
        this->col = col;
    }
    /**
     * get the number of the row
     * @return the number of the row
     */
    int getRow() const {
        return row;
    }
    /**
     * get the number of the col
     * @return the number of the col
     */
    int getCol() const {
        return col;
    }

    /**
     * override operator <
     * @param other - a point
     * @return
     */
    bool operator<(const Point other) const {
        if (this->row < other.getRow()) {
            return true;
        }
        if (this->row > other.getRow()) {
            return false;
        }
        if (this->col < other.getCol()) {
            return true;
        }
        if (this->col > other.getCol()) {
            return false;
        }
        return false;
    }
};

#endif //PROJECT2_POINT_H
