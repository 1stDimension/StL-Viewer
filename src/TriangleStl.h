#ifndef STL_VIEWER_TRIANGLESTL_H
#define STL_VIEWER_TRIANGLESTL_H


class TriangleStl {
private:
    //each contains 3 values
    float* direction;
    float* vertexOne;
    float* vertexTwo;
    float* vertexTree;
public:
    //each must contain 3 values
    TriangleStl(float* dir, float* one, float* Two, float* tree);
    ~TriangleStl();

    //TODO Consider returning copy of array to separate
    float *getDirection() const;

    float *getVertexOne() const;

    float *getVertexTwo() const;

    float *getVertexTree() const;
};


#endif //STL_VIEWER_TRIANGLESTL_H
