#include <cstring>
#include "ContentSpliter.h"

ContentSpliter::ContentSpliter(std::vector<TriangleStl *> *vector){
    //TODO Copy content to float pointer
    const char triangleSize = 12;
    this->data = new float [vector->size() * triangleSize];
    this->size = vector->size() * triangleSize;
    { uint32_t i = 0;
        for (auto &var : *vector) {
            memcpy(this->data + i, var->getAll(), triangleSize * sizeof(*(this->data)) );
            i += triangleSize;
        }
    }
}
