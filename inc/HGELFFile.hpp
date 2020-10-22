#pragma once

#include <HGELFFileFormat.hpp>

class HGELFFileH {
public:
    HGELFFileH();
    ~HGELFFileH();

private:
    class HGELFFileB;
    HGELFFileB* mBody;
};