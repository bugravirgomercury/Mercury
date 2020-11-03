///
/// Created by Buğra Kadirhan.
///

#define BOOST_TEST_MODULE HGELFFileFormatTests
#include <boost/test/unit_test.hpp>

#include <HGELFFileFormat.hpp>

#define OFFSET(o, m) ((uintptr_t)(&m) - (uintptr_t)(&o))

BOOST_AUTO_TEST_CASE(HGELFFileHeader64CheckOffsets)
{
    HGELFHeader64 h;
    BOOST_CHECK_EQUAL(OFFSET(h, h.MagicNumber), 0x00);
    BOOST_CHECK_EQUAL(OFFSET(h, h.BitWidth), 0x04);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Endianness), 0x05);
    BOOST_CHECK_EQUAL(OFFSET(h, h.VersionID), 0x06);
    BOOST_CHECK_EQUAL(OFFSET(h, h.OSABI), 0x07);
    BOOST_CHECK_EQUAL(OFFSET(h, h.ABIVersion), 0x08);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Padding), 0x09);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Type), 0x10);
    BOOST_CHECK_EQUAL(OFFSET(h, h.MachineISA), 0x12);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Version), 0x14);
    BOOST_CHECK_EQUAL(OFFSET(h, h.EntryPoint), 0x18);
    BOOST_CHECK_EQUAL(OFFSET(h, h.ProgramHeaderTableOffset), 0x20);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SectionHeaderTableOffset), 0x28);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Flags), 0x30);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfThisHeader), 0x34);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfProgramTableEntry), 0x36);
    BOOST_CHECK_EQUAL(OFFSET(h, h.NumberOfProgramTableEntries), 0x38);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfSectionTableEntry), 0x3A);
    BOOST_CHECK_EQUAL(OFFSET(h, h.NumberOfSectionTableEntries), 0x3C);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SectionNameSHTIndex), 0x3E);
    BOOST_CHECK_EQUAL(sizeof(h), 0x40);
}

BOOST_AUTO_TEST_CASE(HGELFFileHeader32CheckOffsets)
{
    HGELFHeader32 h;
    BOOST_CHECK_EQUAL(OFFSET(h, h.MagicNumber), 0x00);
    BOOST_CHECK_EQUAL(OFFSET(h, h.BitWidth), 0x04);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Endianness), 0x05);
    BOOST_CHECK_EQUAL(OFFSET(h, h.VersionID), 0x06);
    BOOST_CHECK_EQUAL(OFFSET(h, h.OSABI), 0x07);
    BOOST_CHECK_EQUAL(OFFSET(h, h.ABIVersion), 0x08);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Padding), 0x09);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Type), 0x10);
    BOOST_CHECK_EQUAL(OFFSET(h, h.MachineISA), 0x12);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Version), 0x14);
    BOOST_CHECK_EQUAL(OFFSET(h, h.EntryPoint), 0x18);
    BOOST_CHECK_EQUAL(OFFSET(h, h.ProgramHeaderTableOffset), 0x1C);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SectionHeaderTableOffset), 0x20);
    BOOST_CHECK_EQUAL(OFFSET(h, h.Flags), 0x24);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfThisHeader), 0x28);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfProgramTableEntry), 0x2A);
    BOOST_CHECK_EQUAL(OFFSET(h, h.NumberOfProgramTableEntries), 0x2C);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SizeOfSectionTableEntry), 0x2E);
    BOOST_CHECK_EQUAL(OFFSET(h, h.NumberOfSectionTableEntries), 0x30);
    BOOST_CHECK_EQUAL(OFFSET(h, h.SectionNameSHTIndex), 0x32);
    BOOST_CHECK_EQUAL(sizeof(h), 0x34);
}