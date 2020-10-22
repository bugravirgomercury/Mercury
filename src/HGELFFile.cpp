#include <HGELFFile.hpp>

class HGELFFileH::HGELFFileB {
};

HGELFFileH::HGELFFileH()
    : mBody { new HGELFFileB() }
{
}

HGELFFileH::~HGELFFileH()
{
    if (mBody != nullptr) {
        delete mBody;
        mBody = nullptr;
    }
}