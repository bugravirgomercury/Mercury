#include <HGELFFile.hpp>
#include <cstdint>
#include <vector>

HGELFBitWidth HGELFFile::getSystemBitWidth() 
{
#ifdef __LP64__
    return HGELFBitWidth::B64;
#else
    return HGELFBitWidth::B32;
#endif
}

HGELFEndianness HGELFFile::getSystemEndianness()
{
    static const char buffer[4] = { 0x00, 0x00, 0x00, 0x01 };
    std::uint32_t number = *(std::uint32_t*)buffer;
    if (number == 0x00000001)
        return HGELFEndianness::Big;
    else if (number == 0x01000000)
        return HGELFEndianness::Little;
    else
        return HGELFEndianness::None; 
}

HGELFABI HGELFFile::getSystemABI()
{
    return HGELFABI::SystemV;
}

HGELFMachine HGELFFile::getSystemArchitecture()
{
    return HGELFMachine::AMD64;
}

HGELFFile::HGELFFileRef 
HGELFFile::makeFromScratch(
    HGELFBitWidth   bitWidth,
    HGELFEndianness endianness,
    HGELFType       type,
    HGELFABI        abi,
    HGELFMachine    architecture)
{
    std::vector<std::uint8_t> d;
    d.reserve(0x4000);

    HGELFHeaderCommonHead *h = (HGELFHeaderCommonHead *)d.data();
    h->MagicNumber = *(std::uint32_t*)("\x7FELF");
    h->BitWidth = bitWidth;
    h->Endianness = endianness;
    h->Type = type;
    h->OSABI = abi;
    h->MachineISA = architecture;

    switch (bitWidth) {
        case HGELFBitWidth::B32:
            return std::make_unique<HGELFFile32>(d);
        case HGELFBitWidth::B64:
            return std::make_unique<HGELFFile64>(d);
        default:
            return nullptr;
    }
}

std::uint32_t
HGELFFile64::getMagicNumber() const
{
    return ((HGELFHeader64*)mData.data())->MagicNumber;
}

std::uint32_t
HGELFFile32::getMagicNumber() const
{
    return ((HGELFHeader32*)mData.data())->MagicNumber;
}

HGELFBitWidth
HGELFFile64::getBitWidth() const
{
    return ((HGELFHeader64*)mData.data())->BitWidth;
}

HGELFBitWidth
HGELFFile32::getBitWidth() const
{
    return ((HGELFHeader32*)mData.data())->BitWidth;
}

HGELFEndianness
HGELFFile64::getEndianness() const
{
    return ((HGELFHeader64*)mData.data())->Endianness;
}

HGELFEndianness
HGELFFile32::getEndianness() const
{
    return ((HGELFHeader32*)mData.data())->Endianness;
}

#endif /* HGELFFILE_H */
