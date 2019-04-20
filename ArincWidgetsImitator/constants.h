#ifndef CONSTANTSANDERRORS
#define CONSTANTSANDERRORS

const int ACLK = 4;

enum class  SpiModes
{
    notCpohNotCpol,    //Mode0
    cpha          ,    //Mode1
    cpol          ,    //Mode2
    cphaAndCpol   ,    //Mode3
};

enum class Registers
{
    empty                      = 0x00,
    wrMasterReset              = 0x04,
    wrSoftReset                = 0x44,

    wrLabelToRec1Lmemory       = 0x14,
    wrLabelToRec2Lmemory       = 0x28,
    wrSetRec1LmemoryBitsTo1    = 0x48,
    wrSetRec2LmemoryBitsTo1    = 0x4C,
    rdRec1Lmemory              = 0x98,
    rdRec2Lmemory              = 0xB8,

    wrMsgToTransmitFifo        = 0x0C,
    wrTransmitCurrentConFifo   = 0x40,

    rdMsgFromRec1Fifo          = 0xA0,
    rdMsgFromRec2Fifo          = 0xC0,


    wrRec1PriorityMatchReg     = 0x18,
    rdRec1PriorityMatchReg     = 0x9C,
    wrRec2PriorityMatchReg     = 0x2C,
    rdRec2PriorityMatchReg     = 0xBC,
    rdRec1PriorityLabel1       = 0xA4,
    rdRec1PriorityLabel2       = 0xA8,
    rdRec1PriorityLabel3       = 0xAC,
    rdRec2PriorityLabel1       = 0xC4,
    rdRec2PriorityLabel2       = 0xC8,
    rdRec2PriorityLabel3       = 0xCC,

    wrRec1Control              = 0x10,
    rdRec1Control              = 0x94,
    wrRec2Control              = 0x24,
    rdRec2Control              = 0xB4,
    wrTransmitControl          = 0x08,
    rdTransmitControl          = 0x84,
    rdRec1Stat                 = 0x90,
    rdRec2Stat                 = 0xB0,
    rdTransmitStat             = 0x80,
    wrAclk                     = 0x38,
    rdAclk                     = 0xD4,
    wrInterrupt                = 0x34,
    rdInterrupt                = 0xD0,
    full                       = 0xFF,

};

enum class ReceiverControlFlags
{
    rate =   1, /* If RATE is “0”, ARINC 429 high-speed data rate is selected. RATE = “1” selects low-speed
ARINC 429 data rate (high-speed / 8).*/
    plon  =  2, /* Priority-Label Register enable. If PLON = “1” the three
Priority-Label Registers are enabled and received ARINC 429 messages with labels
that match one of the three pre-programmed values will be capured and stored in
the corresponding Prioty-Label Mail Boxes. If PLON = “0” the Priority-Label
matching feature is turned off and no words are placed in the mail boxes.*/
    labrec = 4, /* When “0”, all received messages are stored. If this bit
is set, incoming ARINC message label filtering is enabled. Only messages
whose corresponding label filter table entry is set to a “1”
will be stored in the Receive FIFO.*/
    parity = 8, /* Received word parity checking is enabled when this bit is
set. If “0”, all 32 bits of the received ARINC 429 word are
stored without parity checking.*/
    sdon =   16, /* If this bit is set, bits 9 and 10 of the received
ARINC 429 message must match SD9 and SD10 */
    sd10 =  32, /* If set  then ARINC 429 message
bit 10 must match this bit for the message to be accepted. */
    sd9 =   64, /* If set  then ARINC 429 message
bit 9 must match this bit for the message to be accepted. */
    rFlip = 128  /* Reverses the bit order of the first 8 bits
of each ARINC 429 message received.*/
};

enum class TransmitControlFlags
{
    rate     =  1,   /* Speed rate High or low */
    notUsed =   2,
    tParity  =  4,   /* If TPARITY = “0”, no parity bit is inserted and
the 32nd transmitted bit is data. When TPARITY is a “1” a parity bit
is substituted for bit 32 according to the ODDEVEN bit value. */
    oddEven  =  8,   /* If the TPARITY bit is set, the transmitter inserts
an odd parity bit if ODDEVEN = “0”, or an even if ODDEVEN = “1”. */
    selfTest =  16,   /* looping-back the transmitter outputs to both
receiver inputs for self-test purposes */
    tMode    =  32,   /* If TMODE is “0”, data in the transmit FIFO is sent to
the ARINC 429 bus only upon receipt of an SPI op-code 0x40, transmit enable,
command. If TMODE is a “1”, data is sent as soon as it is available.*/
    tFlip    =  64,  /* Setting this bit reverses the bit order of the first
8 bits of each ARINC 429 message transmitted.See figure 1 for details.*/
    hiz      = 128   /* Puts the on-chip line driver outputs to a high state.*/
};

/*
 * This table of 8bit address Arinc messages.If need to add new
 * data u must add new label to this class.This class used by functions
 * that work with LookUpTable, for filter not needed messages
*/
enum class ArincCodeMessage
{
    lat             = 0310,  // Latitude
    lng             = 0311,  //Longitude
    distanceToDest  = 005,   //Miles to destination
    timeToDest      = 006,   //Time to destination
    speed           = 0312,  //Current speed
    grinvichTime    = 0150,  //Time by grinvich
    temperature     = 0213,  //Temperature
    date            = 0260,  //Date
    alt             = 0203,  //Absolute high
};

enum class Config
{
    spiFreq           = 12000000,
    bitsPerWord       = 0,
    lsb               = 0,
};

//Length in bytes
enum class WordLength
{
    emptyWord         = 0,
    regBit1           = 1,
    labelMatchReg3    = 3,
    arincWord4        = 4,
    lableTable32      = 32,
};

enum class Errors
{
    noErrors,
    failOpenFile,
    failSoftReset,
    failMasterReset,
    failOpenDevice,
    failSetMode,
    failSetAclk,
    failSetBitsPerWord,
    failSetSpiFreq,
    failSetLsb,
    failSetLookUp,
    failSetRec1ConBit,
    failSetRec2ConBit,
    failSetTransmitConBit,
    wrongLableTableSize,
    wrongAclk,
    wrongSpiFreq,
    wrongBitsPerWord,
};

enum class ArincDataLength
{
    latLength           = 20,
    longLength          = 20,
    altLength           = 17,
    distanceLength      = 18,
    timeLength          = 12,
    speedLength         = 15,
    grinvichLength      = 17,
    tempLength          = 11,
    dateLength          = 19,
};

// Enum does not support double values
class GeoParse
{
public:
    GeoParse();
    const static  double latPrice;
    const static  double lngPrice;
    const static  double altPrice ;
    const static  double distancePrice;
    const static  double timePrice;
    const static  double speedPrice;
    const static  double tempPrice ;
};

#endif // CONSTANTSANDERRORS



