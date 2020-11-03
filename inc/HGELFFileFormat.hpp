///
/// Created by Buğra Kadirhan.
///

#pragma once
#include <cstdint>

enum class HGELFBitWidth : std::uint8_t {
    B32 = 1,
    B64 = 2
};

enum class HGELFEndianness : std::uint8_t {
    Little = 1,
    Big = 2,
    None = 0
};

enum class HGELFType : std::uint16_t {
    None = 0x00,
    Rel = 0x01,
    Exec = 0x02,
    Dyn = 0x03,
    Core = 0x04,
    OSLow = 0xFE00,
    OSHigh = 0xFEFF,
    ProcLow = 0xFF00,
    ProcHigh = 0xFFFF
};

enum class HGELFABI : std::uint8_t {
    SystemV = 0x00,
    HPUX = 0x01,
    NetBSD = 0x02,
    Linux = 0x03,
    GNUHurd = 0x04,
    Solaris = 0x06,
    AIX = 0x07,
    IRIX = 0x08,
    FreeBSD = 0x09,
    Tru64 = 0x0A,
    NovellModesto = 0x0B,
    OpenBSD = 0x0C,
    OpenVMS = 0x0D,
    NonStopKernel = 0x0E,
    AROS = 0x0F,
    FenixOS = 0x10,
    CloudABI = 0x11,
    StratusTechnologiesOpenVOS = 0x12
};

enum class HGELFMachine : std::uint16_t {
    Unspecified = 0x00,
    ATNTWE32100 = 0x01,
    SPARC = 0x02,
    x86 = 0x03,
    M68K = 0x04,
    M88K = 0x05,
    IntelMCU = 0x06,
    Intel80860 = 0x07,
    MIPS = 0x08,
    MIPSRS3000LittleEndian = 0x0A,
    PARISC = 0x0E,
    Intel80960 = 0x13,
    PowerPC = 0x14,
    PowerPC64 = 0x15,
    S390 = 0x16,
    S390x = 0x16,
    ARM = 0x28,
    SuperH = 0x2A,
    IA64 = 0x32,
    AMD64 = 0x3E,
    TMS320C6000 = 0x8C,
    ARM64 = 0xB7,
    RISCV = 0xF3,
    WDC65C816 = 0x101
};

struct HGELFHeaderCommonFooter {
    std::uint32_t Flags; // Depends on target architecture.
    std::uint16_t SizeOfThisHeader; // Not the footer's size!
    std::uint16_t SizeOfProgramTableEntry;
    std::uint16_t NumberOfProgramTableEntries;
    std::uint16_t SizeOfSectionTableEntry;
    std::uint16_t NumberOfSectionTableEntries;
    std::uint16_t SectionNameSHTIndex;
};

struct HGELFHeaderCommonHead {
    std::uint32_t MagicNumber;
    std::uint8_t BitWidth; // 1 = 32-bit, 2 = 64-bit.
    std::uint8_t Endianness; // 1 = big, 2 = little-endian.
    std::uint8_t VersionID; // Currently 1.
    std::uint8_t OSABI; // Application Binary Interface.
    std::uint8_t ABIVersion;
    std::uint8_t Padding[7];
    std::uint16_t Type;
    std::uint16_t MachineISA; // Instruction Set Architecture
    std::uint32_t Version; // Currently 1.
};

struct HGELFHeader32BitsSpecific {
    std::uint32_t EntryPoint;
    std::uint32_t ProgramHeaderTableOffset;
    std::uint32_t SectionHeaderTableOffset;
};

struct HGELFHeader64BitsSpecific {
    std::uint64_t EntryPoint;
    std::uint64_t ProgramHeaderTableOffset;
    std::uint64_t SectionHeaderTableOffset;
};

struct HGELFHeader32 : public HGELFHeaderCommonHead,
                       public HGELFHeader32BitsSpecific,
                       public HGELFHeaderCommonFooter {
};

struct HGELFHeader64 : public HGELFHeaderCommonHead,
                       public HGELFHeader64BitsSpecific,
                       public HGELFHeaderCommonFooter {
};
