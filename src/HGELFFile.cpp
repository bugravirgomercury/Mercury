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
    char buffer[4] = { 0x00, 0x00, 0x00, 0x01 };
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
    if (bitWidth == HGELFBitWidth::B32) {
        HGELFHeader32 *h = (HGELFHeader32*)d.data();
        h->BitWidth = HGELFBitWidth::B32;
        h->Endianness = endianness;
        h->Type = type;
        h->OSABI = abi;
        h->MachineISA = architecture;
    }
}

#endif /* HGELFFILE_H */
