#pragma once

#include <HGELFFileFormat.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include <utility>

class HGELFFile {
public:
    using HGELFFileRef = std::unique_ptr<HGELFFile>;

    static HGELFBitWidth getSystemBitWidth();
    static HGELFEndianness getSystemEndianness();
    static HGELFABI getSystemABI();
    static HGELFMachine getSystemArchitecture();

    static HGELFFileRef makeFromData(void* data, std::size_t dataLength);
    static const HGELFFileRef makeFromConstData(const void* data, std::size_t dataLength);
    static HGELFFileRef makeFromScratch(HGELFBitWidth bitWidth, HGELFEndianness endianness, HGELFType type, HGELFABI abi, HGELFMachine architecture);

    virtual std::uint32_t getMagicNumber() const = 0;
    virtual HGELFBitWidth getBitWidth() const = 0;
    virtual HGELFEndianness getEndianness() const = 0;
    virtual HGELFABI getABI() const = 0;
    virtual HGELFMachine getArchitecture() const = 0;
    
    virtual HGELFType getType() const = 0;
    virtual HGELFFile &setType(HGELFType type) = 0;
    virtual std::uint8_t getABIVersion() const = 0;
    virtual HGELFFile &setABIVersion(std::uint8_t abiVersion) = 0;
    virtual std::uint32_t getFlags() const = 0;
    virtual HGELFFile &setFlags(std::uint32_t flags) = 0;
    virtual std::uint32_t getFileHeaderSize() const = 0;
    virtual HGELFFile &setFileHeaderSize(std::uint32_t fhs) = 0;
    virtual std::uint16_t getSizeOfProgramTableEntry() const = 0;
    virtual HGELFFile &setSizeOfProgramTableEntry(std::uint16_t szpte) = 0;
    virtual std::uint16_t getNumberOfProgramTableEntries() const = 0;
    virtual HGELFFile &setNumberOfProgramTableEntries(std::uint16_t npte) = 0;
    virtual std::uint16_t getSizeOfSectionTableEntry() const = 0;
    virtual HGELFFile &setSizeOfSectionTableEntry(std::uint16_t szste) = 0;
    virtual std::uint16_t getNumberOfSectionTableEntries() const = 0;
    virtual HGELFFile &setNumberOfSectionTableEntries(std::uint16_t nste) = 0;
    virtual std::uint16_t getSectionNameSHTIndex() const = 0;
    virtual HGELFFile &setSectionNameSHTIndex(std::uint16_t nshtndx) = 0;

private:
    HGELFFile();
    ~HGELFFile();
};

class HGELFFile64 : public HGELFFile {
private:
    friend HGELFFile;

    HGELFFile64(std::vector<std::uint8_t> &&data) 
        : mData(std::move(data))
    {
    }

    std::vector<std::uint8_t> mData;
};

class HGELFFile32 : public HGELFFile {
private:
    friend HGELFFile;

    HGELFFile32(std::vector<std::uint8_t> &&data)
        : mData(std::move(data))
    {
    }

    std::vector<std::uint8_t> mData;
};

