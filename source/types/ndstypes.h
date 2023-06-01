#ifndef NDSTYPES_H_INCLUDED
#define NDSTYPES_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// Partially the libnds nds types header: https://libnds.devkitpro.org/ndstypes_8h.html
// Also uses martices, vectors, planes, sizes etc. from the PlayStation Vita SDK: https://docs.vitasdk.org/psp2common_2types_8h_source.html

typedef uint8_t byte; // 8 bit unsigned integer
typedef uint16_t uint16; // 16 bit unsigned integer
typedef uint32_t uint32; // 32 bit unsigned integer
typedef uint64_t uint64; // 64 bit unsigned integer
typedef uintmax_t uintMax; // <Maximum> bit unsigned integer (usually 32 or 64 bit)

typedef float float32; // 32 bit signed floating point number
typedef double float64; // 64 bit signed floating point number
typedef volatile float vfloat32; // 32 bit volatile signed floating point number
typedef volatile double vfloat64; // 64 bit volatile signed floating point number

typedef int8_t int8; // 8 bit signed integer
typedef int16_t int16; // 16 bit signed integer
typedef int32_t int32; // 32 bit signed integer
typedef int64_t int64; // 64 bit signed integer
typedef intmax_t intMax; // <Maximum> bit signed integer (usually 32 or 64 bit)

typedef volatile uint8_t vbyte; // 8 bit volatile unsigned integer
typedef volatile uint16_t vuint16; // 16 bit volatile unsigned integer
typedef volatile uint32_t vuint32; // 32 bit volatile unsigned integer
typedef volatile uint64_t vuint64; // 64 bit volatile unsigned integer
typedef volatile uintmax_t vuintMax; // <Maximum> bit volatile unsigned integer (usually 32 or 64 bit)

typedef volatile int8_t vint8; // 8 bit volatile signed integer
typedef volatile int16_t vint16; // 16 bit volatile signed integer
typedef volatile int32_t vint32; // 32 bit volatile signed integer
typedef volatile int64_t vint64; // 64 bit volatile signed integer
typedef volatile intmax_t vintMax; // <Maximum> bit volatile signed integer (usually 32 or 64 bit)

typedef void(*VoidFn); // Void pointer

typedef struct nds_ivector2
{
    int32 x;
    int32 y;
} nds_ivector2;

typedef struct nds_fvector2
{
    float32 x;
    float32 y;
} nds_fvector2;

typedef struct nds_ivector3
{
    int32 x;
    int32 y;
    int32 z;
} nds_ivector3;

typedef struct nds_fvector3
{
    float32 x;
    float32 y;
    float32 z;
} nds_fvector3;

typedef struct nds_ivector4
{
    int32 x;
    int32 y;
    int32 z;
    int32 w;
} nds_ivector4;

typedef struct nds_fvector4
{
    float32 x;
    float32 y;
    float32 z;
    float32 w;
} nds_fvector4;

typedef struct nds_imatrix2
{
    nds_ivector2 x;
    nds_ivector2 y;
} nds_imatrix2;

typedef struct nds_fmatrix2
{
    nds_fvector2 x;
    nds_fvector2 y;
} nds_fmatrix2;

typedef struct nds_imatrix3
{
    nds_ivector3 x;
    nds_ivector3 y;
    nds_ivector3 z;
} nds_imatrix3;

typedef struct nds_fmatrix3
{
    nds_fvector3 x;
    nds_fvector3 y;
    nds_fvector3 z;
} nds_fmatrix3;

typedef struct nds_imatrix4
{
    nds_ivector4 x;
    nds_ivector4 y;
    nds_ivector4 z;
    nds_ivector4 w;
} nds_imatrix4;

typedef struct nds_fmatrix4
{
    nds_fvector4 x;
    nds_fvector4 y;
    nds_fvector4 z;
    nds_fvector4 w;
} nds_fmatrix4;

typedef struct nds_fquaternion
{
    float32 x;
    float32 y;
    float32 z;
    float32 w;
} nds_fquaternion;

typedef struct nds_color
{
    float32 r;
    float32 g;
    float32 b;
    float32 a;
} nds_color;

typedef struct nds_fplane
{
    float32 a;
    float32 b;
    float32 c;
    float32 d;
} nds_fplane;

#define NDS_1KiB   (0x400)
#define NDS_2KiB   (0x800)
#define NDS_4KiB   (0x1000)
#define NDS_8KiB   (0x2000)
#define NDS_16KiB  (0x4000)
#define NDS_32KiB  (0x8000)
#define NDS_64KiB  (0x10000)
#define NDS_128KiB (0x20000)
#define NDS_256KiB (0x40000)
#define NDS_512KiB (0x80000)
#define NDS_1MiB   (0x100000)
#define NDS_2MiB   (0x200000)
#define NDS_4MiB   (0x400000)
#define NDS_8MiB   (0x800000)
#define NDS_16MiB  (0x1000000)
#define NDS_32MiB  (0x2000000)
#define NDS_64MiB  (0x4000000)
#define NDS_128MiB (0x8000000)
#define NDS_256MiB (0x10000000)
#define NDS_512MiB (0x20000000)
#define NDS_1GiB   (0x40000000)

#define HEADER_SIZE 8192

typedef struct {
    unsigned char gameTitle[13];
    unsigned char gameCode[5];
    unsigned char makerCode[3];
    unsigned char unitCode;
    unsigned char encryptionSeed[2];
    unsigned char deviceCapacity;
    unsigned char reserved[9];
    unsigned char romVersion;
    unsigned char internalFlags;
    unsigned int arm9RomOffset;
    unsigned int arm9EntryAddress;
    unsigned int arm9RamAddress;
    unsigned int arm9Size;
    unsigned int arm7RomOffset;
    unsigned int arm7EntryAddress;
    unsigned int arm7RamAddress;
    unsigned int arm7Size;
    unsigned int fntOffset;
    unsigned int fntSize;
    unsigned int fatOffset;
    unsigned int fatSize;
    unsigned int arm9OverlayOffset;
    unsigned int arm9OverlaySize;
    unsigned int arm7OverlayOffset;
    unsigned int arm7OverlaySize;
    unsigned short normalCardControlRegSettings;
    unsigned short secureCardControlRegSettings;
    unsigned int iconTitleOffset;
    unsigned short secureAreaChecksum;
    unsigned short secureAreaDelay;
    unsigned int arm9AutoLoadListRamAddress;
    unsigned int arm7AutoLoadListRamAddress;
    unsigned short secureAreaDisable;
    unsigned short ntrRegionRomSize;
    unsigned short ntrRegionRuntimeSize;
    unsigned int totalRomSize;
    unsigned short romHeaderSize;
    unsigned short reserved2;
    unsigned short logoChecksum;
    unsigned short headerChecksum;
} ndsrom_header;

#endif // NDSTYPES_H_INCLUDED
